#pragma once
#include "Header.h"
#include <vector>
class SMO
{

	
public:
	const int T;
	const int L;
	int N;
	double currentMi;
	double currentLa;
	vector<int> values_from_PD;
	vector<double> values_from_EX;
	Queue queue;
	vector<Channel> channels;
	EventHandler *event_handler;

	SMO();
	void Initializing_vec_of_PD();
	void event_t1();
	void event_t2(int channel);
	void Initialize_event_tab();
	void setCurrentMiLa();
};
