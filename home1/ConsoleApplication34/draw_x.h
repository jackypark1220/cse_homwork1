#pragma once
#include<iostream>
#include"GeometricObject.h"
void drawx(const int x, const int y, const int r);
class draw_x : public GeometricObject {
	
	
	void draw()
	{
		drawx( x,  y,  r);
	}
};
