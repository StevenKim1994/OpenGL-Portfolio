#version 150

#if GL_ES
precision mediump float;
#endif

uniform vec3 iResolution;
uniform float iTime;
uniform float iTimeDelta;
uniform int iFrame;
uniform vec4 iMouse;
uniform sampler2D iChannel0;
uniform sampler2D iChannel1;
uniform sampler2D iChannel2;
uniform sampler2D iChannel3;

out vec4 fragColor;

void main()
{
    vec2 fragCoord = gl_FragCoord.xy;
    vec2 uv = fragCoord.xy / iResolution.xy;
    if( uv.x < 0.5 )
    {
        if( uv.y < 0.5 )
        {
            fragColor = texture(iChannel0, uv);
        }
        else
        {
            fragColor = texture(iChannel1, uv);
        }
    }
    else
    {
        if( uv.y < 0.5 )
        {
            fragColor = texture(iChannel2, uv);
        }
        else
        {
            fragColor = texture(iChannel3, uv);
        }
    }
}

