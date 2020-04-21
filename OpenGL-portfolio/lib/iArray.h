#pragma once

struct xArray
{
	void* data;
	xArray* prev;
};

typedef void (*IARRAY_METHOD)(void* data);

class iArray
{
public:
	iArray(IARRAY_METHOD m);
	virtual ~iArray();

	void addObject(int index, void* data);
	void addObject(void* data);

	void remove(int index);
	void removeAll();

	void* objectAtIndex(int index);
public:
	xArray* curr;
	int count;
	IARRAY_METHOD method;
};


