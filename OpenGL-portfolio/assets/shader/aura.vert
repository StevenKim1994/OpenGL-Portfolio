#version 150

#if GL_ES

precision mediump float;

#endif



in vec4 position;

void main()
{
	gl_Position = position; 
}

