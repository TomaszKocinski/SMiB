#pragma once
#include "Header.h"
#include <vector>
class SMO
{
private:
	const int T;
	const int L;
	vector<int> values_from_PD;
	Queue *queue;
	vector<Channel> channels;
	EventHandler *event_handler;
public:
	SMO();
	void Initializing_vec_of_PD();
};
