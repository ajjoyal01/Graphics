//------------------------------------------------------------------------------------
// Andrew Joyal and Greg Venezia
// Project 3
// 10/28/14
// Description: This project creates a 3D scene with three textured cubes. The cubes can be resized, rotated
//			and translated. 
//			
// Special Instructions:
//
//		Press 'l' to turn on lighting (ABOVE AND BEYOND!!)
//		Press 'i' to translate back in the z direction
//		Press 'o' to translate forwards in the z direction
//------------------------------------------------------------------------------------


#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <iostream>

#include "vgl.h"
#include "vec.h"
#include "LoadShaders.h"
#include "World.h"

// this is a useful compiler directive for mapping a value in a specified range to another range
// i.e. if value = 300, inLow = 0, inHigh = 300, outLow = -1.0, outHight = 1.0, would be the value 0.0
#define map(value,inLow,inHigh,outLow,outHigh) ((value - inLow) * (outHigh - outLow) / (inHigh - inLow) + outLow)

// window width and height
#define WIN_WIDTH 900
#define WIN_HEIGHT 900

using std::cerr;
using std::endl;
using std::cout;

World world;

void display()
{
	world.display();
}

void keyPress(unsigned char key,int x,int y)
{
	world.keyPress(key,x,y);
}

void specialFunc(int key, int x, int y)
{
	world.arrowInput(key, x, y);
}

int main(int argc,char* argv[])
{
	// setup display/version information
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutInitWindowPosition(600, 0);
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow("Project 3");

	glewExperimental = GL_TRUE;

	//error check
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}

	

	// initialize the world
	world.init();

	// set up the display and keyboard functions
	glutDisplayFunc(display);
	glutKeyboardFunc(keyPress);
	glutSpecialFunc(specialFunc);

	//glut main loop
	glutMainLoop();

	return 0;
}

