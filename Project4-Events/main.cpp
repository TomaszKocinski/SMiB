#include <iostream>
#include <fstream>
#include "SMO.h"
using namespace std;

int main() {
	SMO smo;
	ofstream file("data.txt");
	vector<int> number_of_events_arrived_and_handled;
	for (int i = 0; i <= smo.N; i++)
	{
		number_of_events_arrived_and_handled.push_back(0);
	}
	while (smo.event_handler->showFirst().first < smo.T) {
		int number_of_channel_full = 0;
		int channel_nr = smo.event_handler->showFirst().second;
		cout <<channel_nr << " ";
		for (int i = 0; i < smo.N; i++) {
			cout << smo.channels[i];
			if (smo.channels[i].isBusy()) number_of_channel_full++;
		}
		cout << " "<<smo.event_handler->showFirst().first << endl;
		
		
		if (channel_nr == 0) {
			smo.event_t1();
		}
		else if (channel_nr >0 && channel_nr <= smo.N) {
			smo.event_t2(channel_nr);	
		}
		else {
			cout << "value smo.event_handler->showFirst().second different than expected" << endl;
		}
		number_of_events_arrived_and_handled[channel_nr]++;
		file << smo.event_handler->showFirst().first << " " << smo.queue.getl()<<" "<< number_of_channel_full;

		for (vector<int>::iterator ite = number_of_events_arrived_and_handled.begin(); ite != number_of_events_arrived_and_handled.end(); ite++)
			file << " " << *ite;
		file<< endl;
		
	}
	file.close();
	return 0;
}