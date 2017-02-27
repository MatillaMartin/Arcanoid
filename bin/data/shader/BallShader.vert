#version 150

// these are for the programmable pipeline system
uniform mat4 modelViewProjectionMatrix;

uniform vec2 ballDisplacement;

in vec4 position;
in vec2 texcoord;

out vec2 texCoordVarying;

void main()
{	
	// send texture
	texCoordVarying = texcoord;

	vec4 modifiedPosition = position;
	modifiedPosition.xy += ballDisplacement;
    modifiedPosition = modelViewProjectionMatrix * modifiedPosition;
	gl_Position = modifiedPosition;
}