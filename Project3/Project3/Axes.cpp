#include "Axes.h"

Axes::Axes()
{
}

Axes::Axes(GLfloat inPosition[NUM_AXES][NUM_VERTICES][DIMENTIONS], GLfloat inColor[NUM_AXES][NUM_VERTICES][DIMENTIONS])
{
	// initialize positions and colors (i = axis,j = vertex,k = value)
	for (int i = 0; i < NUM_AXES;i++)
	{
		for (int j = 0; j < NUM_VERTICES; j++)
		{
			for (int k = 0; k < DIMENTIONS;k++)
			{
				position[i][j][k] = inPosition[i][j][k];
				color[i][j][k] = inColor[i][j][k];
			}
		}
	}

	// create Vertex Array
	glGenVertexArrays(NUM_AXES_VAOS,VAOs);
	glBindVertexArray(VAOs[AXES_VERTS]);

	// create Buffer
	glGenBuffers(NUM_AXES_BUFFERS, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[AXES_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(position) + sizeof(color), NULL, GL_DYNAMIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(position), position);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(position), sizeof(color), color);

	// set attrib pointer
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(position)));
}

Axes::~Axes()
{
}

void Axes::init(GLfloat inPosition[NUM_AXES][NUM_VERTICES][DIMENTIONS], GLfloat inColor[NUM_AXES][NUM_VERTICES][DIMENTIONS])
{
	// initialize positions and colors (i = axis,j = vertex,k = value)
	for (int i = 0; i < NUM_AXES; i++)
	{
		for (int j = 0; j < NUM_VERTICES; j++)
		{
			for (int k = 0; k < DIMENTIONS; k++)
			{
				position[i][j][k] = inPosition[i][j][k];
				color[i][j][k] = inColor[i][j][k];
			}
		}
	}

	// create Vertex Array
	glGenVertexArrays(NUM_AXES_VAOS, VAOs);
	glBindVertexArray(VAOs[AXES_VERTS]);

	// create Buffer
	glGenBuffers(NUM_AXES_BUFFERS, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[AXES_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(position) + sizeof(color), NULL, GL_DYNAMIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(position), position);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(position), sizeof(color), color);

	// set attrib pointer
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(position)));
}

void Axes::draw()
{
	glBindVertexArray(VAOs[AXES_VERTS]);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[AXES_BUFFER]);

	// enable vertex array attributes
	glEnableVertexAttribArray(vPosition);
	glEnableVertexAttribArray(vColor);

	glDrawArrays(GL_LINES, 0, NUM_AXES * NUM_VERTICES);
}