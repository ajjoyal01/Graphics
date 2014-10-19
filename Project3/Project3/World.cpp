#include "World.h"



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

	axes->draw();
}

void World::initValues()
{
	//----------------------------------------------------------
	// Data for Axes and Cubes
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

	GLfloat cubesPosition[NUM_SHAPES][NUM_FACES][4][4] = {
		// Cube 1:
			{
				// Face 1:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } },
				// Face 2:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } },
				// Face 3:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } },
				// Face 4:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } },
				// Face 5:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } },
				// Face 6:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } }
			},
			// Cube 2:
			{
				// Face 1:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } },
				// Face 2:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } },
				// Face 3:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } },
				// Face 4:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } },
				// Face 5:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } },
				// Face 6:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } }
			},
			// Cube 3:
			{
				// Face 1:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } },
				// Face 2:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } },
				// Face 3:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } },
				// Face 4:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } },
				// Face 5:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } },
				// Face 6:
				{ { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 } }
			}
	}; // end Cube Positions

	GLfloat cubesColor[NUM_SHAPES][NUM_FACES][4];
	//----------------------------------------------------------

	axes = new Axes(axesPosition, axesColor);
}