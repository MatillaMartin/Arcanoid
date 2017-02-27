#version 150

// these are for the programmable pipeline system
uniform mat4 modelViewProjectionMatrix;

uniform vec2 tileDisplacement;

in vec4 position;

void main()
{	
    vec4 modifiedPosition = modelViewProjectionMatrix * position;
	modifiedPosition += tileDisplacement;
	gl_Position = modifiedPosition;
}