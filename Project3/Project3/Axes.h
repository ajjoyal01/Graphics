#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>

#include "Object.h"

class Axes : class Object
{

public:
	Axes();
	~Axes();
	void draw();

private:

	GLfloat position[6][4];
	GLfloat color[6][4];
};

