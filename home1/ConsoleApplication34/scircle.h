#pragma once
#include<iostream>
#include"GeometricObject.h"
void smallcircle(const int x, const int y, const int r);
class scircle : public GeometricObject {
public:
		 void draw()
		 {
			 smallcircle(x, y, r);
		 }
	
};