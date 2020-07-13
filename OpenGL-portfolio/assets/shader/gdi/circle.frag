#version 150

#if GL_ES

precision mediump float;

#endif


// uniform == only one in
uniform vec2 center;
uniform float radius;

uniform vec4 color;
//uniform vec4 viewport;
//uniform vec2 devSize;
uniform float lineWidth;

out vec4 fragColor;

void main()
{
	float d = length(gl_FragCoord.xy - center);
	d = clamp(1.0- abs(radius-d)/lineWidth, 0.0, 1.0) ; // d = 1.0 clamp(d /radius, 0.0, 1.0);
	fragColor = vec4(color.rgb, color.a * d);
}
