#pragma once

#include<map>
#include<iostream>

using namespace std;

class EventHandler
{
	multimap<double, int> events;
public:
	EventHandler();
	void push(double, int);
	pair<double, int> pop();
};