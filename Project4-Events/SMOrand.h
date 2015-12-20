#pragma once
#include "SMO.h"
#include <vector>

using namespace std;

class SMOrand : public SMO {
public:
	SMOrand(int, int, int = 8, int = 3, int = 15);
	~SMOrand();
	double getT0Time() const;
	double getTnTime() const;
};