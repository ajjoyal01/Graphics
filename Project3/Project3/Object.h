#pragma once

#include "Shader.h"

class Object
{
public:
	Object();
	~Object();
	void virtual draw(Shader shader) = 0;	// function to be overwritten in sub-classes

	void setNumVertices(int);
	int getNumVertices();

private:

	int numVertices;
};

