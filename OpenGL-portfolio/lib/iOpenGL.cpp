#pragma once
#include "iOpenGL.h"

HGLRC hRC;
void setupOpenGL(bool setup, HDC hDC)
{
	//OpenGL 초기화 부분 플랫폼마다 다름
	if(setup)
	{
		PIXELFORMATDESCRIPTOR pfd;
		memset(&pfd, 0x00, sizeof(PIXELFORMATDESCRIPTOR));

		pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		pfd.nVersion = 1;
		pfd.iPixelType = PFD_TYPE_RGBA;
		pfd.cColorBits = 32;
		pfd.cDepthBits = 32;
		pfd.iLayerType = PFD_MAIN_PLANE;
		pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;

		int pixelFormat = ChoosePixelFormat(hDC, &pfd);
		SetPixelFormat(hDC, pixelFormat, &pfd);

		hRC = wglCreateContext(hDC);
		wglMakeCurrent(hDC, hRC);
		
	}
	else
	{
		//OpenGL 프로그램 종료 되었을때 destory 부분

		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(hRC);
	}
	
}

bool startGLEW()
{
	glewExperimental = true;

	GLenum error = glewInit();

	if (error != GLEW_OK)
		return false;

	return true;
}

void initOpenGL()
{
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	// GL_MODULATE / GL_BLEND_SRC
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND_SRC);



	glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LEQUAL); 
	glDepthFunc(GL_ALWAYS);
	glClearDepth(1.0f);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_SMOOTH);
}

#include "iStd.h"
void reshapeOpenGL(int width, int height)
{
	float r0 = devSize.width / devSize.height;

	monitorSizeW = width;
	monitorSizeH = height;
	float r1 = 1.0f * width / height;

	if (r0 < r1)// 모니터 가로가 큰 경우
	{
		viewport.origin.y = 0; viewport.size.height = height;
		viewport.size.width = devSize.width * height / devSize.height;
		viewport.origin.x = (width - viewport.size.width) / 2;
	}
	else if (r0 > r1)// 모니터 가로가 작은 경우(세로 긴 경우)
	{
		viewport.origin.x = 0; viewport.size.width = width;
		viewport.size.height = devSize.height * width / devSize.width;
		viewport.origin.y = (height - viewport.size.height) / 2;
	}
	else// 정비율
	{
		viewport = iRectMake(0, 0, width, height);
	}

	glViewport(viewport.origin.x, viewport.origin.y, viewport.size.width, viewport.size.height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, devSize.width, devSize.height, 0, -1000, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

GLuint nextPot(GLuint x)
{
	x = x - 1;
	x = x | (x >> 1);
	x = x | (x >> 2);
	x = x | (x >> 4);
	x = x | (x >> 8);
	x = x | (x >> 16);
	return x + 1;
}

Texture* createImageWithRGBA(GLubyte* rgba, GLuint width, GLuint height)
{
//#bug
	return 0;
}

void setAntiAliasParameters(bool anti)
{
}
