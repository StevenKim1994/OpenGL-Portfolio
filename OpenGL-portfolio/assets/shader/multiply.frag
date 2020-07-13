#version 150

#if GL_ES

precision mediump float;

#endif


in vec2 texCoordV;
in vec4 colorV;


// uniform == only one in
uniform vec2 resolution;

out vec4 fragColor;

void main()
{
	vec4 c = vec4(255,255,0,255);
	///float grey = 0.299*c.r + 0.578 * c.g + 0.114 * c.b;
	//fragColor = vec4(grey, grey, grey, c.a);
	//fragColor = c.yzzw;

	fragColor = c;
	//fragColor = vec4(1.);
}

