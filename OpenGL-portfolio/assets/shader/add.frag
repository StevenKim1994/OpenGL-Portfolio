#version 150

#if GL_ES

precision mediump float;

#endif


in vec2 texCoordV;
in vec4 colorV;


// uniform == only one in
uniform vec2 resolution;
uniform sampler2D texBlend;  
uniform sampler2D texBase; // backbuffer;

out vec4 fragColor;

void main()
{
	// glBlendFunc(gl_src_alpha, gl_one);

	vec2 size = textureSize(texBase, 0);
	vec2 uv = gl_FragCoord.xy / size;
	vec4 base = texture(texBase, uv);

	vec4 blend = texture(texBlend, texCoordV);

	fragColor =  vec4(base.rgb + blend.rgb * blend.a, base.a);	
}

