#pragma once
#include <map>
#include <functional>

using namespace std;

class Queue {
	
	int L;
	int l;

public:
	Queue(int);
	int getl();
	int getL();
	
	int operator++(int);
	int operator--(int);
};

class Channel {
	static int count;
	int number;
	bool busy;

public:
	Channel();
	
	void setBusy();
	void setFree();
	bool isBusy();
};

class EventHandler {
	multimap<double, int> events;

public:
	EventHandler();
	void push(double, int);
	pair<double, int> pop();

};

