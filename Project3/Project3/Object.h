#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>

class Object
{
public:
	Object();
	~Object();
	void virtual draw() = 0;	// function to be overwritten in sub-classes

	void setNumVertices(int);
	int getNumVertices();

private:

	int numVertices;
};

