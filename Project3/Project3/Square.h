#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>

#include "vgl.h"
#include "Object.h"
#include "Texture.h"
#include "Color.h"
#include "vec.h"

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
	void init(Color);
	void addTexture(Texture texture);

//private:

	vec3 position[NUM_VERTICES];		// array to store vertex positions 4d
	vec2 texCoords[NUM_VERTICES];	// stores texture coords for each vertex
	Color color[NUM_VERTICES];		// stores color coords for each vertex

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

