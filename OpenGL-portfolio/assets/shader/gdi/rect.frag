
#version 150
                                                         
#if GL_ES
precision mediump float;
#endif

uniform vec4 rect;
uniform vec4 color;
uniform float radius;
 

out vec4 fragColor;

float boxDist(vec2 p, vec2 size, float radius)
{
	size -= vec2(radius);
	vec2 d = abs(p)- size;

	return min(max(d.x, d.y), 0.0) + length(max(d, 0.0)) - radius;
}

void main()
{
	//vec2 center = vec2(rect.x + rect.z/2, rect.y- rect.w/2);
	vec2 center = vec2(rect.x/2 + rect.z/2 , rect.y  - rect.w/2);
	float d = boxDist(gl_FragCoord.xy- center, rect.zw/2, radius);

	if(radius == 0)
		fragColor = vec4(color);
	else
		fragColor = vec4(color.rgb, color.a * -d);
}