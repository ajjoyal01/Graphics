#include "World.h"

World::World()
{
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		shape[i] = new Cube();
	}

	axes = new Axes();

	curShape = 0;

	srand(time(NULL));
}

World::~World()
{
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		delete shape[i];
	}
	for (int i = 0; i < 6; i++)
	{
		delete _textures[i];
	}
	
	delete axes;
}

void World::init()
{
	initValues();
	cam.init();

	_shader.init();
	setupTextures(); 
	
	// Antialiasing
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);

	glLineWidth(4);

	glEnable(GL_DEPTH_TEST);

	// update the currently selected cube
	updateSelected();

	randomTexture(0);
	randomTexture(1);
	randomTexture(2);
}

void World::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	draw();

	// swap the buffers at the end of the display sequence
	glutSwapBuffers();
}

void World::keyPress(unsigned char key,int x,int y)
{
	int selectedTexture = 0;
	switch (key)
	{
	case 'm':
	case 'M':
		updateSelected();
		break;
	case 'b':
	case 'B':
		shape[curShape]->scale(SCALE_UP);
		break;
	case 'n':
	case 'N':
		shape[curShape]->scale(SCALE_DOWN);
		break;
	case 'c':
	case 'C':
		// rotate clockwise along axis of view
		shape[curShape]->rotate(ROTATION, cam.eye);
		break;
	case 'v':
	case 'V':
		// rotate counterclockwise
		shape[curShape]->rotate(-ROTATION, cam.eye);
		break;
	case 'w':
	case 'W':
		// translate up
		shape[curShape]->translate(0, TRANSLATE_DIST, 0);
		break;
	case 'a':
	case 'A':
		// translate left
		shape[curShape]->translate(0 - TRANSLATE_DIST, 0, 0);
		break;
	case 's':
	case 'S':
		// translate down
		shape[curShape]->translate(0, 0 - TRANSLATE_DIST, 0);
		break;
	case 'd':
	case 'D':
		// translate right
		shape[curShape]->translate(TRANSLATE_DIST, 0, 0);
		break;
	case 'i':
	case 'I':
		// translate in
		shape[curShape]->translate(0, 0, 0 - TRANSLATE_DIST);
		break;
	case 'o':
	case 'O':
		// translate out
		shape[curShape]->translate(0, 0, TRANSLATE_DIST);
		break;
	case 't':
	case 'T':
		// random textures on 3 shapes		
		randomTexture(0);
		randomTexture(1);
		randomTexture(2);
		break;
	case 'r':
	case 'R':
		// reverse shapes
		cam.reverse();
		break;
	case 'l':
	case 'L':
		// turn directional lighting on and off
		_light.toggle();
		glutPostRedisplay();
		break;
	default:
		break;
	}

	glutPostRedisplay();
}

void World::arrowInput(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		//move camera up, look at center of scene
		cam.camUp(CAM_DIST);
		break;
	case GLUT_KEY_DOWN:
		//move camera down, look at center of scene
		cam.camDown(CAM_DIST);
		break;
	case GLUT_KEY_LEFT:
		//move camera left, look at center of scene
		cam.camLeft(CAM_DIST);
		break;
	case GLUT_KEY_RIGHT:
		//move camera right, look at center of scene
		cam.camRight(CAM_DIST);
		break;
	}

	glutPostRedisplay();
}

void World::draw()
{

	_light.draw(_shader);
	
	glUniformMatrix4fv(_shader.getUniformLocation("projection"), 1, GL_FALSE, cam.frustum);
	glUniformMatrix4fv(_shader.getUniformLocation("view"), 1, GL_FALSE, cam.view);

	axes->draw(_shader);

	// draw all three shapes
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		shape[i]->draw(_shader);
	}
}

void World::initValues()
{

	Color color;
	color.red = 0.7;
	color.green = 1.0;
	color.blue = 0.1;
	Color ambient;
	ambient.red = 0.7;
	ambient.green = 0.7;
	ambient.blue = 1.0;


	_light.setColor(color);
	_light.setAmbient(ambient);
	_light.setDirection(1.0, 0.5, 2.0);
	_light.setShininess(3.0);
	_light.setStrength(5.0);



	//----------------------------------------------------------
	// Data for Axes
	//----------------------------------------------------------
	vec4 axesPosition[NUM_AXES][2] = {
		{ vec4(-1.0, 0.0, 0.0, 1.0), vec4(1.0, 0.0, 0.0, 1.0) },
		{ vec4(0.0, -1.0, 0.0, 1.0), vec4(0.0, 1.0, 0.0, 1.0) },
		{ vec4(0.0, 0.0, -1.0, 1.0), vec4(0.0, 0.0, 1.0, 1.0) }
	};

	// cube color
	Color cubesColor = { 1.0, 0.0, 1.0, 1.0 };
	Color axesColor = { .8, .8, .8, 1 };

	// declare all 3 shapes as new Cubes
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		shape[i]->init(0.2, cubesColor);
	}

	

	axes->init(axesPosition);
	axes->setColor(axesColor);

	shape[0]->translate(.4, 0, 0);
	shape[2]->translate(-.4, 0, 0);
}

void World::setupTextures()
{
	// get the texture uniform location


	_textureFilenames[0] = "Images/BrushedMetalTexture.png";
	_textureFilenames[1] = "Images/DarkWoodTexture.png";
	_textureFilenames[2] = "Images/DieTexture.png";
	_textureFilenames[3] = "Images/LightWoodTexture.png";
	_textureFilenames[4] = "Images/MinecraftTexture.png";
	_textureFilenames[5] = "Images/RubikTexture.png";
	_textureFilenames[6] = "Images/StyrofoamTexture.png";
	_textureFilenames[7] = "Images/Lava.png";
	_textureFilenames[8] = "Images/Portal.png";
	_textureFilenames[9] = "Images/Ice.png";

	for (int i = 0; i < NUM_TEXTURES; i++)
	{
		_textures[i] = new Texture();
		_textures[i]->loadFromFile(_textureFilenames[i]);
	}
}

void World::updateSelected()
{
	shape[curShape]->deselect(_shader);
	curShape = (curShape + 1) % 3;
	shape[curShape]->select(_shader);
}

void World::randomTexture(int index)
{
	int selectedTexture;

	do
	{
		cout << "New Tex " << index << endl;
		selectedTexture = rand() % NUM_TEXTURES;
	} while (selectedTexture == shape[index]->getLastTexture());

	shape[index]->setTexture(_textures[selectedTexture]);
	shape[index]->setSelectedTexture(selectedTexture);
	_textures[selectedTexture]->load();

	glutPostRedisplay();
}