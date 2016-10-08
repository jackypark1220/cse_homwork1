#pragma once
#include<iostream>
#include"GeometricObject.h"
void drawrectanline(const int x, const int y, const int r);

class Box : public GeometricObject {


public:
	


	void draw()
	{
		drawrectanline(x, y, r);
	}
};