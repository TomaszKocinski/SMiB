#include "Header.h"
#include <iostream>
using namespace std;
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

bool Queue::isFull()
{
	if(l<L)
		return false;
	return true;
}

int Queue::operator++(int)
{
	if (l == L) {
		cout << "Queue is already full. Cannot add another dude." << endl;
		return l;
	}
	else
		return ++l;
}

int Queue::operator--(int)
{
	if (l == 0) {
		cout << "Queue is empty." << endl;
		return l;
	}
	else
		return --l;
}

Channel::Channel()
{
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
	if (!busy){
		cout << "Channel is already free" << endl;
	}
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

std::ostream& operator<<(std::ostream& os, const Channel& mp)
{
	if (mp.busy)return os << "t";
	return os << "f";
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

pair<double, int> EventHandler::showFirst()
{
	if (events.empty()) {
		throw exception("EventHandler table is empty.");
	}
	pair<double, int> temp;
	temp.first = events.begin()->first;
	temp.second = events.begin()->second;
	return temp;
}

void EventHandler::replace(double d, int i)
{
	multimap<double, int>::iterator it;
	for (it = events.begin(); it->second != i; it++);
	if (it == events.end() || it->second !=i ) throw exception("Handler::replace coudln't find right event to replace");
	events.erase(it);
	events.insert(pair<double, int>(d, i));
}



