#include "World.h"

World::World()
{
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		shape[i] = new Cube();
	}

	axes = new Axes();

	setupTextures();
	
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

void World::keyPress(unsigned char key,int x,int y)
{
	/*
	switch (key)
	{
	case 'b':
		shape[curShape]->scale(1.25);
		break;
	case 'n':
		shape[curShape]->scale(0.8);
		break;
	case 'c':
		// rotate clockwise along axis of view
		break;
	case 'v':
		// rotate counterclockwise 
		break;
	case 'w':
		// translate up
		break;
	case 'a':
		// translate left
		break;
	case 's':
		// translate down
		break;
	case 'd':
		// translate right
		break;


	case 't':
		// random textures on 3 shapes
		break;
	case 'r':
		// reverse textures
		break;

	}
	*/
}

void World::arrowInput(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		//move camera up, look at center of scene
		break;
	case GLUT_KEY_DOWN:
		//move camera down, look at center of scene
		break;
	case GLUT_KEY_LEFT:
		//move camera left, look at center of scene
		break;
	case GLUT_KEY_RIGHT:
		//move camera right, look at center of scene
		break;
	}
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
			{ { 255, 255, 255, 255 }, { 255, 255, 255, 255 } },
			{ { 255, 255, 255, 255 }, { 255, 255, 255, 255 } },
			{ { 255, 255, 255, 255 }, { 255, 255, 255, 255 } }
	};
	//----------------------------------------------------------
	
	// cube color
	Color cubesColor = { 255, 255, 0, 255 }; // yellow

	/*
	// declare all 3 shapes as new Cubes
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		shape[i] = new Cube(0.2);
	}*/

	shape[0]->init(0.2,cubesColor);
	axes->init(axesPosition, axesColor);
}

void World::setupTextures()
{
	// generate textures
	glGenTextures(NUM_TEXTURES, Textures);
}