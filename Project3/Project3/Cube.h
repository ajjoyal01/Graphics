#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>


#include "Shape.h"

class Cube : public Shape
{

public:

	Cube();
	~Cube();
	void draw();

private:


};

