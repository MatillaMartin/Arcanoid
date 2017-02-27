#version 150

uniform sampler2D tileTexture;
in vec2 texCoordVarying;
out vec4 outputColor;
 
void main()
{
    outputColor = texture2D(tileTexture, texCoordVarying);
}