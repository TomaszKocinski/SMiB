#include<iostream>
#include<string>
#include"MapContener.h"
using namespace std;

int main(void) {
	Map* Instace_Of_Map=new Map();
	Instace_Of_Map->Traffic();
	Instace_Of_Map->Draw();
	Instace_Of_Map->Find_Way_Extended(point(0, 0), point(4, 4));
	//Instace_Of_Map->Draw();
	
}