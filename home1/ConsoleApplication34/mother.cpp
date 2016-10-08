#include<iostream>
#include"GeometricObject.h"
float* pixels = new float[width*height * 3];
void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

//re-act aganist cursor
void drawcircle(const int x, const int y, const int r)
{
	for (int i = 0; i <= 360; i++) {
		drawPixel(x + r * cos(i), y + r * sin(i), 255, -255, -255);
	}
}
void colorcircle(const int x, const int y, const int r)
{
	for (int i = 0; i <= 360; i++) {
		drawPixel(x + r * cos(i), y + r * sin(i), 0, 0, 0);
	}
}
bool isinsideCircle(const double x, const double y, const double x_c, const double y_c, const double r_c) {
	double f = (x - x_c)*(x - x_c) + (y - y_c)* (y - y_c) - r_c*r_c;
	if (f <= 0)
		return true;
	else return false;
}

void usertype(const double x, const double y, const double x_c, const double y_c, const double r_c) {
	if (isinsideCircle(x, y, x_c, y_c, r_c) == true)
		drawcircle(x_c, y_c, r_c);
	else
		colorcircle(x_c, y_c, r_c);
}
////////////////////////




void downvector(const int x, const int y, const int r)
{
	for (int j = 0; j < 100; j++)
	{
		drawPixel(x, y - r + j, 0, 0, 0);
	}
	drawLine(x, y - r, x + r - 10, y - 10, 0, 0, 0);
	drawLine(x - r + 10, y - 10, x, y - r, 0, 0, 0);
}
void drawx(const int x, const int y, const int r)
{//draw x //
	drawLine(x - r, y - r, x + r, y + r, 0, 0, 0);
	drawLine(x - r, y + r, x + r, y - r, 0, 0, 0);
}
void smallcircle(const int x, const int y, const int r) {
	for (int i = r - 5; i < r + 5; i++)
		colorcircle(x, y, i);
}

void thickline(const int x, const int y, const int r) {
	for (int i = 0; i < 20; i++)
		drawLine(x - r, y - 70 + i, x + r, y + 50 + i, 0, 0, 0);
}
void upvector(const int x, const int y, const int r) {
	//vector to up
	for (int j = 0; j < 100; j++)
	{
		drawPixel(x, y - r + j, 0, 0, 0);
	}
	drawLine(x, y + 50, x + (r - 10), y + 10, 0, 0, 0);
	drawLine(x - (r - 10), y + 10, x, y + 50, 0, 0, 0);
	//

}
void rightvector(const int x, const int y, const int r)
{
	for (int i = 0; i < 2 * r; i++)
	{
		drawPixel(x - r + i, y, 0, 0, 0);

	}
	drawLine(x + r - (r - 10), y - (r - 10), x + r, y, 0, 0, 0);
	drawLine(x + r - (r - 10), y + (r - 10), x + r, y, 0, 0, 0);
}
void leftvector(const int x, const int y, const int r)
{//vector to left
	for (int i = 0; i < 100; i++)
	{
		drawPixel(x - r + i, y, 0, 0, 0);

	}
	drawLine(x - r, y, x - r + (r - 10), y + (r - 10), 0, 0, 0);
	drawLine(x - r, y, x - r + (r - 10), y - (r - 10), 0, 0, 0);
}
void linel(const int x, const int y, const int r)
{
	//line Y//
	for (int j = 0; j < 100; j++)
	{
		drawPixel(x, y - r + j, 0, 0, 0);
	}
}
void draw_A(const int x, const int y, const int r)
{
	drawLine(x, y + 70, x + 40, y - 50, 0, 0, 0);
	drawLine(x-40, y - 50, x, y + 70, 0, 0, 0);
	for (int i = 0; i < 50; i++)
	{
		drawPixel(x - r / 2 + i, y - 5, 0, 0, 0);
	}
}
void drawrectanline(const int x, const int y, const int r)
{
	int x_c = x;
	int y_c = y;
	for (int a = 0; a <= 2 * r; a++)
	{
		for (int b = 0; b <= 2 * r; b++)
		{
			{
				drawPixel(x - r + b, y - r + a, 255, 255, 0);
			}
		}
	}
	int g = (int)r *0.9;
	for (int a = 0; a <= 2 * g; a++)
	{
		for (int b = 0; b <= 2 * g; b++)
		{
			{
				drawPixel(x - g + b, y - g + a, 255, 255, 255);
			}
		}
	}
}




void drawblackinbox(const int x, const int y, const int r)
{

	for (int i = 0; i < 2 * r; i++)
	{
		drawPixel(x - r + i, y - r, 0, 0, 0); drawPixel(x - r, y - r + i, 0, 0, 0); drawPixel(x - r + i, y + r, 0, 0, 0); drawPixel(x + r, y - r + i, 0, 0, 0);
	}
}
void drawyellowinbox(const int x, const int y, const int r)
{

	for (int i = 0; i < 2 * r; i++)
	{
		drawPixel(x - r + i, y -r, 255, 255, 0); drawPixel(x - r , y - r+i, 255, 255, 0); drawPixel(x -r +i, y + r, 255, 255, 0); drawPixel(x + r, y - r + i, 255, 255, 0);
	}
}
bool isinsideBox(double xpos, double ypos, int x, int y, int r) {

	if (xpos > x - r&&xpos<x + r&&ypos>y - r&&ypos < y + r)
		return true;
	else return false;
}
void usertype2(double xpos, double ypos, int x, int y, int r) {
	if (isinsideBox(xpos, ypos, x, y, r) == true)
		drawblackinbox(x, y, r);
	else if (isinsideBox(xpos, ypos, x, y, r) == false)
		drawyellowinbox(x, y, r);
	else {};
}
