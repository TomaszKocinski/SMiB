#include "SMO.h"
#include "Header.h"
#include <random>
#include <iostream>
SMO::SMO():T(8),L(10)
{
	queue=new Queue(L);
	event_handler = new EventHandler();
	for (int i=0;i<3;i++)
	{
		channels.push_back(Channel());
	}
	Initializing_vec_of_PD();

}

void SMO::Initializing_vec_of_PD()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::poisson_distribution<> d(4);
	for (int i = 0; i<T; i++)
	{
		values_from_PD.push_back(d(gen));
	}
	for (vector<int>::iterator ite = values_from_PD.begin(); ite!=values_from_PD.end(); ite++)
	{
		cout << *ite << endl;
	}

}
