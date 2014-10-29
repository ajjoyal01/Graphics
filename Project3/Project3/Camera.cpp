#include "Camera.h"


Camera::Camera()
{
	
}


Camera::~Camera()
{
}

void Camera::camUp(float move)
{
	eye_y += move;
	update();
}

void Camera::camDown(float move)
{
	eye_y -= move;
	update();
}

void Camera::camLeft(float move)
{
	eye_x -= move;
	update();
}

void Camera::camRight(float move)
{
	eye_x += move;
	update();
}

void Camera::init()
{
	eye_x = -.4;
	eye_y = .4;
	eye_z = 1;

	eye = vmath::vec3(eye_x, eye_y, eye_z);
	center = vmath::vec3(0, 0, 0);
	up = vmath::vec3(0, 1, 0);

	view = vmath::lookat(eye, center, up);
	//view = vmath::translate((float)0, (float)0, (float)0) * view;

	frustum = vmath::frustum(-.3, .3, -.3, .3, 0.3, 10);
}

void Camera::update()
{
	eye = vmath::vec3(eye_x, eye_y, eye_z);
	view = vmath::lookat(eye, center, up);
	//view = vmath::translate((float)0, (float)0, (float)0) * view;
}

void Camera::reverse()
{
	eye_z = -eye_z;
	eye_x = -eye_x;

	/*
	vmath::mat4 cam_rotate = vmath::rotate((float)180, (float)0, (float)1, (float)0);

	eye_x = cam_rotate[3][0];
	eye_y = cam_rotate[3][1];
	eye_z = cam_rotate[3][2];
	*/
	update();
}