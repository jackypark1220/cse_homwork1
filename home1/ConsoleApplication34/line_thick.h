#pragma once
#include<iostream>
#include"GeometricObject.h"
void thickline(const int x, const int y, const int r);
class line_thick : public GeometricObject {

	void draw()
	{
		thickline(x, y, r);
	}
	//thick line//
};