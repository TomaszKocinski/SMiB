#pragma once
#include "EventHandler.h"
#include "Channel.h"
#include "Queue.h"
#include"Report.h"
#include <vector>
#include <random>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class SMO
{
protected:
	SMO();
	int T;
	int N;
	int La;
	int Mi;
	Queue *queue;
	vector<Channel> channels;
	EventHandler *event_handler;
	pair<double, int> currentT;
	double generate() const;
	Report* report;
public:
	SMO(int, int, int = 8, int = 3, int = 15);
	virtual ~SMO();
	pair<double, int> getCurrentT() const;
	int getT() const;
	int getN() const;
	int getL() const;
	bool event();
	virtual double getT0Time() const;
	virtual double getTnTime() const;
	void createReport(ostream& = cout, ostream& = cout, ostream& = cout, ostream& = cout) const;
};
