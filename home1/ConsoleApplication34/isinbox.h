#pragma once
#include<iostream>
#include"GeometricObject.h"

void drawblackinbox(const int x, const int y, const int r);
void drawyellowinbox(const int x, const int y, const int r);
bool isinsideBox(double xpos, double ypos, int x, int y, int r);
void usertype2(double xpos, double ypos, int x, int y, int r);
class isinbox : public GeomericObject {
public:

	void draw()
	{
		usertype2(xpos,ypos,x,y,r);
	}
};