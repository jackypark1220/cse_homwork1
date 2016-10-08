#pragma once
#include<iostream>
#include<glfw3.h>

const int width = 1180;
const int height = 980;
extern float* pixels;

	void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue);
	void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);
	void drawcircle(const int x, const int y, const int r);
	void colorcircle(const int x, const int y, const int r);

	void usertype(const double x, const double y, const double x_c, const double y_c, const double r_c);

	void drawblackinbox(const int x, const int y, const int r);
	void drawyellowinbox(const int x, const int y, const int r);
	bool isinsideBox(double xpos, double ypos, int x, int y, int r);
	void usertype2(double xpos, double ypos, int x, int y, int r);
class GeometricObject {
public:
	int x, y, r;
	double xpos, ypos;

	virtual void draw()
	{
		usertype2(xpos,ypos,x,y,r);
		//if u change function name"usertype2" into "usertype" , you can draw circle icons //
	}
};