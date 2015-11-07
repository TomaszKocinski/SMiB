#include"MapContener.h"
using namespace std;
Map::Map()
{
	
	random_device rd;
	default_random_engine e1(rd());
	
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0; j < 5; j++)
		{
			uniform_real_distribution<double> uniform_dist(0, 1);
			Tab_Of_Values[i][j] = uniform_dist(e1);
		}
	}

}

Map::~Map()
{
}
void Map::Draw() {
	
}