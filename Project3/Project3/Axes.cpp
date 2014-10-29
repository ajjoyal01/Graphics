#include "Axes.h"

void Axes::init(vec4 inPosition[NUM_AXES][NUM_VERTICES])
{
	// sets whether affected by transformations
	isTransformed = 0;
	setIsTextured(false);

	// initialize positions and colors (i = axis,j = vertex,k = value)
	for (int i = 0; i < NUM_AXES; i++)
	{
		for (int j = 0; j < NUM_VERTICES; j++)
		{
			_position[i][j] = inPosition[i][j];
		}
	}

	// create Vertex Array
	glGenVertexArrays(NUM_AXES_VAOS, VAOs);
	glBindVertexArray(VAOs[AXES_VERTS]);

	// create Buffer
	glGenBuffers(NUM_AXES_BUFFERS, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[AXES_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_position), _position, GL_DYNAMIC_DRAW);

	// set attrib pointer
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	
}


/*
	Sets the color of the axes.
	Pre: None
	Post: the axes color is set
*/
void Axes::setColor(Color inColor)
{
	// populate colors
	_color.red = inColor.red;
	_color.green = inColor.green;
	_color.blue = inColor.blue;
	_color.alpha = inColor.alpha;
}

void Axes::draw(Shader shader)
{
	glBindVertexArray(VAOs[AXES_VERTS]);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[AXES_BUFFER]);

	// enable vertex array attributes
	glEnableVertexAttribArray(vPosition);
	
	glVertexAttrib4fv(1, &_color.red);
	glVertexAttribI1i(4, isTransformed);
	glVertexAttribI1i(3, _isTextured);

	glDrawArrays(GL_LINES, 0, NUM_AXES * NUM_VERTICES);

}

void Axes::setIsTextured(bool isTextured)
{
	if (isTextured)
		_isTextured = 1;
	else
		_isTextured = 0;

}