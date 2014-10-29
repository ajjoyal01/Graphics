/*
	Cube.h
	Author: Gregory Venezia, and Andrew Joyal
	Date: 10/24/2014
	Course: CSC5210
	Description: A 3d cube
*/

#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <iostream>
#include <string>

#include "Square.h"
#include "Color.h"
#include "vec.h"
#include "Texture.h"
#include "Shader.h"
#include "vmath.h"

#define NUM_FACES 6

using namespace std;

class Cube : public Object
{

public:
	Cube();
	~Cube();
	void draw(Shader);
	void init(float,Color);

	void setTexture(Texture*);

	// **NEW SINCE COMMIT***
	void scale(float);
	void translate(float, float, float);
	void rotate(float, vmath::vec3);
	void deselect(Shader);
	void select(Shader);
	void updateCenter();
	void setSelectedTexture(int);
	int getLastTexture();

//private:

	Square* faces[NUM_FACES];	// pointers to faces (Squares)

	Texture * _texture; // the texture of this object

	vec2 normalize(vec2 value); // normalizes to uv coordinates

	void setFaceTexCoords(int face, int top, int left, int bottom, int right);
	void setFaceNormal(int face, float x, float y, float z);

	
	vec4 center;

	vmath::mat4 transform;

	int lastTexture = 0;
};

