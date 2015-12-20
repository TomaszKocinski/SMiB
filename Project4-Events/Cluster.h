#pragma once
#include"SMO.h"
#include"SMOrand.h"
typedef std::vector<SMO*> Cells;
typedef std::vector<int> Channels;
typedef std::vector<int> Lambdas;

class Cluster
{
protected:
	Cells cells;
public:
	void manage();
	static const int clusterSize = 3;
	Cluster(bool, Lambdas, int, Channels, int);
	~Cluster();
};

