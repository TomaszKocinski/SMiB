#pragma once

class Queue {
	int L;
	int l;
public:
	Queue(int);
	int getl() const;
	int getL() const;
	bool isFull() const;
	int operator++(int);
	int operator--(int);
};