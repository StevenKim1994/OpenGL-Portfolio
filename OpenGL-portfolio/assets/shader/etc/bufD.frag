#version 150

#if GL_ES
precision mediump float;
#endif

out vec4 fragColor;

void main()
{
	fragColor = vec4(1.0, 1.0, 0.0, 1.0);
}