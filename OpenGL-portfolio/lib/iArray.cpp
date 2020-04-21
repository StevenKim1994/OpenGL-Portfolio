#include "iArray.h"

#include <stdio.h>
#include <stdlib.h>

iArray::iArray(IARRAY_METHOD m)
{
	curr = NULL;
	count = 0;
	method = m;
}

iArray::~iArray()
{
	removeAll();
}

void iArray::addObject(int index, void* data)
{
	xArray* x = (xArray*)malloc(sizeof(xArray));
	x->data = data;
	//x->prev = curr;

	xArray* a = curr;
	for (int i = 1; ; i++)
	{
		if (count - i == index)
		{
			x->prev = a->prev;
			a->prev = x;
			count++;
			return;
		}
		a = a->prev;
	}

	// 마지막 노드에 추가
	x->prev = curr;
	curr = x;
	count++;
}
void iArray::addObject(void* data)
{
	xArray* a = (xArray*)malloc(sizeof(xArray));
	a->data = data;
	a->prev = curr;
	curr = a;

	count++;
}

void iArray::remove(int index)
{
	xArray* a = curr;
	xArray* b = NULL;
	for (int i = 1; ;i++)
	{
		if (count - i == index)
		{
			if (b)
				b->prev = a->prev;
			if (method)
				method(a->data);
			free(a);
			count--;
			return;
		}
		b = a;
		a = a->prev;
	}
}

void iArray::removeAll()
{
	while (curr)
	{
		xArray* c = curr->prev;
		if (method)
			method(curr->data);
		free(curr);
		curr = c;
	}
	count = 0;
}

void* iArray::objectAtIndex(int index)
{
	xArray* a = curr;
	for (int i = 1; ; i++)
	{
		if (count - i == index)
			return a->data;
		a = a->prev;
	}
}


