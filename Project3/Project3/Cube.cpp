#include "Cube.h"


Cube::Cube(float sideLength, GLfloat inColor[])
{
	cout << "New Cube\n" << endl;

	for (int i = 0; i < NUM_FACES; i++)
	{
		faces[i] = new Square(inColor);
	}

	// calculate pos and neg value and center square on origin
	float pos = sideLength / 2;
	float neg = pos * -1;

	// face 1:
	faces[0]->position[0][0] = neg;
	faces[0]->position[0][1] = pos;
	faces[0]->position[0][2] = neg;
	faces[0]->position[1][0] = neg;
	faces[0]->position[1][1] = neg;
	faces[0]->position[1][2] = neg;
	faces[0]->position[2][0] = pos;
	faces[0]->position[2][1] = neg;
	faces[0]->position[2][2] = neg;
	faces[0]->position[3][0] = pos;
	faces[0]->position[3][1] = pos;
	faces[0]->position[3][2] = neg;

	// face 2:
	faces[1]->position[0][0] = pos;
	faces[1]->position[0][1] = pos;
	faces[1]->position[0][2] = neg;
	faces[1]->position[1][0] = pos;
	faces[1]->position[1][1] = neg;
	faces[1]->position[1][2] = neg;
	faces[1]->position[2][0] = pos;
	faces[1]->position[2][1] = neg;
	faces[1]->position[2][2] = pos;
	faces[1]->position[3][0] = pos;
	faces[1]->position[3][1] = pos;
	faces[1]->position[3][2] = pos;

	// face 3:
	faces[2]->position[0][0] = pos;
	faces[2]->position[0][1] = pos;
	faces[2]->position[0][2] = pos;
	faces[2]->position[1][0] = pos;
	faces[2]->position[1][1] = neg;
	faces[2]->position[1][2] = pos;
	faces[2]->position[2][0] = neg;
	faces[2]->position[2][1] = neg;
	faces[2]->position[2][2] = pos;
	faces[2]->position[3][0] = neg;
	faces[2]->position[3][1] = pos;
	faces[2]->position[3][2] = pos;

	// face 4:
	faces[3]->position[0][0] = neg;
	faces[3]->position[0][1] = pos;
	faces[3]->position[0][2] = pos;
	faces[3]->position[1][0] = neg;
	faces[3]->position[1][1] = neg;
	faces[3]->position[1][2] = pos;
	faces[3]->position[2][0] = neg;
	faces[3]->position[2][1] = neg;
	faces[3]->position[2][2] = neg;
	faces[3]->position[3][0] = neg;
	faces[3]->position[3][1] = pos;
	faces[3]->position[3][2] = neg;

	// face 5:
	faces[4]->position[0][0] = neg;
	faces[4]->position[0][1] = pos;
	faces[4]->position[0][2] = pos;
	faces[4]->position[1][0] = neg;
	faces[4]->position[1][1] = pos;
	faces[4]->position[1][2] = neg;
	faces[4]->position[2][0] = pos;
	faces[4]->position[2][1] = pos;
	faces[4]->position[2][2] = neg;
	faces[4]->position[3][0] = pos;
	faces[4]->position[3][1] = pos;
	faces[4]->position[3][2] = pos;

	// face 6:
	faces[5]->position[0][0] = neg;
	faces[5]->position[0][1] = neg;
	faces[5]->position[0][2] = neg;
	faces[5]->position[1][0] = neg;
	faces[5]->position[1][1] = neg;
	faces[5]->position[1][2] = pos;
	faces[5]->position[2][0] = pos;
	faces[5]->position[2][1] = neg;
	faces[5]->position[2][2] = pos;
	faces[5]->position[3][0] = pos;
	faces[5]->position[3][1] = neg;
	faces[5]->position[3][2] = neg;

	// set w value for all faces points to 1, update faces
	for (int i = 0; i < NUM_FACES; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			faces[i]->position[j][4] = 1.0;
		}

		faces[i]->update();
	}

}


Cube::~Cube()
{

}

void Cube::draw()
{
	for (int i = 0; i < NUM_FACES; i++)
	{
		faces[i]->draw();
	}
}