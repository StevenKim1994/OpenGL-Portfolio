#include "iPopup.h"

#include "iStd.h"

Texture* texFboForiPopup;

iPopup::iPopup(iPopupStyle style)
{
	arrayImg = new iArray(freeImg);

	this->style = style;
	stat = iPopupStatClose;
	bShow = false;
	_showDt = default_showDt;
	showDt = 0.0f;

	openPosition = iPointMake(0, 0);
	closePosition = iPointMake(0, 0);
	methodOpen = NULL;
	methodClose = NULL;
	methodDrawBefore = NULL;
	methodDrawAfter = NULL;

	selected = -1;
}

iPopup::~iPopup()
{
	delete arrayImg;
}

void iPopup::freeImg(void* data)
{
	iImage* img = (iImage*)data;
	delete img;
}

void iPopup::addObject(void* img)
{
	arrayImg->addObject(img);
}

void iPopup::show(bool show)
{
	if (show)
	{
		bShow = true;
		if (stat != iPopupStatClose)
			return;
		stat = iPopupStatOpen;
	}
	else
	{
		//bShow = false;
		if (stat != iPopupStatProc)
			return;
		stat = iPopupStatClose;
	}
	showDt = 0.0f;
}

void iPopup::paint(float dt)
{
	if (bShow == false)
		return;

	float alpha = 1.0f;
	float rx = 1.0f, ry = 1.0f;
	iPoint p;
	if (style == iPopupStyleNone || style == iPopupStyleAlpha || style == iPopupStyleMove)
	{
		float a;
		iPoint pp;
		if (stat == iPopupStatOpen)
		{
			a = linear(showDt / _showDt, 0.0f, 1.0f);
			if (showDt >= _showDt)
			{
				a = 1.0f;
				stat = iPopupStatProc;
				if (methodOpen)
					methodOpen(this);
			}
			pp = linear(a, openPosition, closePosition);
		}
		else if (stat == iPopupStatProc)
		{
			a = 1.0f;
			pp = closePosition;
		}
		else// if (stat == iPopupStatClose)
		{
			a = linear(showDt / _showDt, 1.0f, 0.0f);
			if (showDt >= _showDt)
			{
				a = 0.0f;
				bShow = false;
				if (methodClose)
					methodClose(this);
			}
			pp = linear(a, openPosition, closePosition);
		}

		if (style == iPopupStyleNone)
			p = closePosition;
		else if (style == iPopupStyleAlpha)
		{
			p = closePosition;
			alpha = a;
		}
		else if (style == iPopupStyleMove)
			p = pp;
	}
	else if (style == iPopupStyleZoom)
	{
		if (stat == iPopupStatOpen)
		{
			rx = ry = easeIn(showDt / _showDt, 0.0f, 1.0f);
			if (showDt >= _showDt)
			{
				stat = iPopupStatProc;
				if (methodOpen)
					methodOpen(this);
			}
			p = linear(rx, openPosition, closePosition);
		}
		else if (stat == iPopupStatProc)
		{
			p = closePosition;
		}
		else// if (stat == iPopupStatClose)
		{
			rx = ry = easeIn(showDt / _showDt, 1.0f, 0.0f);
			if (showDt >= _showDt)
			{
				bShow = false;
				if (methodClose)
					methodClose(this);
			}
			p = linear(rx, openPosition, closePosition);
		}
	}

	showDt += dt;

	float gr, gg, gb, ga;
	getRGBA(gr, gg, gb, ga);
	float size = getStringSize();
	float border = getStringBorder();
	float r, g, b, a, br, bg, bb, ba;
	getStringRGBA(r, g, b, a);
	getStringBorderRGBA(br, bg, bb, ba);

	Texture* tex = texFboForiPopup;
	fbo->bind(tex);///////////////////////////
	fbo->clear(0, 0, 0, 0);
	setRGBA(1, 1, 1, 1.0f);
	if (methodDrawBefore)
		methodDrawBefore(this, p, dt);

	int i, num = arrayImg->count;
	for (i = 0; i < num; i++)
	{
		iImage* img = (iImage*)arrayImg->objectAtIndex(i);
		img->paint(dt, p);
	}

	if (methodDrawAfter)
		methodDrawAfter(this, p, dt);
	fbo->unbind();///////////////////////////

	setRGBA(1, 1, 1, alpha);
	p -= iPointMake(closePosition.x * rx, closePosition.y * ry);
	drawImage(tex, p.x, p.y, 0, 0, tex->width, tex->height, TOP | LEFT, rx, ry, 2, 0, REVERSE_HEIGHT);

	setRGBA(gr, gg, gb, ga);
	setStringSize(size);
	setStringBorder(border);
	setStringRGBA(r, g, b, a);
	setStringBorderRGBA(br, bg, bb, ba);
}
