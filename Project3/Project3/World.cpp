#include "World.h"


World::World()
{
	// declare all 3 shapes as new Cubes
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		shape[i] = new Cube();
	}
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