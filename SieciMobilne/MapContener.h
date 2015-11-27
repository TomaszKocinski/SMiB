#pragma once
#include<list>
class point {
public:
	int x,y;
	point(int x_arg,int y_arg):x(x_arg),y(y_arg){}
	point(){}
	bool operator==(point);
	bool operator!=(point);
};
class Crossroad;

class Map
{
	Crossroad** crossroad;
	
public:
	const int vSize = 5;
	const int hSize = vSize;
	Map();
	~Map();
	void Draw();
	void Traffic();
	void Find_Way(point,point);
	void Find_Way_Extended(point, point);
	void Find_Way_Attempt_Third(point, point);
	point looking_for_destination(point, point, std::list<point>&);
private:

};

