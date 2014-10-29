#include "Cube.h"

Cube::Cube() : _texture(nullptr)
{
	for (int i = 0; i < NUM_FACES; i++)
	{
		faces[i] = new Square();
	}
}

Cube::~Cube()
{
	for (int i = 0; i < NUM_FACES; i++)
	{
		delete faces[i];
	}
}


void Cube::setTexture(Texture * texture)
{
	_texture = texture;
}

void Cube::init(float sideLength, Color inColor)
{
	transform = mat4::identity();

	for (int i = 0; i < NUM_FACES; i++)
	{
		faces[i]->init(inColor);
	}

	// calculate pos and neg value and center square on origin
	float pos = sideLength / 2;
	float neg = pos * -1;

	// the following takes the input value and generates a cube centered at the origin
	// ----------------------
	// face 1:
	// ----------------------
	faces[0]->_position[0] = vec4(neg, pos, neg, 1.0);
	faces[0]->_position[1] = vec4(neg, neg, neg, 1.0);
	faces[0]->_position[2] = vec4(pos, neg, neg, 1.0);
	faces[0]->_position[3] = vec4(pos, pos, neg, 1.0);

	setFaceTexCoords(0, 300, 300, 600, 600);
	setFaceNormal(0, 1.0, 1.0, 1.0);

	// ----------------------
	// face 2: 
	// ----------------------
	faces[1]->_position[0] = vec4(pos, pos, neg, 1.0);
	faces[1]->_position[1] = vec4(pos, neg, neg, 1.0);
	faces[1]->_position[2] = vec4(pos, neg, pos, 1.0);
	faces[1]->_position[3] = vec4(pos, pos, pos, 1.0);

	setFaceTexCoords(1, 600, 300, 900, 600);
	setFaceNormal(1, 1.0, 1.0, 1.0);

	// ----------------------
	// face 3:
	// ----------------------
	faces[2]->_position[0] = vec4(pos, pos, pos, 1.0);
	faces[2]->_position[1] = vec4(pos, neg, pos, 1.0);
	faces[2]->_position[2] = vec4(neg, neg, pos, 1.0);
	faces[2]->_position[3] = vec4(neg, pos, pos, 1.0);

	setFaceTexCoords(2, 900, 300, 1200, 600);
	setFaceNormal(2, 1.0, 2.0, 2.0);

	// ----------------------
	// face 4:
	//-----------------------
	faces[3]->_position[0] = vec4(neg, pos, pos, 1.0);
	faces[3]->_position[1] = vec4(neg, neg, pos, 1.0);
	faces[3]->_position[2] = vec4(neg, neg, neg, 1.0);
	faces[3]->_position[3] = vec4(neg, pos, neg, 1.0);

	setFaceTexCoords(3, 0, 300, 300, 600);
	setFaceNormal(3, 1.0, 4.0, 0.5);

	// ----------------------
	// face 5:
	// ----------------------
	faces[4]->_position[0] = vec4(neg, pos, pos, 1.0);
	faces[4]->_position[1] = vec4(neg, pos, neg, 1.0);
	faces[4]->_position[2] = vec4(pos, pos, neg, 1.0);
	faces[4]->_position[3] = vec4(pos, pos, pos, 1.0);

	setFaceTexCoords(4, 300, 0, 600, 300);
	setFaceNormal(4, 1.0, 0.5, 1.0);

	// ----------------------
	// face 6:
	// ----------------------
	faces[5]->_position[0] = vec4(neg, neg, neg, 1.0);
	faces[5]->_position[1] = vec4(neg, neg, pos, 1.0);
	faces[5]->_position[2] = vec4(pos, neg, pos, 1.0);
	faces[5]->_position[3] = vec4(pos, neg, neg, 1.0);

	setFaceTexCoords(5, 300, 600, 600, 900);
	setFaceNormal(5, 1.0, 0.5, 0.5);

	center = vec4(0.0, 0.0, 0.0, 1.0);

	for (int i = 0; i < NUM_FACES; i++)
	{
		faces[i]->update();
	}
}

void Cube::draw(Shader shader)
{
	if (_texture != nullptr)
		_texture->activate(shader.getUniformLocation("tex"));

	for (int i = 0; i < NUM_FACES; i++)
	{
		faces[i]->draw(shader);
	}

	if (_texture != nullptr)
		_texture->deactivate();
}

vec2 Cube::normalize(vec2 point)
{
	float textureWidth = 1200;
	float textureHeight = 900;
	return vec2(point.x / textureWidth, point.y / textureHeight);
}

void Cube::setFaceTexCoords(int face, int top, int left, int bottom, int right)
{
	faces[face]->setTexCoords(0, normalize(vec2(top, left))); // top left
	faces[face]->setTexCoords(1, normalize(vec2(top, right))); 
	faces[face]->setTexCoords(2, normalize(vec2(bottom, right)));// bottom right
	faces[face]->setTexCoords(3, normalize(vec2(bottom, left))); 
}

void Cube::setFaceNormal(int face, float x, float y, float z)
{
	faces[face]->updateNormal(); // top left
}

// **NEW SINCE COMMIT**
void Cube::scale(float scaleFactor)
{
	// Translate to center
	vmath::mat4 translate1 = vmath::translate(0 - center.x, 0 - center.y, 0 - center.z);
	vmath::mat4 scale = vmath::scale(scaleFactor);
	vmath::mat4 translate2 = vmath::translate(center.x, center.y, center.z);

	transform = (translate2 * scale * translate1) * transform;
	updateCenter();

	for (int i = 0; i < NUM_FACES; i++)
	{
		faces[i]->vTransform = transform;
		faces[i]->updateNormalMat();
	}

}

void Cube::translate(float x, float y, float z)
{
	vmath::mat4 translate = vmath::translate(x, y, z);

	transform = translate * transform;
	updateCenter();

	for (int i = 0; i < NUM_FACES; i++)
	{
		faces[i]->vTransform = transform;
		faces[i]->updateNormalMat();
	}
}

void Cube::rotate(float angle, vmath::vec3 inAxis)
{
	// Translate to center
	vmath::mat4 translate1 = vmath::translate(0 - center.x, 0 - center.y, 0 - center.z);
	vmath::mat4 rotate = vmath::rotate(angle, inAxis);
	vmath::mat4 translate2 = vmath::translate(center.x, center.y, center.z);

	transform = (translate2 * rotate * translate1) * transform;
	updateCenter();

	for (int i = 0; i < NUM_FACES; i++)
	{
		faces[i]->vTransform = transform;
		faces[i]->updateNormalMat();
	}
}

void Cube::deselect(Shader shader)
{
	for (int i = 0; i < NUM_FACES; i++)
	{
		faces[i]->selected = false;
	}

	draw(shader);
}

void Cube::select(Shader shader)
{
	for (int i = 0; i < NUM_FACES; i++)
	{
		faces[i]->selected = true;
	}

	draw(shader);
}

void Cube::updateCenter()
{
	center.x = transform[3][0];
	center.y = transform[3][1];
	center.z = transform[3][2];

	//cout << "( " << center.x << ", " << center.y << ", " << center.z << " )\n";
}

void Cube::setSelectedTexture(int texture)
{
	lastTexture = texture;
}

int Cube::getLastTexture()
{
	return lastTexture;
}