#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <iostream>
// for random number generation
#include <ctime>
#include <stdlib.h>

#include "LoadShaders.h"
#include "vgl.h"
#include "Cube.h"
#include "Axes.h"
#include "Texture.h"
#include "Shader.h"
#include "TextureCache.h"
#include "vmath.h"
#include "DirectionalLight.h"
#include "Camera.h"

#define NUM_SHAPES 3
#define NUM_AXES 3
#define NUM_TEXTURES 10

#define CAM_DIST 0.02
#define SCALE_UP 1.25
#define SCALE_DOWN 0.8
#define TRANSLATE_DIST .01
#define ROTATION 1

using vmath::mat4;

static class World
{

public:

	World();
	~World();
	void init();		// initializes World
	void display();		// display function
	void keyPress(unsigned char, int, int);
	void arrowInput(int, int, int);
	void draw();		// draw function for entire World
	void initValues();	// initializes values for all objects
						// all values stored in this function, making it easy to change the values
	void setupTextures();
	void updateSelected();
	void randomTexture(int);
	

private:
	
	Cube* shape[NUM_SHAPES];	//pointer to array of shapes. 
								//more efficient to pass pointers around than whole arrays of data
	Axes* axes;		// the three axes, drawn for reference

	int curShape = 0;	// keeps track of highlighted shape
	
	Shader _shader;
	DirectionalLight _light;

	int lastTexture = 0;
	

	std::string _textureFilenames[NUM_TEXTURES];
	Texture * _textures[NUM_TEXTURES];

	Camera cam;
	GLuint program;
	vmath::matNM<float, 3, 3> normalMatrix;
	
};

