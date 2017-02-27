#version 150

uniform sampler2D paddleTexture;
in vec2 texCoordVarying;
out vec4 outputColor;
 
void main()
{
    outputColor = texture2D(paddleTexture, texCoordVarying);
}