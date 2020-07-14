#pragma once

// ------------------------------------------
// iMatrix
// ------------------------------------------
struct iMatrix
{
	float m[4][4];
	float* d() { return &m[0][0]; }

	iMatrix& operator = (const iMatrix& b);
	const iMatrix operator * (const iMatrix& b);
	const iMatrix operator * (iMatrix* b);
	iMatrix& operator *= (const iMatrix& b);
	iMatrix& operator *= (iMatrix* b);

	void loadIdentity();

	void scale(float sx, float sy, float sz);
	void rotate(float x, float y, float z, float angle);
	void translate(float tx, float ty, float tz);

	// 2D
	void ortho(float left, float right, float bottom, float top, float nearZ, float farZ);
	// 3D
	void frustum(float left, float right, float bottom, float top, float nearZ, float farZ);
	void perspective(float fovy, float aspect, float nearZ, float farZ);
	void lookat(float eyeX, float eyeY, float eyeZ,
		float lookAtX, float lookAtY, float lookAtZ,
		float upX, float upY, float upZ);
};

void multiply(iMatrix* a, const iMatrix* b);

// ------------------------------------------
// iVector
// ------------------------------------------
struct iVector
{
	float m[4];

	iVector& operator = (const iVector& v);
	const iVector operator * (const iMatrix& a);
	const iVector operator * (iMatrix* a);
	iVector& operator *= (const iMatrix& m);
	iVector& operator *= (iMatrix* m);

	void rotate(iVector* v, float x, float y, float z, float angle);
};

void multiply(iVector* v, const iMatrix* m);




