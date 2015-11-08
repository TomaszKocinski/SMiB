#pragma once
class point {
public:
	int x,y;
	point(int x_arg,int y_arg):x(x_arg),y(y_arg){}
	bool isEqual(point);
};
class Crossroad;
class Map
{
	Crossroad** crossroad;
	const int vSize = 5;
	const int hSize = vSize;
public:
	Map();
	~Map();
	void Draw();
	void Traffic();
	void Find_Way(point,point);
private:

};

