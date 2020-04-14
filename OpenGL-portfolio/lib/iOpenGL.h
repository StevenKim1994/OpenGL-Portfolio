#pragma once


#include <gl/glew.h>

#pragma comment(lib,"opengl32.lib") 
#include <Windows.h>

void setupOpenGL(bool setup, HDC hDC);
bool startGLEW();
void initOpenGL();
void reshapeOpenGL(int width, int height);

GLuint nextPot(GLuint x); // OpenGL은 2의 승수로 텍스처를 로딩하기 떄문에 2의 승수로 바꿔주는 함수

struct Texture;
Texture* createImageWithRGBA(GLubyte* rgba, GLuint width, GLuint height);

void setAntiAliasParameters(bool anti);

#define OPENGL 1