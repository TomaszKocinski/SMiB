#include"MapContener.h"
#include"Crossroad.h"
#include<iostream>
#include<list>
#include<iterator>

using namespace std;
Map::Map()
{
	crossroad = new Crossroad*[hSize];
	for (int i = 0; i < hSize; i++)
	{
		crossroad[i] = new Crossroad[vSize];

	}

}

Map::~Map()
{
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
	while (!current_point.isEqual(destination)) {
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

	list<point>::iterator ite;
	for (ite = visited_streets.begin(); ite != visited_streets.end(); ite++) {
		cout << ite->x << "," << ite->y<<endl;
	}
}
void Map::Draw() {
	/*cout << "  ,"<<(int)(Tab_Of_Values_Horizontal[0][0]*10)<<"   ," << (int)(Tab_Of_Values_Horizontal[0][1] * 10) << "   ," << (int)(Tab_Of_Values_Horizontal[0][2] * 10) << "   ," << (int)(Tab_Of_Values_Horizontal[0][3] * 10) << "\n";
	cout << "o----o----o----o----o\n|    |    |    |    |\n";
	cout << "|," << (int)(Tab_Of_Values_Vertical[0][0] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[0][1] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[0][2] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[0][3] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[0][4] * 10) << "\n";
	cout << "| ," << (int)(Tab_Of_Values_Horizontal[1][0] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[1][1] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[1][2] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[1][3] * 10) << " |\n";
	cout << "o----o----o----o----o\n|    |    |    |    |\n";
	cout << "|," << (int)(Tab_Of_Values_Vertical[1][0] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[1][1] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[1][2] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[1][3] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[1][4] * 10) << "\n";
	cout << "| ," << (int)(Tab_Of_Values_Horizontal[2][0] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[2][1] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[2][2] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[2][3] * 10) << " |\n";
	cout << "o----o----o----o----o\n|    |    |    |    |\n";
	cout << "|," << (int)(Tab_Of_Values_Vertical[2][0] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[2][1] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[2][2] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[2][3] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[2][4] * 10) << "\n";
	cout << "| ," << (int)(Tab_Of_Values_Horizontal[3][0] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[3][1] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[3][2] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[3][3] * 10) << " |\n";
	cout << "o----o----o----o----o\n|    |    |    |    |\n";
	cout << "|," << (int)(Tab_Of_Values_Vertical[3][0] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[3][1] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[3][2] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[3][3] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[3][4] * 10) << "\n";
	cout << "| ," << (int)(Tab_Of_Values_Horizontal[4][0] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[4][1] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[4][2] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[4][3] * 10) << " |\n";
	cout << "o----o----o----o----o\n";*/
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << " ";
			cout << crossroad[i][j].N;
			cout << " ";
			cout << crossroad[i][j].E;
			cout << " ";
			cout << crossroad[i][j].S;
			cout << " ";
			cout << crossroad[i][j].W;
			cout << '\n';
		}
		cout << "\n\n\n";
	}

}

bool point::isEqual(point arg)
{
	if (arg.x == this->x && arg.y == this->y) return true;
	return false;
}
