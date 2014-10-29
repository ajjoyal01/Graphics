#include "Shader.h"


Shader::Shader()
{
}

Shader::~Shader()
{
}

void Shader::init()
{
	// load shader info
	ShaderInfo shaders[] = {
		{ GL_VERTEX_SHADER, "project3.vert" },
		{ GL_FRAGMENT_SHADER, "project3.frag" },
		{ GL_NONE, NULL },
	};

	// set shader program
	_id = LoadShaders(shaders);
	glUseProgram(_id);
}

void Shader::use()
{
	glUseProgram(_id);
}

void Shader::unuse()
{
	glUseProgram(0);
}

GLint Shader::getUniformLocation(std::string name)
{
	return glGetUniformLocation(_id, name.c_str());
}
