#include"EventHandler.h"

using namespace std;

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