#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>

#include "Shape.h"

#define NUM_VERTICES 4
#define DIMENTIONS 4

//---------------------------------------------------------
// Vertex Arrays and Buffers
//---------------------------------------------------------
enum { VERTS, NUM_VAOS };
enum { BUFFER, NUM_BUFFERS };
//---------------------------------------------------------

class Square : public Shape
{

public:
	Square();
	~Square();
	void draw();

private:

	GLfloat position[NUM_VERTICES][DIMENTIONS];		// array to store vertex positions 4d
	GLfloat texCoords[NUM_VERTICES][DIMENTIONS];	// stores texture coords for each vertex
	GLfloat color[NUM_VERTICES][DIMENTIONS];		// stores color coords for each vertex
};

