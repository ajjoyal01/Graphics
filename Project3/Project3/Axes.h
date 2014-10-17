#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>

#include "Object.h"

#define NUM_VERTICES 6
#define DIMENTIONS 4
class Axes : public Object
{

public:
	Axes(GLfloat[NUM_VERTICES][DIMENTIONS], GLfloat[NUM_VERTICES][DIMENTIONS]);
	~Axes();
	void draw();

private:

	GLfloat position[6][4];
	GLfloat color[6][4];
};

