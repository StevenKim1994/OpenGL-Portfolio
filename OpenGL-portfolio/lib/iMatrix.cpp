#include "iMatrix.h"

#include <string.h>
#include <math.h>

// ------------------------------------------
// iMatrix
// ------------------------------------------
iMatrix& iMatrix::operator = (const iMatrix& b)
{
	memcpy(&m[0][0], &b.m[0][0], sizeof(float) * 16);
	return *this;
}

const iMatrix iMatrix::operator * (const iMatrix& b)
{
	iMatrix a = (*this);
	multiply(&a, &b);
	return a;
}

const iMatrix iMatrix::operator * (iMatrix* b)
{
	iMatrix a = (*this);
	multiply(&a, b);
	return a;
}

iMatrix& iMatrix::operator *= (const iMatrix& b)
{
	multiply(this, &b);
	return *this;
}

iMatrix& iMatrix::operator *= (iMatrix* b)
{
	multiply(this, b);
	return *this;
}

void multiply(iMatrix* a, const iMatrix* b)
{
	float m[4][4];
	for (int i = 0; i < 4; i++)
	{
		m[i][0] = (a->m[i][0] * b->m[0][0]) +
			(a->m[i][1] * b->m[1][0]) +
			(a->m[i][2] * b->m[2][0]) +
			(a->m[i][3] * b->m[3][0]);
		m[i][1] = (a->m[i][0] * b->m[0][1]) +
			(a->m[i][1] * b->m[1][1]) +
			(a->m[i][2] * b->m[2][1]) +
			(a->m[i][3] * b->m[3][1]);
		m[i][2] = (a->m[i][0] * b->m[0][2]) +
			(a->m[i][1] * b->m[1][2]) +
			(a->m[i][2] * b->m[2][2]) +
			(a->m[i][3] * b->m[3][2]);
		m[i][3] = (a->m[i][0] * b->m[0][3]) +
			(a->m[i][1] * b->m[1][3]) +
			(a->m[i][2] * b->m[2][3]) +
			(a->m[i][3] * b->m[3][3]);
	}
	memcpy(&a->m[0][0], &m[0][0], sizeof(float) * 16);
}

void iMatrix::loadIdentity()
{
	memset(m, 0x00, sizeof(float) * 16);
	m[0][0] = 1.0f;
	m[1][1] = 1.0f;
	m[2][2] = 1.0f;
	m[3][3] = 1.0f;
}

void iMatrix::scale(float sx, float sy, float sz)
{
	m[0][0] *= sx;
	m[0][1] *= sx;
	m[0][2] *= sx;
	m[0][3] *= sx;

	m[1][0] *= sy;
	m[1][1] *= sy;
	m[1][2] *= sy;
	m[1][3] *= sy;

	m[2][0] *= sz;
	m[2][1] *= sz;
	m[2][2] *= sz;
	m[2][3] *= sz;
}

#ifndef M_PI
#define M_PI		3.14159265358979323846
#endif

void iMatrix::rotate(float x, float y, float z, float angle)
{
	float sinAngle, cosAngle;
	float mag = sqrtf(x * x + y * y + z * z);

	sinAngle = sinf(angle * M_PI / 180.0f);
	cosAngle = cosf(angle * M_PI / 180.0f);
	if (mag > 0.0f)
	{
		float xx, yy, zz, xy, yz, zx, xs, ys, zs;
		float oneMinusCos;
		iMatrix rotMat;
		memset(&rotMat, 0x00, sizeof(float) * 4);// 초기화

		x /= mag;
		y /= mag;
		z /= mag;

		xx = x * x;
		yy = y * y;
		zz = z * z;
		xy = x * y;
		yz = y * z;
		zx = z * x;
		xs = x * sinAngle;
		ys = y * sinAngle;
		zs = z * sinAngle;
		oneMinusCos = 1.0F - cosAngle;
#if 0	// 시계방향
		rotMat.m[0][0] = (oneMinusCos * xx) + cosAngle;
		rotMat.m[0][1] = (oneMinusCos * xy) - zs;
		rotMat.m[0][2] = (oneMinusCos * zx) + ys;
		rotMat.m[0][3] = 0.0F;

		rotMat.m[1][0] = (oneMinusCos * xy) + zs;
		rotMat.m[1][1] = (oneMinusCos * yy) + cosAngle;
		rotMat.m[1][2] = (oneMinusCos * yz) - xs;
		rotMat.m[1][3] = 0.0F;

		rotMat.m[2][0] = (oneMinusCos * zx) - ys;
		rotMat.m[2][1] = (oneMinusCos * yz) + xs;
		rotMat.m[2][2] = (oneMinusCos * zz) + cosAngle;
		rotMat.m[2][3] = 0.0F;
#else	// 반시계방향(OpenGL 방향)
		rotMat.m[0][0] = (oneMinusCos * xx) + cosAngle;
		rotMat.m[0][1] = (oneMinusCos * xy) + zs;// z
		rotMat.m[0][2] = (oneMinusCos * zx) - ys;// y
		rotMat.m[0][3] = 0.0F;

		rotMat.m[1][0] = (oneMinusCos * xy) - zs;// z
		rotMat.m[1][1] = (oneMinusCos * yy) + cosAngle;
		rotMat.m[1][2] = (oneMinusCos * yz) + xs;// x
		rotMat.m[1][3] = 0.0F;

		rotMat.m[2][0] = (oneMinusCos * zx) + ys;// y
		rotMat.m[2][1] = (oneMinusCos * yz) - xs;// x
		rotMat.m[2][2] = (oneMinusCos * zz) + cosAngle;
		rotMat.m[2][3] = 0.0F;
#endif
		rotMat.m[3][0] = 0.0F;
		rotMat.m[3][1] = 0.0F;
		rotMat.m[3][2] = 0.0F;
		rotMat.m[3][3] = 1.0F;

		rotMat *= (*this);
		memcpy(&m[0][0], &rotMat.m[0][0], sizeof(float) * 16);
	}
}

void iMatrix::translate(float tx, float ty, float tz)
{
	m[3][0] += (m[0][0] * tx + m[1][0] * ty + m[2][0] * tz);
	m[3][1] += (m[0][1] * tx + m[1][1] * ty + m[2][1] * tz);
	m[3][2] += (m[0][2] * tx + m[1][2] * ty + m[2][2] * tz);
	m[3][3] += (m[0][3] * tx + m[1][3] * ty + m[2][3] * tz);
}

// glOrthof
void iMatrix::ortho(float left, float right, float bottom, float top, float nearZ, float farZ)
{
	float		deltaX = right - left;
	float		deltaY = top - bottom;
	float		deltaZ = farZ - nearZ;

	if ((deltaX == 0.0f) || (deltaY == 0.0f) || (deltaZ == 0.0f))
		return;

	loadIdentity();
	m[0][0] = 2.0f / deltaX;
	m[3][0] = -(right + left) / deltaX;
	m[1][1] = 2.0f / deltaY;
	m[3][1] = -(top + bottom) / deltaY;
	m[2][2] = -2.0f / deltaZ;
	m[3][2] = -(nearZ + farZ) / deltaZ;
}

// glFrustumf
void iMatrix::frustum(float left, float right, float bottom, float top, float nearZ, float farZ)
{
	float	deltaX = right - left;
	float	deltaY = top - bottom;
	float	deltaZ = farZ - nearZ;
	iMatrix	frust;

	if ((nearZ <= 0.0f) || (farZ <= 0.0f) ||
		(deltaX <= 0.0f) || (deltaY <= 0.0f) || (deltaZ <= 0.0f))
		return;

	frust.m[0][0] = 2.0f * nearZ / deltaX;
	frust.m[0][1] = frust.m[0][2] = frust.m[0][3] = 0.0f;

	frust.m[1][1] = 2.0f * nearZ / deltaY;
	frust.m[1][0] = frust.m[1][2] = frust.m[1][3] = 0.0f;

	frust.m[2][0] = (right + left) / deltaX;
	frust.m[2][1] = (top + bottom) / deltaY;
	frust.m[2][2] = -(nearZ + farZ) / deltaZ;
	frust.m[2][3] = -1.0f;

	frust.m[3][2] = -2.0f * nearZ * farZ / deltaZ;
	frust.m[3][0] = frust.m[3][1] = frust.m[3][3] = 0.0f;

	//(*matrix) *= frust;
	multiply(this, &frust);
}

void iMatrix::perspective(float fovy, float aspect, float nearZ, float farZ)
{
	float frustumW, frustumH;

	frustumH = tanf(fovy / 360.0f * M_PI) * nearZ;
	frustumW = frustumH * aspect;

	frustum(-frustumW, frustumW, -frustumH, frustumH, nearZ, farZ);
}

//첫번째 xyz는 바라보는 시선의 위치
//두번째 xyz는 모델의 위치
//세번째 xyz는 모델의 top좌표(모델의 꼭대기부분이 바라보는 좌표의 위치)
void iMatrix::lookat(float eyeX, float eyeY, float eyeZ,
	float lookAtX, float lookAtY, float lookAtZ,
	float upX, float upY, float upZ)
{
	float x[3], y[3], z[3];
	float mag;

	/* Make rotation matrix */

	/* Z vector */
	z[0] = eyeX - lookAtX;
	z[1] = eyeY - lookAtY;
	z[2] = eyeZ - lookAtZ;
	mag = (float)sqrtf(z[0] * z[0] + z[1] * z[1] + z[2] * z[2]);
	if (mag) {
		z[0] /= mag;
		z[1] /= mag;
		z[2] /= mag;
	}

	/* Y vector */
	y[0] = upX;
	y[1] = upY;
	y[2] = upZ;

	/* X vector = Y cross Z */
	x[0] = y[1] * z[2] - y[2] * z[1];
	x[1] = -y[0] * z[2] + y[2] * z[0];
	x[2] = y[0] * z[1] - y[1] * z[0];

	/* Recompute Y = Z cross X */
	y[0] = z[1] * x[2] - z[2] * x[1];
	y[1] = -z[0] * x[2] + z[2] * x[0];
	y[2] = z[0] * x[1] - z[1] * x[0];

	/* cross product gives area of parallelogram, which is < 1.0 for
	 * non-perpendicular unit-length vectors; so normalize x, y here
	 */

	mag = (float)sqrtf(x[0] * x[0] + x[1] * x[1] + x[2] * x[2]);
	if (mag) {
		x[0] /= mag;
		x[1] /= mag;
		x[2] /= mag;
	}

	mag = (float)sqrtf(y[0] * y[0] + y[1] * y[1] + y[2] * y[2]);
	if (mag) {
		y[0] /= mag;
		y[1] /= mag;
		y[2] /= mag;
	}

	float m[16];
#define M(row,col)  m[col*4+row]
	M(0, 0) = x[0];
	M(0, 1) = x[1];
	M(0, 2) = x[2];
	M(0, 3) = 0.0f;
	M(1, 0) = y[0];
	M(1, 1) = y[1];
	M(1, 2) = y[2];
	M(1, 3) = 0.0f;
	M(2, 0) = z[0];
	M(2, 1) = z[1];
	M(2, 2) = z[2];
	M(2, 3) = 0.0f;
	M(3, 0) = 0.0f;
	M(3, 1) = 0.0f;
	M(3, 2) = 0.0f;
	M(3, 3) = 1.0f;
#undef M

	iMatrix fixedM;
	memcpy(&fixedM.m[0][0], m, sizeof(float) * 16);
	multiply(this, &fixedM);

	/* Translate Eye to Origin */
	translate(-eyeX, -eyeY, -eyeZ);
}

// ------------------------------------------
// iVector
// ------------------------------------------

iVector& iVector::operator = (const iVector& v)
{
	memcpy(m, &v.m, sizeof(float) * 4);
	return *this;
}

const iVector iVector::operator * (const iMatrix& a)
{
	iVector v = (*this);
	multiply(&v, &a);
	return v;
}

const iVector iVector::operator * (iMatrix* a)
{
	iVector v = (*this);
	multiply(&v, a);
	return v;
}

iVector& iVector::operator *= (const iMatrix& m)
{
	multiply(this, &m);
	return *this;
}

iVector& iVector::operator *= (iMatrix* m)
{
	multiply(this, m);
	return *this;
}

void iVector::rotate(iVector* v, float x, float y, float z, float angle)
{
	iMatrix e;
	e.loadIdentity();
	e.rotate(x, y, z, angle);

	float ix = m[0] - v->m[0];
	float iy = m[1] - v->m[1];
	float iz = m[2] - v->m[2];
	m[0] = v->m[0] + e.m[0][0] * ix + e.m[0][1] * iy + e.m[0][2] * iz;
	m[1] = v->m[1] + e.m[1][0] * ix + e.m[1][1] * iy + e.m[1][2] * iz;
	m[2] = v->m[2] + e.m[2][0] * ix + e.m[2][1] * iy + e.m[2][2] * iz;
}

void multiply(iVector* v, const iMatrix* m)
{
	float t[4];
	t[0] = v->m[0] * m->m[0][0] +
		v->m[1] * m->m[1][0] +
		v->m[2] * m->m[2][0] +
		v->m[3] * m->m[3][0];
	t[1] = v->m[0] * m->m[0][1] +
		v->m[1] * m->m[1][1] +
		v->m[2] * m->m[2][1] +
		v->m[3] * m->m[3][1];
	t[2] = v->m[0] * m->m[0][2] +
		v->m[1] * m->m[1][2] +
		v->m[2] * m->m[2][2] +
		v->m[3] * m->m[3][2];
	t[3] = v->m[0] * m->m[0][3] +
		v->m[1] * m->m[1][3] +
		v->m[2] * m->m[2][3] +
		v->m[3] * m->m[3][3];
	memcpy(v->m, t, sizeof(float) * 4);
}