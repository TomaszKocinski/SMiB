#include"Crossroad.h"
#include<iostream>
#include <random>
#include <cmath>
using namespace std;
void Crossroad::Traffic(char arg) {
	random_device rd;
	default_random_engine e1(rd());
	uniform_int_distribution<int> uniform_dist(0, 100);
	if (arg == 'N') {
		N= uniform_dist(e1)*0.01;
	}
	else if (arg == 'E') {
		E = uniform_dist(e1)*0.01;
	}
	else if (arg == 'S') {
		S = uniform_dist(e1)*0.01;
	}
	else if (arg == 'W') {
		W = uniform_dist(e1)*0.01;
	}

	
	
}