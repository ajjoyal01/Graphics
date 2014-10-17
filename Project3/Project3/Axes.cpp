#include "Axes.h"


Axes::Axes(GLfloat inPosition[NUM_VERTICES][DIMENTIONS], GLfloat inColor[NUM_VERTICES][DIMENTIONS])
{
	// initialize positions and colors
	for (int i = 0; i < NUM_VERTICES; i++)
	{
		for (int j = 0; j < DIMENTIONS;j++)
		{
			position[i][j] = inPosition[i][j];
			color[i][j] = inColor[i][j];
		}
	}
}


Axes::~Axes()
{
}
