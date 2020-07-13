                                                                                                                   
#version 150
                                                         
#if GL_ES
precision mediump float;
#endif

uniform vec4 rect;
uniform float lineWidth;
uniform vec4 color;
uniform float radius;
uniform float degree;

out vec4 fragColor;

vec2 rotateCCW(vec2 p, float a)
{
	mat2 m = mat2(cos(a), sin(a),-sin(a), cos(a));

	return p * m;
}

vec2 rotateCW(vec2 p, float a)
{
	mat2 m = mat2(cos(a), -sin(a), sin(a), cos(a));
	
	return p * m;
}

float boxDist(vec2 p, vec2 size, float radius)
{
	size -= vec2(radius);
	vec2 d = abs(p)- size;

	return min(max(d.x, d.y), 0.0) + length(max(d, 0.0)) - radius;
}

void main()
{
	vec2 center = vec2(rect.x/2 + rect.z/2 , rect.y  - rect.w/2);
	float d = boxDist(gl_FragCoord.xy- center, rect.zw/2, radius);

	d = clamp(1.0-abs(d)/lineWidth, 0.0, 1.0);

	fragColor = vec4(color.rgb, color.a * d);
} 

