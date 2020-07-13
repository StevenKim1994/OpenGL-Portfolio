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


	vec4 c = texture(texID, texCoordV);
	vec3 grey = vec3(0.299*c.r + 0.587 * c.g + 0.114 * c.b);
	fragColor =  vec4(grey, c.a * colorV.a);	
}

