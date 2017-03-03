#version 150

// these are for the programmable pipeline system
uniform mat4 modelViewProjectionMatrix;

uniform vec2 pos;
uniform vec2 size;

in vec4 position;
in vec2 texcoord;

out vec2 texCoordVarying;

void main()
{	
	// send texture
	texCoordVarying = texcoord;

	vec4 modifiedPosition = position;
	// scale
	modifiedPosition.x *= size.x;
	modifiedPosition.y *= size.y;
	// translate
	modifiedPosition.xy += pos;

    modifiedPosition = modelViewProjectionMatrix * modifiedPosition;
	gl_Position = modifiedPosition;
}