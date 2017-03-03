#version 150

uniform sampler2D texture;
in vec2 texCoordVarying;
out vec4 outputColor;
 
void main()
{
	//outputColor = vec4(texCoordVarying.x, texCoordVarying.y, 0, 1);
    outputColor = texture2D(texture, texCoordVarying);
}