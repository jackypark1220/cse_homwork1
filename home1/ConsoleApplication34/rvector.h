#pragma once
#include<iostream>
#include"GeometricObject.h"
void rightvector(const int x, const int y, const int r);
class rvector : public GeometricObject {
	
	void draw()
	{
		rightvector(x, y, r);
	}
};