#version 150

#if GL_ES

precision mediump float;

#endif

uniform mat4 mProjection, mModelview;

in vec4 position;


void main()
{

	gl_Position = position; 
	

}

