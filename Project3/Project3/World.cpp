#include "World.h"

World::World()
{
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		shape[i] = new Cube();
	}

	axes = new Axes();
}

World::~World()
{
}

void World::init()
{
	initValues();

	// load shader info
	ShaderInfo shaders[] = {
			{ GL_VERTEX_SHADER, "project3.vert" },
			{ GL_FRAGMENT_SHADER, "project3.frag" },
			{ GL_NONE, NULL },
	};

	// set shader program
	GLuint program = LoadShaders(shaders);
	glUseProgram(program);

	
}

void World::display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	draw();

	// swap the buffers at the end of the display sequence
	glutSwapBuffers();
}

void World::draw()
{
	/*
	// draw all three shapes
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		shape[i]->draw();
	}*/

	axes->draw();
	shape[0]->draw();
}

void World::initValues()
{
	//----------------------------------------------------------
	// Data for Axes
	//----------------------------------------------------------
	GLfloat axesPosition[NUM_AXES][2][4] = {
			{ { -1.0, 0.0, 0.0, 1.0 }, { 1.0, 0.0, 0.0, 1.0 } },
			{ { 0.0, -1.0, 0.0, 1.0 }, { 0.0, 1.0, 0.0, 1.0 } },
			{ { 0.0, 0.0, -1.0, 1.0 }, { 0.0, 0.0, 1.0, 1.0 } }
	};

	GLfloat axesColor[NUM_AXES][2][4] = {
			{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } },
			{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } },
			{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } }
	};
	//----------------------------------------------------------
	
	

	Color cubesColor = { 1.0, 0.0, 1.0, 1.0 };

	/*
	// declare all 3 shapes as new Cubes
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		shape[i] = new Cube(0.2);
	}*/

	shape[0]->init(0.2,cubesColor);
	axes->init(axesPosition, axesColor);
}