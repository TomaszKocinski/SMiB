#include"MapContener.h"
#include<iostream>
using namespace std;
Map::Map()
{
	
	random_device rd;
	default_random_engine e1(rd());
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0; j < 4; j++)
		{
			uniform_real_distribution<double> uniform_dist(0, 1);
			Tab_Of_Values_Horizontal[i][j] = uniform_dist(e1);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			uniform_real_distribution<double> uniform_dist(0, 1);
			Tab_Of_Values_Vertical[i][j] = uniform_dist(e1);
		}
	}
}

Map::~Map()
{
}
void Map::Draw() {
	cout << "  ,"<<(int)(Tab_Of_Values_Horizontal[0][0]*10)<<"   ," << (int)(Tab_Of_Values_Horizontal[0][1] * 10) << "   ," << (int)(Tab_Of_Values_Horizontal[0][2] * 10) << "   ," << (int)(Tab_Of_Values_Horizontal[0][3] * 10) << "\n";
	cout << "o----o----o----o----o\n|    |    |    |    |\n";
	cout << "|," << (int)(Tab_Of_Values_Vertical[0][0] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[0][1] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[0][2] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[0][3] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[0][4] * 10) << "\n";
	cout << "| ," << (int)(Tab_Of_Values_Horizontal[1][0] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[1][1] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[1][2] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[1][3] * 10) << " |\n";
	cout << "o----o----o----o----o\n|    |    |    |    |\n";
	cout << "|," << (int)(Tab_Of_Values_Vertical[1][0] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[1][1] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[1][2] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[1][3] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[1][4] * 10) << "\n";
	cout << "| ," << (int)(Tab_Of_Values_Horizontal[2][0] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[2][1] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[2][2] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[2][3] * 10) << " |\n";
	cout << "o----o----o----o----o\n|    |    |    |    |\n";
	cout << "|," << (int)(Tab_Of_Values_Vertical[2][0] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[20][1] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[2][2] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[2][3] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[2][4] * 10) << "\n";
	cout << "| ," << (int)(Tab_Of_Values_Horizontal[3][0] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[3][1] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[3][2] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[3][3] * 10) << " |\n";
	cout << "o----o----o----o----o\n|    |    |    |    |\n";
	cout << "|," << (int)(Tab_Of_Values_Vertical[3][0] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[3][1] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[3][2] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[3][3] * 10) << "  |," << (int)(Tab_Of_Values_Vertical[3][4] * 10) << "\n";
	cout << "| ," << (int)(Tab_Of_Values_Horizontal[4][0] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[4][1] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[4][2] * 10) << " | ," << (int)(Tab_Of_Values_Horizontal[4][3] * 10) << " |\n";
	cout << "o----o----o----o----o\n";
}