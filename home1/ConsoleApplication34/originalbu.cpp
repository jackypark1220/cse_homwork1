#define d_SCL_SECURE_NO_WARNINGS
#include <glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"
#include<algorithm>
#include<Windows.h>
#include"GeometricObject.h"
#include"Box.h"


class types : public GeometricObject {
public:
	void drawrectanline(const int x, const int y, const int r, const float& red, const float& green, const float& blue)
	{
		int x_c = x;
		int y_c = y;
		for (int a = 0; a <= 2 * r; a++)
		{
			for (int b = 0; b <= 2 * r; b++)
			{
				{
					drawPixel(x - r + b, y - r + a, red, green, blue);
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
	void rightvector(const int x, const int y, const int r)
	{
		for (int i = 0; i < 2 * r; i++)
		{
			drawPixel(x - r + i, y, 0, 0, 0);

		}
		drawLine(x + r - (r - 10), y - (r - 10), x + r, y, 0, 0, 0);
		drawLine(x + r - (r - 10), y + (r - 10), x + r, y, 0, 0, 0);
	}
	void drawA(const int x, const int y, const int r)
	{
		drawLine(x, y + 70, x + 40, y - 50, 0, 0, 0);
		drawLine(320, y - 50, x, y + 70, 0, 0, 0);
		for (int i = 0; i < 50; i++)
		{
			drawPixel(x - r / 2 + i, y - 5, 0, 0, 0);
		}
	}
	void linel(const int x, const int y, const int r)
	{
		//line Y//
		for (int j = 0; j < 100; j++)
		{
			drawPixel(x, y - r + j, 0, 0, 0);
		}
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
	void thickline(const int x, const int y, const int r) {
		for (int i = 0; i < 20; i++)
			drawLine(x - r, y - 70 + i, x + r, y + 50 + i, 0, 0, 0);
	}
	//thick line//
	void smallcircle(const int x, const int y, const int r) {
		for (int i = r - 5; i < r + 5; i++)
			colorcircle(x, y, i);
	}
	void drawx(const int x, const int y, const int r)
	{//draw x //
		drawLine(x - r, y - r, x + r, y + r, 0, 0, 0);
		drawLine(x - r, y + r, x + r, y - r, 0, 0, 0);
	}
	void downvector(const int x, const int y, const int r)
	{
		for (int j = 0; j < 100; j++)
		{
			drawPixel(x, y - r + j, 0, 0, 0);
		}
		drawLine(x, y - r, x + r - 10, y - 10, 0, 0, 0);
		drawLine(x - r + 10, y - 10, x, y - r, 0, 0, 0);
	}
};



void drawOnPixelBuffer()
{
	fflush(stdin);
	//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

													//for (int i = 0; i<width*height; i++) {
													//	pixels[i * 3 + 0] = 1.0f; // red 
													//	pixels[i * 3 + 1] = 1.0f; // green
													//	pixels[i * 3 + 2] = 1.0f; // blue
													//}

	const int i = rand() % width, j = rand() % height;
	//drawPixel(i, j, 0.0f, 0.0f, 0.0f);

	// drawing a line
	//TODO: anti-aliasing
	const int i0 = 100, i1 = 200;
	const int j0 = 50, j1 = 80;
	//drawLine(i0, j0, i1, j1, 1.0f, 0.0f, 0.0f);

	//TODO: try moving object


	/*drawrectanful(850, 850, 100, 0, 0, 100);
	drawrectanline(250, 250, 100, 250, 0, 0);
	drawthick(500, 800, 700, 900, 0, 255, 255);
	drawtri(500, 100, 650, 400, 800, 100, 255, 0, 0);
	drawpenta(600, 550, 550, 650, 650, 720, 750, 650, 700, 550, 255, 0, 0);*/
}

int main(void)
{
	GeometricObject* usericons[40];
	GeometricObject* myicons[40];
	GeometricObject dc;
	types db;

	GLFWwindow* window;
	GeometricObject* boj = new Box;
	/* Initialize the library */
	if (!glfwInit())
		return -1;


	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}



	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	// while background

	//register double x, y;
	//for (int i = 0; i < 10000; i++) {
	//	x = getRandouble(0, 1.0);
	//	y = getRandouble(0, 1.0);
	//	if (isinsideCircle(x, y))
	//		drawPixel(x, y, 1, 0, 0);
	//}
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{




		/* Render here */

		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer();
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		printf("%f, %f\n", xpos, ypos);
		double ypos_ = height - ypos;

		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 5; i++)
				//myicons[j * 10 + i * 2] = new icon(i * 200 + 100, j * 200 + 100, 70, 3, xpos, ypos);
				myicons[j * 10 + i * 2] = new icon2(i * 200 + 30, j * 200 + 30, i * 200 + 170, j * 200 + 170, 3, xpos, ypos);
		}

		//dc.usertype(xpos, ypos_, 130, 130, 100);
		//
		//dc.usertype(xpos, ypos_, 360, 130, 100);
		//
		//dc.usertype(xpos, ypos_, 590, 130, 100);
		//
		//dc.usertype(xpos, ypos_, 820, 130, 100);
		//
		//dc.usertype(xpos, ypos_, 1050, 130, 100);
		///////////////////////////////////////////
		//db.rightvector(130, 130, 50);
		//db.drawA(360, 130, 50);
		//db.linel(590, 130, 50);
		//db.leftvector(820, 130, 50);
		//db.upvector(1050, 130, 50);
		//db.thickline(130, 360, 50);
		//db.smallcircle(360, 360, 50);
		//db.drawrectanline(590, 360, 50, 0, 0, 0);
		//db.drawx(820, 360, 50);
		//db.downvector(1050, 360, 50);
		///////////////////////////////////////////
		//dc.usertype(xpos, ypos_, 130, 360, 100);
		//
		//dc.usertype(xpos, ypos_, 360, 360, 100);
		//
		//dc.usertype(xpos, ypos_, 590, 360, 100);
		//
		//dc.usertype(xpos, ypos_, 820, 360, 100);

		//dc.usertype(xpos, ypos_, 1050, 360, 100);
		///////////////////////////////////////////
		//dc.usertype(xpos, ypos_, 130, 590, 100);
		//dc.usertype(xpos, ypos_, 360, 590, 100);
		//dc.usertype(xpos, ypos_, 590, 590, 100);
		//dc.usertype(xpos, ypos_, 820, 590, 100);
		//dc.usertype(xpos, ypos_, 1050, 590, 100);
		///////////////////////////////////////////
		//dc.usertype(xpos, ypos_, 130, 820, 100);
		//;
		//dc.usertype(xpos, ypos_, 360, 820, 100);
		//
		//dc.usertype(xpos, ypos_, 590, 820, 100);
		//dc.usertype(xpos, ypos_, 820, 820, 100);
		//dc.usertype(xpos, ypos_, 1050, 820, 100);
		////////////////////////////////////////
		//db.rightvector(130, 590, 50);
		//db.drawA(360, 590, 50);
		//db.linel(590, 590, 50);
		//db.leftvector(820, 590, 50);
		//db.upvector(1050, 590, 50);
		//db.thickline(130, 820, 50);
		//db.smallcircle(360, 820, 50);
		//db.drawrectanline(590, 820, 50, 0, 0, 0);
		//db.drawx(820, 820, 50);
		//db.downvector(1050, 820, 50);













		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
		glClearColor(1, 1, 1, 1);
		/* Swap front and back buffers */
		glfwSwapBuffers(window);



		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}


	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;

}
