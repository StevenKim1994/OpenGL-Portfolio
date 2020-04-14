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

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_ALWAYS);

	glClearDepth(1.0f);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glEnable(GL_SMOOTH);
}

void reshapeOpenGL(int width, int height)
{
}

GLuint nextPot(GLuint x)
{
 //#bug
	return 0;
}

Texture* createImageWithRGBA(GLubyte* rgba, GLuint width, GLuint height)
{
//#bug
	return 0;
}

void setAntiAliasParameters(bool anti)
{
}
