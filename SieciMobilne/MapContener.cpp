#include "MapContener.h"
#include "Crossroad.h"
#include <iostream>
#include <list>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <random>
#include <cmath>

using namespace std;
class point;
bool point::operator==(point arg)
{
	if (arg.x == this->x && arg.y == this->y) return true;
	return false;
}

bool point::operator!=(point arg)
{
	if (arg.x != this->x || arg.y != this->y) return true;
	return false;
}

Map::Map()
{
	crossroad = new Crossroad*[hSize];
	for (int i = 0; i < hSize; i++)
	{
		crossroad[i] = new Crossroad[vSize];
	}
}

void Map::Traffic()
{
	for (int i = 0; i < vSize; i++) {
		for (int j = 0; j < hSize - 1; j++) {
			crossroad[i][j].Traffic('E');
			crossroad[j][i].Traffic('S');
		}
	}
	for (int i = vSize - 1; i >= 0; i--) {
		for (int j = hSize - 1; j > 0; j--) {
			crossroad[i][j].W = crossroad[i][j - 1].E;
			crossroad[j][i].N = crossroad[j - 1][i].S;
		}
	}

}

void Map::Find_Way(point source, point destination)
{
	list<point> visited_streets;
	visited_streets.push_back(source);
	point current_point = source;
	while (current_point != destination) {
		if (current_point.x < destination.x) {
			if (current_point.y < destination.y) {
				if (crossroad[current_point.x][current_point.y].E <= crossroad[current_point.x][current_point.y].S) {
					current_point.x++;
				}
				else current_point.y++;
			}
			else if (current_point.y > destination.y) {
				if (crossroad[current_point.x][current_point.y].E <= crossroad[current_point.x][current_point.y].N) {
					current_point.x++;
				}
				else current_point.y--;
			}
			else {
				current_point.x++;
			}
		}

		else if (current_point.x > destination.x) {
			if (current_point.y < destination.y) {
				if (crossroad[current_point.x][current_point.y].W <= crossroad[current_point.x][current_point.y].S) {
					current_point.x--;
				}
				else current_point.y++;
			}
			else if (current_point.y > destination.y) {
				if (crossroad[current_point.x][current_point.y].W <= crossroad[current_point.x][current_point.y].N) {
					current_point.x--;
				}
				else current_point.y--;
			}
			else {
				current_point.x--;
			}
		}

		else {
			if (current_point.y < destination.y) {
				current_point.y++;
			}
			else current_point.y--;
		}
		visited_streets.push_back(current_point);
	}

	ofstream file("data.txt");

	list<point>::iterator ite;
	for (ite = visited_streets.begin(); ite != visited_streets.end(); ite++) {
		file << ite->y << " " << ite->x << endl;
	}

	cout << endl << "Route saved in file data.txt" << endl;
}

void Map::Find_Way_Extended(point source, point destination)
{
	cout << "Source And Destination: (" << source.x << "," << source.y << ")->(" << destination.x << "," << destination.y << ")" << endl << endl;
	list<point> visited_streets;
	visited_streets.push_back(source);
	point current_point = source;
	while (current_point != destination) {
		if (current_point.x < destination.x) {
			if (current_point.y < destination.y) {
				if (crossroad[current_point.x][current_point.y].E <= crossroad[current_point.x][current_point.y].S) {
					current_point.x++;
					cout << "(" << current_point.x - 1 << "," << current_point.y << ")->(" << current_point.x << "," << current_point.y << ") - because: " << setw(4) << left << crossroad[current_point.x - 1][current_point.y].E << " <= " << setw(4) << crossroad[current_point.x - 1][current_point.y].S;
				}
				else {
					current_point.y++;
					cout << "(" << current_point.x << "," << current_point.y - 1 << ")->(" << current_point.x << "," << current_point.y << ") - because: " << setw(4) << left << crossroad[current_point.x][current_point.y - 1].S << " <= " << setw(4) << crossroad[current_point.x][current_point.y - 1].E;
				}
			}
			else if (current_point.y > destination.y) {
				if (crossroad[current_point.x][current_point.y].E <= crossroad[current_point.x][current_point.y].N) {
					current_point.x++;
					cout << "(" << current_point.x - 1 << "," << current_point.y << ")->(" << current_point.x << "," << current_point.y << ") - because: " << setw(4) << left << crossroad[current_point.x - 1][current_point.y].E << " <= " << setw(4) << crossroad[current_point.x - 1][current_point.y].N;
				}
				else {
					current_point.y--;
					cout << "(" << current_point.x << "," << current_point.y + 1 << ")->(" << current_point.x << "," << current_point.y << ") - because: " << setw(4) << left << crossroad[current_point.x][current_point.y - 1].N << " <= " << setw(4) << crossroad[current_point.x][current_point.y - 1].E;
				}
			}
			else {
				current_point.x++;
				cout << "(" << current_point.x - 1 << "," << current_point.y << ")->(" << current_point.x << "," << current_point.y << ") - because: dest y=" << destination.y << " & curr x(" << current_point.x << ")< dest x(" << destination.y << ")";
			}
		}

		else if (current_point.x > destination.x) {
			if (current_point.y < destination.y) {
				if (crossroad[current_point.x][current_point.y].W <= crossroad[current_point.x][current_point.y].S) {
					current_point.x--;
					cout << "(" << current_point.x + 1 << "," << current_point.y << ")->(" << current_point.x << "," << current_point.y << ") - because: " << setw(4) << left << crossroad[current_point.x + 1][current_point.y].W << " <= " << setw(4) << crossroad[current_point.x - 1][current_point.y].S;
				}
				else {
					current_point.y++;
					cout << "(" << current_point.x << "," << current_point.y - 1 << ")->(" << current_point.x << "," << current_point.y << ") - because: " << setw(4) << left << crossroad[current_point.x][current_point.y - 1].S << " <= " << setw(4) << crossroad[current_point.x][current_point.y - 1].W;
				}
			}
			else if (current_point.y > destination.y) {
				if (crossroad[current_point.x][current_point.y].W <= crossroad[current_point.x][current_point.y].N) {
					current_point.x--;
					cout << "(" << current_point.x + 1 << "," << current_point.y << ")->(" << current_point.x << "," << current_point.y << ") - because: " << setw(4) << left << crossroad[current_point.x + 1][current_point.y].W << " <= " << setw(4) << crossroad[current_point.x + 1][current_point.y].N;
				}
				else {
					current_point.y--;
					cout << "(" << current_point.x << "," << current_point.y + 1 << ")->(" << current_point.x << "," << current_point.y << ") - because: " << setw(4) << left << crossroad[current_point.x][current_point.y + 1].N << " <= " << setw(4) << crossroad[current_point.x][current_point.y + 1].W;
				}
			}
			else {
				current_point.x--;
				cout << "(" << current_point.x + 1 << "," << current_point.y << ")->(" << current_point.x << "," << current_point.y << ") - because: dest y=" << destination.y << " & curr x(" << current_point.x << ")> dest x(" << destination.y << ")";
			}
		}

		else {
			if (current_point.y < destination.y) {
				current_point.y++;
				cout << "(" << current_point.x << "," << current_point.y - 1 << ")->(" << current_point.x << "," << current_point.y << ") - because: dest x=" << destination.x << " & curr y(" << current_point.y << ")< dest y(" << destination.y << ")";

			}
			else {
				current_point.y--;
				cout << "(" << current_point.x << "," << current_point.y + 1 << ")->(" << current_point.x << "," << current_point.y << ") - because: dest x=" << destination.x << " & curr y(" << current_point.y << ")> dest y(" << destination.y << ")";
			}
		}
		visited_streets.push_back(current_point);
		cout << "\n";
	}

	ofstream file("data.txt");

	list<point>::iterator ite;
	int i = 0;
	for (ite = visited_streets.begin(); ite != visited_streets.end(); ite++) {
		file << ite->x << " " << ite->y << endl;
	}

	cout << endl << "Route saved in file data.txt" << endl;
}
void Map::Find_Way_Attempt_Third(point source, point destination) {
	list<point> visited_streets;
	visited_streets.push_back(source);
	point current_point = source;
	while (current_point != destination) {
		current_point = looking_for_destination(current_point, destination, visited_streets);
		if (current_point.x == -1 || current_point.y==-1) throw new exception();
		list<point>::iterator ite = visited_streets.end();
		ite--;
		cout << (*ite).x << (*ite).y << endl;
	}
}
point Map::looking_for_destination(point current_point, point destination, list<point>& visited_streets) {
	char Choosen_Path;
	bool Can_N = false, Recommended_To_Go_N = false,
		Can_E = false, Recommended_To_Go_E = false,
		Can_S = false, Recommended_To_Go_S = false,
		Can_W = false, Recommended_To_Go_W = false;
	if (crossroad[current_point.x][current_point.y].N != -1) Can_N = true;
	if (crossroad[current_point.x][current_point.y].E != -1) Can_E = true;
	if (crossroad[current_point.x][current_point.y].S != -1) Can_S = true;
	if (crossroad[current_point.x][current_point.y].W != -1) Can_W = true;

	point previous_point;
	if (visited_streets.size() > 1) {
		list<point>::iterator ite = visited_streets.end();
		--ite;
		previous_point = *(--ite);
		if (previous_point.x > current_point.x) Can_E = false;
		else if (previous_point.x < current_point.x) Can_W = false;
		else if (previous_point.y > current_point.y) Can_S = false;
		else if (previous_point.y < current_point.y) Can_N = false;
	}
	if (destination.x > current_point.x && Can_E)  Recommended_To_Go_E = true;
	if (destination.x < current_point.x && Can_W)  Recommended_To_Go_W = true;
	if (destination.y > current_point.y && Can_S)  Recommended_To_Go_S = true;
	if (destination.y < current_point.y && Can_N)  Recommended_To_Go_N = true;
	while (true)
	{


		if (Recommended_To_Go_N && Recommended_To_Go_E) {
			if (crossroad[current_point.x][current_point.y].N < crossroad[current_point.x][current_point.y].E) {
				Choosen_Path = 'N';
			}
			else
			{
				Choosen_Path = 'E';
			}
		}
		else if (Recommended_To_Go_E && Recommended_To_Go_S) {
			if (crossroad[current_point.x][current_point.y].E < crossroad[current_point.x][current_point.y].S) {
				Choosen_Path = 'E';
			}
			else
			{
				Choosen_Path = 'S';
			}
		}
		else if (Recommended_To_Go_S && Recommended_To_Go_W) {
			if (crossroad[current_point.x][current_point.y].S < crossroad[current_point.x][current_point.y].W) {
				Choosen_Path = 'S';
			}
			else
			{
				Choosen_Path = 'W';
			}
		}
		else if (Recommended_To_Go_W && Recommended_To_Go_N) {
			if (crossroad[current_point.x][current_point.y].W < crossroad[current_point.x][current_point.y].N) {
				Choosen_Path = 'W';
			}
			else
			{
				Choosen_Path = 'N';
			}
		}
		else if (Recommended_To_Go_E && !Recommended_To_Go_S  && !Recommended_To_Go_W  && !Recommended_To_Go_N) {
			Choosen_Path = 'E';
		}
		else if (Recommended_To_Go_N && !Recommended_To_Go_S  && !Recommended_To_Go_W  && !Recommended_To_Go_E) {
			Choosen_Path = 'N';
		}
		else if (Recommended_To_Go_W && !Recommended_To_Go_S  && !Recommended_To_Go_E  && !Recommended_To_Go_N) {
			Choosen_Path = 'W';
		}
		else if (Recommended_To_Go_S && !Recommended_To_Go_N  && !Recommended_To_Go_W  && !Recommended_To_Go_E) {
			Choosen_Path = 'S';
		}
		else if (Can_E && !Can_S && !Can_N && !Can_W) {
			Choosen_Path = 'E';
		}
		else if (Can_W && !Can_S && !Can_N && !Can_E) {
			Choosen_Path = 'W';
		}
		else if (Can_N && !Can_S && !Can_E && !Can_W) {
			Choosen_Path = 'N';
		}
		else if (Can_S && !Can_E && !Can_N && !Can_W) {
			Choosen_Path = 'S';
		}
		else if (!Can_E && !Can_N && !Can_S && !Can_W) {
			cout << "THIS SHOULD BE EXEPCTION";
			return point(-1, -1);
		}
		else {
			cout << "SOMETHING IS WRONG, NOT ENOUGH SITUATIONS";
		}

		random_device rd;
		default_random_engine e1(rd());
		uniform_int_distribution<int> uniform_dist(0, 100);
		double Propability_of_Trafic_Jam;
		Propability_of_Trafic_Jam = uniform_dist(e1)*0.01;

		if (Choosen_Path == 'E') {
			if (crossroad[current_point.x][current_point.y].E < Propability_of_Trafic_Jam) {
				current_point.x++;
				break;
			}
			else {
				Can_E = false;
				Recommended_To_Go_E = false;
				continue;
			}
		}
		if (Choosen_Path == 'N') {
			if (crossroad[current_point.x][current_point.y].N < Propability_of_Trafic_Jam) {
				current_point.y--;
				break;
			}
			else {
				Can_N = false;
				Recommended_To_Go_N = false;
				continue;
			}
		}
		if (Choosen_Path == 'W') {
			if (crossroad[current_point.x][current_point.y].W < Propability_of_Trafic_Jam) {
				current_point.x--;
				break;
			}
			else {
				Can_W = false;
				Recommended_To_Go_W = false;
				continue;
			}
		}
		if (Choosen_Path == 'S') {
			if (crossroad[current_point.x][current_point.y].S < Propability_of_Trafic_Jam) {
				current_point.y++;
				break;
			}
			else {
				Can_S = false;
				Recommended_To_Go_S = false;
				continue;
			}
		}
	}
	visited_streets.push_back(current_point);
	return current_point;
}
void Map::Draw() {
	for (int i = 0; i < vSize - 1; i++) {
		if (i == 0) {
			for (int j = 0; j < hSize - 1; j++) {
				cout << setw(7) << right << crossroad[i][j].E << setw(3) << " ";
			}
		}
		else {
			for (int j = 0; j < hSize - 1; j++) {
				cout << setw(1) << char(179) << setw(6) << right << crossroad[i][j].E << setw(3) << " ";
			}
			cout << char(179);
		}
		cout << endl;

		for (int j = 0; j < hSize - 1; j++) {
			cout << setw(1) << char(219) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
		}
		cout << char(219) << endl;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < hSize; j++) {
				cout << setw(10) << left << char(179);
			}
			cout << endl;
		}

		for (int j = 0; j < hSize; j++) {
			cout << setw(1) << left << char(179) << setw(9) << left << crossroad[i][j].S;
		}
		cout << endl;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < hSize; j++) {
				cout << setw(10) << left << char(179);
			}
			cout << endl;
		}
	}

	int i = vSize - 1;
	for (int j = 0; j < hSize - 1; j++) {
		cout << setw(1) << char(179) << setw(6) << right << crossroad[i][j].E << setw(3) << " ";
	}
	cout << char(179) << endl;

	for (int j = 0; j < hSize - 1; j++) {
		cout << char(219) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	}
	cout << char(219) << endl;
}