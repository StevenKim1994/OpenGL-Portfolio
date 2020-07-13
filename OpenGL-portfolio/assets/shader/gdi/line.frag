#version 150

#if GL_ES
precision mediump float;
#endif

uniform vec2 sp, ep;
uniform float lineWidth;
uniform vec4 color;

out vec4 fragColor;

float drawLine(vec2 p, vec2 sp, vec2 ep, float width)
{
    vec2 n = ep - sp;
    float len = length(n); // sqrt(n.x*n.x + n.y*n.y);
    n /= len;
        
    vec2 m = p - sp;
   	//vec2 proj = n * clamp( dot(m,n), 0,0, len);
    vec2 proj = n * max(0.0, min(dot(m,n), len));
    return length(m-proj) - width/2.0;
}


void main()
{
    float d = drawLine(gl_FragCoord.xy, sp, ep, lineWidth);
    //float a = clamp(-d, 0.0, 1.0);
    //d = d / (lineWidth /2);
    //
    float a = clamp(-d, 0.0, 1.0);
    //a = a * a * a;

    fragColor = vec4(color.rgb, color.a * a);
   // fragColor = vec4(color.rgb, color.a * d);
    //fragColor = vec4(1.);
}