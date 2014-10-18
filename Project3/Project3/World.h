#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>

#include "LoadShaders.h"
#include "Shape.h"
#include "Cube.h"
#include "Axes.h"

#define NUM_SHAPES 3
#define NUM_AXES 3

class World
{

public:

	World();
	~World();
	void init();		// initializes World
	void display();		// display function
	void draw();		// draw function for entire World
	void initValues();	// initializes values for all objects
						// all values stored in this function, making it easy to change the values

private:
	
	Shape* shape[NUM_SHAPES];	//pointer array to shapes. 
								//more efficient to pass pointers around than whole arrays of data
	Axes axes;		// the three axes, drawn for reference
};

