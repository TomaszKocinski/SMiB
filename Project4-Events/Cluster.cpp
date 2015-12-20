#include "Cluster.h"
#include <sstream>

Cluster::Cluster(bool random, Lambdas lValues, int miValue, Channels cValues, int tValue)
{
	for (int i = 0; i < clusterSize; i++)
		if (random)
			cells.push_back(new SMOrand(lValues[i], miValue, tValue, cValues[i], 1));
		else
			cells.push_back(new SMO(lValues[i], miValue, tValue, cValues[i], 1));
}

Cluster::~Cluster()
{
}

void Cluster::manage()
{
	int i = 0; // cluster number
	for (Cells::iterator it = cells.begin(); it != cells.end(); it++)
	{
		while ((*it)->event())
		{
		}

		i++;

		ostringstream data;
		data << ".\\cells\\dataCell" << i << ".txt";
		ofstream dataFile(data.str());

		ostringstream callsPerTimeUnit;
		callsPerTimeUnit << ".\\cells\\callsPerTimeUnitCell" << i << ".txt";
		ofstream callsPerTimeUnitFile(callsPerTimeUnit.str());

		ostringstream finishedPerTimeUnit;
		finishedPerTimeUnit << ".\\cells\\finishedPerTimeUnitCell" << i << ".txt";
		ofstream finishedPerTimeUnitFile(finishedPerTimeUnit.str());

		ostringstream dismissedPerTimeUnit;
		dismissedPerTimeUnit << ".\\cells\\dismissedPerTimeUnitCell" << i << ".txt";
		ofstream dismissedPerTimeUnitFile(dismissedPerTimeUnit.str());

		if (!dataFile.is_open() || !callsPerTimeUnitFile.is_open() || !finishedPerTimeUnitFile.is_open() || !dismissedPerTimeUnitFile.is_open())
			throw exception("Report couldn't be created!");

		(*it)->createReport(dataFile, callsPerTimeUnitFile, finishedPerTimeUnitFile, dismissedPerTimeUnitFile);

		std::cout << std::endl << "-------------------- CELL" << i << " --------------------" << std::endl;
		std::cout << "time" << "\ttype" << "\tqueue" << "\tch" << std::endl;
		(*it)->createReport();
	}
}