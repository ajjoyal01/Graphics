#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <iostream>

#include "vgl.h"
#include "Object.h"
#include "Texture.h"
#include "Color.h"
#include "vec.h"

#define NUM_VERTICES 4

using namespace std;

class Square : public Object
{

public:
	Square();
	~Square();
	void draw();
	void update();
	void init(Color);
	void setTexture(Texture);

//private:

	Texture _texture;


	vec3 position[NUM_VERTICES];		// array to store vertex positions 4d
	vec2 texCoords[NUM_VERTICES];	// stores texture coords for each vertex
	Color color[NUM_VERTICES];		// stores color coords for each vertex

	//---------------------------------------------------------
	// Vertex Arrays and Buffers
	//---------------------------------------------------------
	GLuint vaoId;
	GLuint vboId;
	//---------------------------------------------------------

	//---------------------------------------------------------
	// Vertex Attributes
	//---------------------------------------------------------
	enum { vPosition, vColor, vTexCoord };
	//---------------------------------------------------------


	
};

