#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <string>

#include "vgl.h"

class Texture
{

public:
	Texture();
	~Texture();


	void loadImage(std::string filename);

private:
	GLuint _id;


};