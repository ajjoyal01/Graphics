#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>

#include "vgl.h"
#include "Object.h"
#include "Texture.h"

#define NUM_VERTICES 4
#define DIMENTIONS 4

//---------------------------------------------------------
// Vertex Array and Buffer
//---------------------------------------------------------
enum { SQUARE_VERTS, NUM_SQUARE_VAOS };
enum { SQUARE_BUFFER, NUM_SQUARE_BUFFERS };
//---------------------------------------------------------

using namespace std;

class Square : public Object
{

public:
	Square();
	~Square();
	void draw();
	void update();
	void init(GLfloat[4]);
	void addTexture(Texture texture);

//private:

	GLfloat position[NUM_VERTICES][DIMENTIONS];		// array to store vertex positions 4d
	GLfloat texCoords[NUM_VERTICES][DIMENTIONS];	// stores texture coords for each vertex
	GLfloat color[NUM_VERTICES][DIMENTIONS];		// stores color coords for each vertex

	//---------------------------------------------------------
	// Vertex Arrays and Buffers
	//---------------------------------------------------------
	GLuint VAOs[NUM_SQUARE_VAOS];
	GLuint Buffers[NUM_SQUARE_BUFFERS];
	//---------------------------------------------------------

	//---------------------------------------------------------
	// Vertex Attributes
	//---------------------------------------------------------
	enum { vPosition, vColor };
	//---------------------------------------------------------
};

