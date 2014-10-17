#include "World.h"


World::World()
{
	shape1 = new Cube();
	shape2 = new Cube();
	shape3 = new Cube();
}


World::~World()
{
}

void init()
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

void display()
{

	// swap the buffers at the end of the display sequence
	glutSwapBuffers();
}

void draw()
{
	shape1->draw();
	shape2->draw();
	shape3->draw();
}