#version 150

#if GL_ES

precision mediump float;

#endif


in vec2 texCoordV;
in vec4 colorV;
uniform sampler2D texBlend;  
uniform sampler2D texBase; // backbuffer;


// uniform == only one in

uniform sampler2D texID;

out vec4 fragColor;

void main()
{
	vec2 size = textureSize(texBase, 0);
	vec2 uv = gl_FragCoord.xy / size;
	vec4 base = texture(texBase, uv);

	fragColor =  texture(texID, texCoordV) * colorV;	
}


