#include "Texture.h"

Texture::Texture()
{
	if (_id == 0)
		glGenTextures(0, &_id);



}

Texture::~Texture()
{
	if (_id != 0)
		glDeleteTextures(1, &_id);
}



// 6*3 textures are active at a time