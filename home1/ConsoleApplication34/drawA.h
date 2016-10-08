#pragma once
#include<iostream>
#include"GeometricObject.h"
void draw_A(const int x, const int y, const int r);
class drawA :public GeometricObject
{public:


	void draw()
	{
		draw_A(x,y,r);
	}
};