#version 330 core

uniform mat4 projection;
uniform mat4 view;
//uniform mat3 NormalMatrix;

layout(location = 0) in vec4 inPosition;
layout(location = 1) in vec4 inColor;
layout(location = 2) in vec2 inTexCoord;
layout(location = 3) in int inIsTextured;
layout(location = 4) in int isTrans;		// if the object is allowed to translate
layout(location = 5) in mat4 model;			// the model translation
layout(location = 9) in vec3 inNormal;
layout(location = 10) in mat3 NormalMatrix;


out vec4 vertColor;
out vec2 vertTexCoord;
flat out int vertIsTextured;

out vec3 Normal;

void main()
{
	
	if(isTrans == 1)
	{
		gl_Position = projection * view * model * inPosition;
	}
	else
	{
		gl_Position = projection * view * inPosition;
	}

	vertColor = inColor;
	vertTexCoord = inTexCoord;
	vertIsTextured = inIsTextured;
	Normal = normalize(NormalMatrix * inNormal);
}