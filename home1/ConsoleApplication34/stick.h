#pragma once
#include<iostream>
#include"GeometricObject.h"
void linel(const int x, const int y, const int r);
class stick : public GeometricObject
{
	
	
		//line Y//
		void draw()
		{
			linel(x, y, r);
		}
	
};