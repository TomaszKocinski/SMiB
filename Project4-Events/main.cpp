#include "Cluster.h"
#include "SMOrand.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	Cluster* cluster;
	int T = 8, mi = 2, la = 3, ch = 1;
	Lambdas lambdas;
	Channels channels;
	bool option = true;

	try
	{
		do
		{
			system("CLS");
			for (int i = 0; i < Cluster::clusterSize; i++)
			{
				/*cout << "Podaj Lambde komorki nr" << i + 1 << ": ";
				cin >> la;
				cout << "Podaj liczbe kanalow komorki nr" << i + 1 << ": ";
				cin >> ch;*/
				lambdas.push_back(la);
				channels.push_back(ch);
			}

			cout << "Wybierz opcje: deterministycznie(0) / losowo(1): ";
			cin >> option;  // false = deterministycznie, true = losowo
			cluster = new Cluster(option, lambdas, mi, channels, T);
			cluster->manage();

			delete(cluster);

			cout << endl << "Zakonczyc program? (0 = nie/1 = tak): ";
			cin >> option;

		} while (!option);
	}
	catch (exception &e)
	{
		cout << e.what();
	}

	cout << endl << "Work finished" << endl << endl;

	return 0;
}