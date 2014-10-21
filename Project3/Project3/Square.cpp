#include "Square.h"

Square::Square() :
	vaoId(0),
	vboId(0)
{

}



Square::~Square()
{
	if (vaoId != 0)
		glDeleteBuffers(1, &vaoId);
	if (vboId != 0)
		glDeleteVertexArrays(1, &vboId);

}

void Square::update()
{
	glBindBuffer(GL_ARRAY_BUFFER, vaoId);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(position), position);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(position), sizeof(color), color);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(position) + sizeof(color), sizeof(texCoords), texCoords);
}

void Square::draw()
{
	
	glBindVertexArray(vaoId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);

	// enable vertex array attributes
	glEnableVertexAttribArray(vPosition);
	glEnableVertexAttribArray(vColor);
	glEnableVertexAttribArray(vTexCoord);

	glDrawArrays(GL_TRIANGLE_FAN, 0, NUM_VERTICES);
}

void Square::init(Color inColor)
{
	// populate colors
	for (int i = 0; i < NUM_VERTICES; i++)
	{
		color[i].red = inColor.red;
		color[i].green = inColor.green;
		color[i].blue = inColor.blue;
		color[i].alpha = inColor.alpha;
	}

	// create Vertex Array
	if (vaoId == 0)
		glGenVertexArrays(1, &vaoId);
	glBindVertexArray(vaoId);

	// create Buffer
	if (vboId == 0)
		glGenBuffers(1, &vboId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(position) + sizeof(color) + sizeof(texCoords), NULL, GL_DYNAMIC_DRAW);

	// set attrib pointer
	glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glVertexAttribPointer(vColor, 4, GL_UNSIGNED_BYTE, GL_TRUE, 0, BUFFER_OFFSET(sizeof(position)));
	glVertexAttribPointer(vTexCoord, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(position) + sizeof(color)));
}