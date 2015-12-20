#include"Report.h"
#include<iomanip>

Report::Report(int tValue)
{
	T = tValue;
}

Report::~Report()
{
	queue.clear();
	channels.clear();
	times.clear();
}

void Report::addTime(std::pair<double, int> timeValue, bool dismissed)
{
	if (dismissed)
		dismissedTimes.insert((timeValue));
	else
		times.insert((timeValue));
}

void Report::addQueueValue(int qValue)
{
	queue.push_back(qValue);
}

void Report::addChannelsValues(std::vector<int> cValues)
{
	channels.push_back(cValues);
}

void Report::saveData(std::ostream &stream) const
{
	QueueVector::const_iterator queue_it = queue.begin();
	ChannelsVector::const_iterator channels_it = channels.begin();
	TimesVector::const_iterator times_it = times.begin();

	for (; times_it != times.end(); times_it++, queue_it++, channels_it++)
	{
		stream << std::setw(9) << times_it->first << " " << times_it->second;
		stream << "\t" << *queue_it;
		for (std::vector<int>::const_iterator it = channels_it->begin(); it != channels_it->end(); it++)
			stream << "\t" << *it;
		stream << std::endl;
	}
}

void Report::saveDismissed(std::ostream &stream) const
{
	for (TimesVector::const_iterator it = dismissedTimes.begin(); it != dismissedTimes.end(); it++)
	{
		stream << std::setw(9) << it->first << " " << it->second;
		stream << std::endl;
	}
}

void Report::saveDismissedPerTimeUnit(std::ostream &stream) const
{
	PerTimeUnitVector dismissedPerTimeUnit;
	for (int i = 0; i <= T; i++)
		dismissedPerTimeUnit.push_back(0);

	for (TimesVector::const_iterator it = dismissedTimes.begin(); it != dismissedTimes.end(); it++)
	{
		if(floor(it->first)>=dismissedPerTimeUnit.size())
			dismissedPerTimeUnit.push_back(1);
		else
			dismissedPerTimeUnit[floor(it->first)]++;
	}

	for (PerTimeUnitVector::const_iterator it = dismissedPerTimeUnit.begin(); it != dismissedPerTimeUnit.end(); it++)
	{
		stream << std::setw(9) << *it;
		stream << std::endl;
	}
}

void Report::saveCallsPerTimeUnit(std::ostream &callsStream, std::ostream &finishedStream) const
{
	PerTimeUnitVector callsPerTimeUnit, finishedPerTimeUnit;
	for (int i = 0; i <= T; i++)
	{
		callsPerTimeUnit.push_back(0);
		finishedPerTimeUnit.push_back(0);
	}

	for (TimesVector::const_iterator it = times.begin(); it != times.end(); it++)
	{
		if(it->second == 0)
			if (floor(it->first) >= callsPerTimeUnit.size())
				callsPerTimeUnit.push_back(1);
			else
				callsPerTimeUnit[floor(it->first)]++;
		else
			if (floor(it->first) >= finishedPerTimeUnit.size())
				finishedPerTimeUnit.push_back(1);
			else
				finishedPerTimeUnit[floor(it->first)]++;
	}

	for (PerTimeUnitVector::const_iterator it = callsPerTimeUnit.begin(); it != callsPerTimeUnit.end(); it++)
	{
		callsStream << std::setw(9) << *it;
		callsStream << std::endl;
	}

	for (PerTimeUnitVector::const_iterator it = finishedPerTimeUnit.begin(); it != finishedPerTimeUnit.end(); it++)
	{
		finishedStream << std::setw(9) << *it;
		finishedStream << std::endl;
	}
}
