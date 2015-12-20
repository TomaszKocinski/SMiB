#include "SMO.h"
#include <fstream>

SMO::SMO()
{
}

SMO::SMO(int laValue, int miValue, int tValue, int nValue, int lValue)
{
	La = laValue;
	Mi = miValue;

	if (tValue < 1)
		throw exception("T value too small");
	else if (tValue>23)
		throw exception("T value too large");
	else
		T = tValue;

	if (nValue < 1)
		throw exception("N value too small");
	else if (nValue > 6)
		throw exception("N value is too large");
	else
		N = nValue;

	queue = new Queue(lValue);

	event_handler = new EventHandler();

	for (int i = 0; i < N; i++)
	{
		channels.push_back(Channel());
	}

	event_handler->push(getT0Time(), 0);

	report = new Report(T);
}

SMO::~SMO()
{
	delete(event_handler);
	delete(queue);
	delete(report);
}

bool SMO::event()
{
	try
	{
		currentT = event_handler->pop();
	}
	catch (exception &e)
	{
		return false;
	}

	report->addTime(currentT);
	if (currentT.second == 0)
	{
		double tempTime = currentT.first + getT0Time();
		if (tempTime < T)
			event_handler->push(tempTime, 0);

		if (queue->isFull())
			report->addTime(currentT, true);
		else
			(*queue)++;
	}
	else
	{
		channels[currentT.second - 1].setFree();
	}

	if (queue->getl() != 0)
	{

		for (int i = 0; i < N; i++)
		{
			if (!channels[i].isBusy())
			{
				(*queue)--;
				channels[i].setBusy();
				event_handler->push(currentT.first + getTnTime(), i + 1);
				break;
			}
		}
	}

	report->addQueueValue(queue->getl());
	vector<int> tempChannels;
	for (int i = 0; i < N; i++)
		if (channels[i].isBusy())
			tempChannels.push_back(1);
		else
			tempChannels.push_back(0);
	report->addChannelsValues(tempChannels);

	return true;
}

double SMO::generate() const
{
	random_device rd;
	mt19937 generator(rd());
	uniform_real_distribution<double> distribution(0.0, 1.0);
	return distribution(generator);
}

double SMO::getT0Time() const
{
	return (1.0 / La);
}

double SMO::getTnTime() const
{
	return (1.0 / Mi);
}

void SMO::createReport(ostream &dataStream, ostream &callsStream, ostream &finishedStream, ostream &dismissedStream) const
{
	if(&dataStream == &std::cout)
		report->saveData(dataStream);
	else
	{
		report->saveData(dataStream);
		report->saveCallsPerTimeUnit(callsStream, finishedStream);
		report->saveDismissedPerTimeUnit(dismissedStream);
	}
}

pair<double, int> SMO::getCurrentT() const
{
	return currentT;
}

int SMO::getT() const
{
	return T;
}

int SMO::getN() const
{
	return N;
}

int SMO::getL() const
{
	return queue->getL();
}