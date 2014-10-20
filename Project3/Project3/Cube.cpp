#include "Cube.h"

Cube::Cube()
{
	for (int i = 0; i < NUM_FACES; i++)
	{
		faces[i] = new Square();
	}
}

Cube::~Cube()
{

}

void Cube::init(float sideLength, Color inColor)
{
	for (int i = 0; i < NUM_FACES; i++)
	{
		faces[i]->init(inColor);
	}

	// calculate pos and neg value and center square on origin
	float pos = sideLength / 2;
	float neg = pos * -1;

	// the following takes the input value and generates a cube centered at the origin
	// face 1:
	faces[0]->position[0] = vec3(neg, pos, neg);
	faces[0]->position[1] = vec3(neg, neg, neg);
	faces[0]->position[2] = vec3(pos, neg, neg);
	faces[0]->position[3] = vec3(pos, pos, neg);

	// face 2:
	faces[1]->position[0] = vec3(pos, pos, neg);
	faces[1]->position[1] = vec3(pos, neg, neg);
	faces[1]->position[2] = vec3(pos, neg, pos);
	faces[1]->position[3] = vec3(pos, pos, pos);

	// face 3:
	faces[2]->position[0] = vec3(pos, pos, pos);
	faces[2]->position[1] = vec3(pos, neg, pos);
	faces[2]->position[2] = vec3(neg, neg, pos);
	faces[2]->position[3] = vec3(neg, pos, pos);

	// face 4:
	faces[3]->position[0] = vec3(neg, pos, pos);
	faces[3]->position[1] = vec3(neg, neg, pos);
	faces[3]->position[2] = vec3(neg, neg, neg);
	faces[3]->position[3] = vec3(neg, pos, neg);

	// face 5:
	faces[4]->position[0] = vec3(neg, pos, pos);
	faces[4]->position[1] = vec3(neg, pos, neg);
	faces[4]->position[2] = vec3(pos, pos, neg);
	faces[4]->position[3] = vec3(pos, pos, pos);

	// face 6:
	faces[5]->position[0] = vec3(neg, neg, neg);
	faces[5]->position[1] = vec3(neg, neg, pos);
	faces[5]->position[2] = vec3(pos, neg, pos);
	faces[5]->position[3] = vec3(pos, neg, neg);

	for (int i = 0; i < NUM_FACES; i++)
	{
		faces[i]->update();
	}
}

void Cube::draw()
{
	for (int i = 0; i < NUM_FACES; i++)
	{
		faces[i]->draw();
	}
}