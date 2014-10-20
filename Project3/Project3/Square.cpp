#include "Square.h"


Square::Square(GLfloat inColor[])
{
	// populate colors
	for (int i = 0; i < NUM_VERTICES; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			color[i][j] = inColor[j];
		}
	}

	// create Vertex Array
	glGenVertexArrays(NUM_SQUARE_VAOS, VAOs);
	glBindVertexArray(VAOs[SQUARE_VERTS]);

	// create Buffer
	glGenBuffers(NUM_SQUARE_BUFFERS, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[SQUARE_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(position) + sizeof(color), NULL, GL_DYNAMIC_DRAW);	

	// set attrib pointer
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(position)));
}


Square::~Square()
{

}

void Square::update()
{
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[SQUARE_BUFFER]);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(position), position);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(position), sizeof(color), color);


}

void Square::draw()
{
	glBindVertexArray(VAOs[SQUARE_VERTS]);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[SQUARE_BUFFER]);

	// enable vertex array attributes
	glEnableVertexAttribArray(vPosition);
	glEnableVertexAttribArray(vColor);

	glDrawArrays(GL_LINE_LOOP, 0, NUM_VERTICES);
}