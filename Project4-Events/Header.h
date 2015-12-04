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
	bool isFull();
	int operator++(int);
	int operator--(int);
};

class Channel {
	bool busy;
public:
	Channel();
	void setBusy();
	void setFree();
	bool isBusy();
	friend std::ostream& operator<<(std::ostream& os, const Channel& mp);
};

class EventHandler {
	multimap<double, int> events;
public:
	EventHandler();
	void push(double, int);
	pair<double, int> pop();
	pair<double, int> showFirst();
	void replace(double, int);
};

