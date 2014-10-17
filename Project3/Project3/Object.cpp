#include "Object.h"


Object::Object()
{
	numVertices = 0;
}


Object::~Object()
{
}

void Object::setNumVertices(int vertices)
{
	numVertices = vertices;
}

int Object::getNumVertices()
{
	return numVertices;
}