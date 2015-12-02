#include "Header.h"
#include <iostream>
using namespace std;
int Channel::count = 0;
Queue::Queue(int length)
{
	if (length > 0)
		L = length;
	else
		L = 20;
	l = 0;
}

int Queue::getl()
{
	return l;
}

int Queue::getL()
{
	return L;
}

int Queue::operator++(int)
{
	if (l == L) {
		cout << "Queue is already full. Cannot add another dude." << endl;
		return l;
	}
	else
		return l++;
}

int Queue::operator--(int)
{
	if (l == 0) {
		cout << "Queue is empty." << endl;
		return l;
	}
	else
		return l--;
}

Channel::Channel()
{
	number = ++count;
	busy = false;
}

void Channel::setBusy()
{
	if (busy)
		cout << "Channel is already busy" << endl;
	else
		busy = true;
}

void Channel::setFree()
{
	if (!busy)
		cout << "Channel is already free" << endl;
	else
		busy = false;
}

bool Channel::isBusy()
{
	if (busy)
		return true;
	else
		return false;
}

EventHandler::EventHandler()
{

}

void EventHandler::push(double time, int channel)
{
	events.insert(pair<double, int>(time, channel));
}

pair<double, int> EventHandler::pop()
{
	if (events.empty()) {
		throw exception("EventHandler table is empty.");
	}
	pair<double, int> temp;
	temp.first = events.begin()->first;
	temp.second = events.begin()->second;
	events.erase(events.begin());
	return temp;
}

