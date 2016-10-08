#pragma once
#include<iostream>
#include"GeometricObject.h"
void upvector(const int x, const int y, const int r);
class uvector : public GeometricObject {
	//void upvector(const int x, const int y, const int r) {
	//	//vector to up
	//	for (int j = 0; j < 100; j++)
	//	{
	//		drawPixel(x, y - r + j, 0, 0, 0);
	//	}
	//	drawLine(x, y + 50, x + (r - 10), y + 10, 0, 0, 0);
	//	drawLine(x - (r - 10), y + 10, x, y + 50, 0, 0, 0);
	//	//

	//}
	void draw()
	{
		upvector(x, y, r);
	}
};