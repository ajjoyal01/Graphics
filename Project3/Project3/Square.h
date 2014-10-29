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
#include "Shader.h"
#include "vmath.h"

#define NUM_VERTICES 4

using vmath::mat4;
using vmath::vec3;
using namespace std;

class Square : public Object
{

public:
	Square();
	~Square();
	void draw(Shader shader);
	void update();
	void init(Color);
	void setTexCoords(int, vec2);
	void updateNormal();
	void setIsTextured(bool);
	void updateNormalMat();
	
	vec4 _position[NUM_VERTICES];		// array to store vertex positions 4d
	mat4 vTransform;
	bool selected;

private:

	vec2 _texCoords[NUM_VERTICES];	// stores texture coords for each vertex
	vec3 _normal; // stores normals for lighting
	Color _color;		// stores color coords for each vertex
	GLuint _isTextured;

	//---------------------------------------------------------
	// Vertex Arrays and Buffers
	//---------------------------------------------------------
	GLuint vaoId;
	GLuint vboId;
	//---------------------------------------------------------

	//---------------------------------------------------------
	// Vertex Attributes
	//---------------------------------------------------------
	enum { vPosition, vColor, vTexCoord, vIsTextured };
	//---------------------------------------------------------

	
	vmath::matNM<float, 3, 3> nTransform;
	
	GLuint isTransformed;
};

