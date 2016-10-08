#pragma once
#include<iostream>
#include"GeometricObject.h"
void leftvector(const int x, const int y, const int r);
class lvector : public GeometricObject {
	
	void draw()
	{
		leftvector(x, y, r);
	}
};