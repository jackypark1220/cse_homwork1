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
#include"draw_x.h"
#include"drawA.h"
#include"dvector.h"
#include"GeometricObject.h"
#include"line_thick.h"
#include"lvector.h"
#include"rvector.h"
#include"scircle.h"
#include"stick.h"
#include"uvector.h"

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

///

//
	int main(void)
	{
		GLFWwindow* window;
		//initialize
		GeometricObject** icons = new GeometricObject*[20];
		GeometricObject** usericons = new GeometricObject*[20];
	
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

		
			int start_x = 130;
			int start_y = 130;
			int num = 0;
			int count = 0;
			/* Render here */

			//glClear(GL_COLOR_BUFFER_BIT);

			drawOnPixelBuffer();
			double xpos, ypos;
			glfwGetCursorPos(window, &xpos, &ypos);
			printf("%f, %f\n", xpos, ypos);double ypos_ = height - ypos;

			for (int j = 0; j < 4; j++)
			for (int i = 0; i < 5; i++) {
				icons[i] = new GeometricObject;
				icons[i]->x = 130 + 230 * i;
				icons[i]->y = 130 + 230 * j;
				icons[i]->r = 100;
				icons[i]->xpos = xpos;
				icons[i]->ypos = ypos_;
				icons[i]->draw();


			}//draw circle outside of icons;
			
			
			
			for (int i = 0; i < 2; i++)
			{
				
				usericons[10 * i + 0] = new drawA;
				usericons[10 * i + 0]->x =  1050;
				usericons[10 * i + 0]->y = 460 * i + 360;
				usericons[10 * i + 0]->r = 50;
				usericons[10 * i + 0]->draw();
				
				usericons[10 * i + 1] = new Box;
				usericons[10 * i + 1]->x =  130;
				usericons[10 * i + 1]->y = 460 * i + 130;
				usericons[10 * i + 1]->r = 50;
				usericons[10 * i + 1]->draw();
				
				usericons[10 * i + 2] = new draw_x;
				usericons[10 * i + 2]->x =  360;
				usericons[10 * i + 2]->y = 460 * i + 360;
				usericons[10 * i + 2]->r = 50;
				usericons[10 * i + 2]->draw();
				
				usericons[10 * i + 3] = new dvector;
				usericons[10 * i + 3]->x =  590;
				usericons[10 * i + 3]->y = 460 * i + 360;
				usericons[10 * i + 3]->r = 50;
				usericons[10 * i + 3]->draw();
			
				usericons[10 * i + 4] = new line_thick;
				usericons[10 * i + 4]->x =  130;
				usericons[10 * i + 4]->y = 460 * i + 360;
				usericons[10 * i + 4]->r = 50;
				usericons[10 * i + 4]->draw();
				
				usericons[10 * i + 5] = new lvector;
				usericons[10 * i + 5]->x =  820;
				usericons[10 * i + 5]->y = 460 * i + 360;
				usericons[10 * i + 5]->r = 50;
				usericons[10 * i + 5]->draw();
			
				usericons[10 * i + 6] = new rvector;
				usericons[10 * i + 6]->x =  1050;
				usericons[10 * i + 6]->y = 460 * i + 130;
				usericons[10 * i + 6]->r = 50;
				usericons[10 * i + 6]->draw();
				
				usericons[10 * i + 7] = new scircle;
				usericons[10 * i + 7]->x = 360;
				usericons[10 * i + 7]->y = 460 * i + 130;
				usericons[10 * i + 7]->r = 50;
				usericons[10 * i + 7]->draw();
				
				usericons[10 * i + 8] = new stick;
				usericons[10 * i + 8]->x =  590;
				usericons[10 * i + 8]->y = 460 * i + 130;
				usericons[10 * i + 8]->r = 50;
				usericons[10 * i + 8]->draw();
				
				usericons[10 * i + 9] = new uvector;
				usericons[10 * i + 9]->x =  820;
				usericons[10 * i + 9]->y = 460 * i + 130;
				usericons[10 * i + 9]->r = 50;
				usericons[10 * i + 9]->draw();
			
			}
			

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
