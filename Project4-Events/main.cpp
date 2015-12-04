#include <iostream>
#include "SMO.h"
using namespace std;

int main() {
	SMO smo;

	
	while (smo.event_handler->showFirst().first < smo.T) {
		int channel_nr = smo.event_handler->showFirst().second;
		
		cout <<channel_nr << " ";
		for (int i = 0; i < smo.N; i++) {
			cout << smo.channels[i];
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
		
		
	}
	return 0;
}