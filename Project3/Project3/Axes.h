#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>

#include "vgl.h"
#include "Object.h"

#define NUM_AXES 3			// number of axes (x,y,z)
#define NUM_VERTICES 2		// number of vertices per axis
#define DIMENTIONS 4		// dimention of vertices

//---------------------------------------------------------
// Vertex Array and Buffer
//---------------------------------------------------------
enum { AXES_VERTS, NUM_AXES_VAOS };
enum { AXES_BUFFER, NUM_AXES_BUFFERS };
//---------------------------------------------------------

//---------------------------------------------------------
// Vertex Attributes
//---------------------------------------------------------
enum { vPosition, vColor };
//---------------------------------------------------------

class Axes : public Object
{

public:
	Axes();
	Axes(GLfloat[NUM_AXES][NUM_VERTICES][DIMENTIONS], GLfloat[NUM_AXES][NUM_VERTICES][DIMENTIONS]);
	~Axes();
	void draw();

private:

	GLfloat position[NUM_AXES][NUM_VERTICES][DIMENTIONS];
	GLfloat color[NUM_AXES][NUM_VERTICES][DIMENTIONS];

	//---------------------------------------------------------
	// Vertex Arrays and Buffers
	//---------------------------------------------------------
	GLuint VAOs[NUM_AXES_VAOS];
	GLuint Buffers[NUM_AXES_BUFFERS];
	//---------------------------------------------------------
};

