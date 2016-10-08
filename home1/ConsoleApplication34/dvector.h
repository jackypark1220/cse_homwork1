#pragma once
#include<iostream>
#include"GeometricObject.h"
void downvector(const int x, const int y, const int r);
class dvector : public GeometricObject {
	
	void draw()
	{
		downvector(x, y, r);
	}
};