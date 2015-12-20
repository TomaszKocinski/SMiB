#include "Queue.h"
#include<iostream>

using namespace std;

Queue::Queue(int length)
{
	if (length > 0)
		L = length;
	else
		L = 20;
	l = 0;
}

int Queue::getl() const
{
	return l;
}

int Queue::getL() const
{
	return L;
}

bool Queue::isFull() const
{
	if (l < L)
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