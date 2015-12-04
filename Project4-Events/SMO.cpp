#include "SMO.h"
#include "Header.h"
#include <random>
#include <iostream>
#include <iomanip>
SMO::SMO() :T(4), L(3), N(2), queue(L)
{
	if (N < 1 || N>6)
		N = 3;
	event_handler = new EventHandler();
	for (int i = 0; i < N; i++)
	{
		channels.push_back(Channel());
	}
	Initializing_vec_of_PD();
	Initialize_event_tab();
}

void SMO::Initializing_vec_of_PD()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::poisson_distribution<> d(4);
	for (int i = 0; i < T; i++)
	{
		values_from_PD.push_back(d(gen));
	}
	std::exponential_distribution<> e(4);
	for (int i = 0; i < T; i++)
	{
		values_from_EX.push_back(e(gen));
	}
	for (vector<int>::iterator ite = values_from_PD.begin(); ite != values_from_PD.end(); ite++)
		cout <<*ite << "    ";
	cout << endl;
	for (vector<double>::iterator ite = values_from_EX.begin(); ite != values_from_EX.end(); ite++)
		cout << "0."<<(int)(*ite*100) << " ";
	cout << endl;
}
void SMO::event_t1()
{
	setCurrentMiLa();
	event_handler->replace(event_handler->showFirst().first +(1.0 / currentLa), 0); //t1
	if (!(queue.isFull())) {
		queue++;
		for (int i = 0; i < N; i++) {
			if (!channels[i].isBusy()) {
				queue--;
				channels[i].setBusy();
				event_handler->replace(event_handler->showFirst().first + (currentMi / 0.6), i+1); // ??????????????? t2
				break;
			}
		}

	}
	else
	{
		cout << "Queue is full, patient have been forced to leave" << endl;
	}
}

void SMO::event_t2(int channel)
{
	setCurrentMiLa();
	channels[channel-1].setFree();
	event_handler->replace(1000, channel);

	if (queue.getl() > 0){
		queue--;
		channels[channel-1].setBusy();
		event_handler->replace(event_handler->showFirst().first + (currentMi / 0.6), channel);
	}
}

void SMO::Initialize_event_tab()
{
	event_handler->push(0, 0);

	for (int i = 1; i <= N; i++)
		event_handler->push(1000, i);
}

void SMO::setCurrentMiLa()
{
	double time = event_handler->showFirst().first;
	for (int i = 0; i < T; i++) {
		if (time >= i && time < i + 1 && currentMi!= values_from_PD[i] && currentMi != values_from_EX[i]){
			currentLa = values_from_PD[i];
			currentMi = values_from_EX[i];
			cout << "Change of Lamda:"<<  currentLa <<" & Mi:" << currentMi <<endl;
			break;
		}
	}
}




