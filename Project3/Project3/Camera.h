#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>
#include <math.h>

#include "LoadShaders.h"
#include "vgl.h"
#include "Cube.h"
#include "Axes.h"
#include "vmath.h"


using vmath::mat4;

class Camera
{
public:
	Camera();
	~Camera();

	void camUp(float);
	void camDown(float);
	void camLeft(float);
	void camRight(float);
	void init();
	void update();
	void reverse();

	mat4 view;
	mat4 frustum;
	vmath::vec3 eye;

private:

	float eye_x;
	float eye_y;
	float eye_z;

	vmath::vec3 center;
	vmath::vec3 up;

	
};

