#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>

class Shape
{

public:

	Shape();
	~Shape();
	virtual void draw() = 0;	// function to be overwritten in sub-classes

private:


};

