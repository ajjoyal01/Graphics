#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>

#include "Shape.h"
#include "Square.h"

#define NUM_FACES 6

using namespace std;

class Cube : public Object
{

public:
	Cube();
	Cube(float,GLfloat[4]);
	~Cube();
	void draw();
	void init(float,GLfloat[4]);

private:

	Square* faces[NUM_FACES];	// pointers to faces (Squares)
};

