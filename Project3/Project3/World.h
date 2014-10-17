#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>

#include "LoadShaders.h"
#include "Shape.h"
#include "Cube.h"

class World
{

public:

	World();
	~World();
	void init();		// initializes World
	void display();		// display function
	void draw();		// draw function for entire World

private:
	
	Shape* shape1;		// pointers to three generic shapes
	Shape* shape2;
	Shape* shape3;
	Shape* currentShape;	// pointer to the current shape we are working with
};

