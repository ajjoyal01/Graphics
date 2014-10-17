#include "World.h"

//----------------------------------------------------------
// Global variables
//----------------------------------------------------------
GLfloat axesPosition[NUM_AXES][2][4] = {
		{ { -1.0, 0.0, 0.0, 1.0 }, { 1.0, 0.0, 0.0, 1.0 } },	
		{ { 0.0, -1.0, 0.0, 1.0 }, { 0.0, 1.0, 0.0, 1.0 } },
		{ { 0.0, 0.0, -1.0, 1.0 }, { 0.0, 0.0, 1.0, 1.0 } }
};
GLfloat axesColor[NUM_AXES][2][4];

GLfloat cubesPosition[NUM_SHAPES][NUM_FACES][4];
GLfloat cubesColor[NUM_SHAPES][NUM_FACES][4];
//----------------------------------------------------------

World::World()
{
	// declare all 3 shapes as new Cubes
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		shape[i] = new Cube();
	}

	// call to store values of all objects
	initValues();

}

World::~World()
{
}

void World::init()
{
	// load shader info
	ShaderInfo shaders[] = {
			{ GL_VERTEX_SHADER, "project2.vert" },
			{ GL_FRAGMENT_SHADER, "project2.frag" },
			{ GL_NONE, NULL },
	};

	// set shader program
	GLuint program = LoadShaders(shaders);
	glUseProgram(program);
}

void World::display()
{

	// swap the buffers at the end of the display sequence
	glutSwapBuffers();
}

void World::draw()
{
	// draw all three shapes
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		shape[i]->draw();
	}
}

void World::initValues()
{
	axesPosition 


}