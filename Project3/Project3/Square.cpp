#include "Square.h"

Square::Square() :
	vaoId(0),
	vboId(0),
	selected(false),
	isTransformed(1)
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
	glBindVertexArray(vaoId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(_position), _position);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(_position), sizeof(_texCoords), _texCoords);
}

void Square::draw(Shader shader)
{
	glBindVertexArray(vaoId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);

	// enable vertex array attributes
	glEnableVertexAttribArray(vPosition);
	
	glEnableVertexAttribArray(vTexCoord);

	glVertexAttrib4fv(1, &_color.red);
	glVertexAttribI1i(3, _isTextured); 
	glVertexAttribI1i(4, isTransformed);
	glVertexAttrib4fv(5, &vTransform[0][0]);
	glVertexAttrib4fv(6, &vTransform[1][0]);
	glVertexAttrib4fv(7, &vTransform[2][0]);
	glVertexAttrib4fv(8, &vTransform[3][0]);
	updateNormal();
	glVertexAttrib4fv(9, &_normal[0]);
	glVertexAttrib4fv(10, &nTransform[0][0]);
	glVertexAttrib4fv(11, &nTransform[1][0]);
	glVertexAttrib4fv(12, &nTransform[2][0]);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDrawArrays(GL_TRIANGLE_FAN, 0, NUM_VERTICES);
	

	if (selected == true)
	{
		setIsTextured(false);
		glVertexAttribI1i(3, _isTextured);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);
		glDrawArrays(GL_LINE_LOOP, 0, NUM_VERTICES);
	}
	setIsTextured(true);

}

void Square::init(Color inColor)
{
	vTransform = mat4::identity();
	nTransform = vmath::matNM<float, 3, 3>::identity();
		
		// populate colors
	
	_color.red = inColor.red;
	_color.green = inColor.green;
	_color.blue = inColor.blue;
	_color.alpha = inColor.alpha;
	
	setIsTextured(true);

	// create Vertex Array
	if (vaoId == 0)
		glGenVertexArrays(1, &vaoId);
	glBindVertexArray(vaoId);

	// create Buffer
	if (vboId == 0)
		glGenBuffers(1, &vboId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_position) + sizeof(_texCoords), NULL, GL_DYNAMIC_DRAW);

	// set attrib pointer
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glVertexAttribPointer(vTexCoord, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(_position)));
	
}

void Square::setTexCoords(int index, vec2 texCoords)
{
	_texCoords[index] = texCoords;
}

void Square::updateNormal()
{
	vec3 point1 = vec3(_position[0].x, _position[0].y, _position[0].z);
	vec3 point2 = vec3(_position[1].x, _position[1].y, _position[1].z);
	vec3 point3 = vec3(_position[2].x, _position[2].y, _position[2].z);
	vec3 direct1 = point1 - point2;
	vec3 direct2 = point1 - point3;

	_normal = vmath::cross(direct2, direct1);

	_normal = vmath::normalize(_normal);
}

void Square::setIsTextured(bool isTextured)
{
	if (isTextured)
		_isTextured = 1;
	else
		_isTextured = 0;
	
}

void Square::updateNormalMat()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			nTransform[j][i] = vTransform[j][i];
		}
	}
}