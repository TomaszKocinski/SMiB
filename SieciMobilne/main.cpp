#include <iostream>
#include <string>
#include "MapContener.h"

using namespace std;

int main(void) {
	Map* Instace_Of_Map = new Map();
	Instace_Of_Map->Traffic();
	Instace_Of_Map->Draw();

	int xS = 0, yS = 0, xD = 0, yD = 0;

	/*cout << endl << endl << "Please input source point x (0-"<<Instace_Of_Map->hSize-1 <<"): ";
	cin >> xS;
	cout << "Please input source point y (0-" << Instace_Of_Map->vSize -1 << "): ";
	cin >> yS;
	cout << endl << "Please input destination point x (0-" << Instace_Of_Map->hSize -1 << "): ";
	cin >> xD;
	cout << "Please input destination point y (0-" << Instace_Of_Map->vSize -1 << "): ";
	cin >> yD;
	cout << endl;*/

	//Instace_Of_Map->Find_Way_Extended(point(xS, yS), point(xD, yD));
	//Instace_Of_Map->Find_Way_Recursive(point(xS, yS), point(xD, yD));
	Instace_Of_Map->Find_Way_Attempt_Third(point(0, 0), point(4, 4));
	cout << endl;

	return 0;
}