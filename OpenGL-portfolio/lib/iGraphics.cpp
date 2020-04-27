#include "iGraphics.h"
#include "iStd.h"
ULONG_PTR startGdiplus()
{
	GdiplusStartupInput gpStartupInput;
	ULONG_PTR			gpToken;
	GdiplusStartup(&gpToken, &gpStartupInput, NULL);
	return gpToken;
	
}

void endGdiplus(ULONG_PTR gpToken)
{
	GdiplusShutdown(gpToken);
}

struct GD
{
	Bitmap* bmp;
	Graphics* g;
};

GD* gd = NULL;

wchar_t* utf8_to_utf16(const char* szFormat, ...)
{
	va_list args;
	va_start(args, szFormat);

	char szText[1024];
	_vsnprintf(szText, sizeof(szText), szFormat, args);
	va_end(args);

	int length = MultiByteToWideChar(CP_UTF8, 0, szText, -1, NULL, 0);
	wchar_t* ws = (wchar_t*)malloc(sizeof(wchar_t) * length);
	MultiByteToWideChar(CP_UTF8, 0, szText, strlen(szText) + 1, ws, length);

	return ws;
}

char* utf16_to_utf8(const wchar_t* str)
{
	int length = WideCharToMultiByte(CP_UTF8, 0, str, lstrlenW(str), NULL, 0, NULL, NULL);
	char* s = (char*)calloc(sizeof(char), length + 1);
	WideCharToMultiByte(CP_UTF8, 0, str, lstrlenW(str), s, length, NULL, NULL);

	return s;
}

void checkFontFamily(FontFamily* ff, int& style)
{
	const char* s = getStringName();

	if (s[0] != 'a' || s[1] != 's' || s[2] != 's')
	{
		// 시스템 설치된 폰트
		wchar_t* wStringName = utf8_to_utf16(s);
		FontFamily f(wStringName);
		free(wStringName);

		memcpy(ff, &f, sizeof(FontFamily));

		style = FontStyleRegular;
	}
	else
	{
		// 커스텀 폰트 (otf, ttf)
		PrivateFontCollection pfc;
		wchar_t* ws = utf8_to_utf16(s);
		pfc.AddFontFile(ws);
		free(ws);

		int count = pfc.GetFamilyCount();
		int found = 0;

		pfc.GetFamilies(count, ff, &found);

		for (int i = 0; i < found; i++)
		{
			if (ff->IsStyleAvailable(FontStyleRegular))
			{
				style = FontStyleRegular;
				return;
			}
			else if (ff->IsStyleAvailable(FontStyleBold))
			{
				style = FontStyleBold;
				return;
			}
		}

	}
}

iGraphics::iGraphics()
{
	gd = (GD*)calloc(sizeof(GD), 1);
}

iGraphics* iGraphics::instance()
{
	static iGraphics* g = new iGraphics();
	return g;
}

iGraphics::~iGraphics()
{
	if (gd->bmp)
		delete gd->bmp;
	if (gd ->g)
		delete gd->g;

	free(gd);
}

void iGraphics::init(iSize size)
{
	if (gd->bmp)
		delete gd->bmp;

	gd->bmp = new Bitmap(size.width, size.height, PixelFormat32bppARGB);
	Graphics* g = Graphics::FromImage(gd->bmp);
	g->SetPageUnit(UnitPixel);
	g->SetPixelOffsetMode(PixelOffsetModeHalf);
	g->SetTextRenderingHint(TextRenderingHintClearTypeGridFit);
	g->SetSmoothingMode(SmoothingModeAntiAlias8x8);
	g->SetInterpolationMode(InterpolationModeHighQualityBicubic);
	if (gd->g)
		delete gd->g;
	gd->g = g;
}

void iGraphics::init(int width, int height)
{
	init(iSizeMake(width, height));
}

void iGraphics::setClip(int x, int y, int width, int height)
{
	Region region(Rect(x, y, width, height));
	gd->g->SetClip(&region, CombineModeReplace);	
}

void iGraphics::setClip(iRect rt)
{
	Region region(Rect(rt.origin.x, rt.origin.y, rt.size.width, rt.size.height));
	gd->g->SetClip(&region, CombineModeReplace);
}

igImage* iGraphics::createIgImage(const char* szFormat, ...)
{
	va_list args;
	va_start(args, szFormat);

	char szText[1024];
	_vsnprintf(szText, sizeof(szText), szFormat, args);
	va_end(args);

	wchar_t* ws = utf8_to_utf16(szText);
	Image* img = new Image(ws);
	free(ws);

	return img;
}

void iGraphics::freeIgImage(igImage* img)
{
	delete img;
}

int iGraphics::getIgImageWidth(igImage* img)
{
	return img->GetWidth();
}

int iGraphics::getIgImageHeight(igImage* img)
{
	return img->GetHeight();
}

void iGraphics::drawImage(igImage* img, float x, float y, int anc)
{
	drawImage(img, x, y, 0, 0, img->GetWidth(), img->GetHeight(), anc, 1.0f, 1.0f, 2, 0, REVERSE_NONE);	
}

void iGraphics::drawImage(igImage* img, float x, float y, float rx, float ry, int anc)
{
	drawImage(img, x, y, 0, 0, img->GetWidth(), img->GetHeight(), anc, rx, ry, 2, 0, REVERSE_NONE);
}

void iGraphics::drawImage(igImage* img, int x, int y, int ix, int iy, int iw, int ih, int anc, float ratX, float ratY, int xyz, float degree, int reverse)
{
	int width = img->GetWidth() * ratX;
	int height = img->GetHeight() * ratY;

	switch (anc)
	{
	case TOP | LEFT:	break;
	case TOP | HCENTER:	x -= width / 2;	break;
	case TOP | RIGHT:	x -= width;		break;
	case VCENTER | LEFT:			y -= height / 2;	break;
	case VCENTER | HCENTER:	x -= width / 2; y -= height / 2; break;
	case VCENTER | RIGHT:	x -= width;	y -= height / 2; break;
	case BOTTOM | LEFT:	y -= height;	break;
	case BOTTOM | HCENTER: x -= width / 2; y -= height;	break;
	case BOTTOM | RIGHT:	x -= width;	y -= height;	break;
	}

	Rect destinationRect(x, y, width, height);

	iPoint destPoint[3] = { {x,y}, {x + width ,y}, {x,y + height} };

	if(reverse == REVERSE_WIDTH)
	{
		destPoint[2].x = destPoint[1].x;

		iPoint t = destPoint[0];
		destPoint[0] = destPoint[1];
		destPoint[1] = t;
	}
	else if(reverse == REVERSE_HEIGHT)
	{
		destPoint[1].y = destPoint[2].y;

		iPoint t = destPoint[0];
		destPoint[0] = destPoint[2];
		destPoint[2] = t;
		
	}

	if(xyz == 0) // x 축으로 회전
	{
		destPoint[0].x = destPoint[1].y = y + height / 2 - height / 2 * _cos(degree);
		destPoint[2].y = y + height / 2 + height / 2 * _cos(degree);
		
	}
	else if( xyz ==1) // y축으로 회전
	{
		destPoint[0].x = destPoint[2].x = x + width / 2 - width / 2 * _cos(degree);
		destPoint[1].x = x + width / 2 + width / 2 * _cos(degree);
		
	}
	else if(xyz == 2) // z축으로 회전
	{
		iPoint t = iPointMake(x + width / 2, y + height / 2);
		for (int i = 0; i < 3; i++)
			destPoint[i] = iPointRotate(destPoint[i], t, degree);
		
	}

	float r, g, b, a;
	getRGBA(r, g, b, a);
	ColorMatrix matrix = { r,   0.0f, 0.0f, 0.0f, 0.0f,
						 0.0f, g,    0.0f, 0.0f, 0.0f,
						 0.0f, 0.0f, b,    0.0f, 0.0f,
						 0.0f, 0.0f, 0.0f, a,    0.0f,
						 0.0f, 0.0f, 0.0f, 0.0f, 1.0f };
	ImageAttributes attr;
	attr.SetColorMatrix(&matrix, ColorMatrixFlagsDefault, ColorAdjustTypeBitmap);
	gd->g->DrawImage(img,
		(PointF*)destPoint, 3,
		ix, iy, iw, ih, UnitPixel, &attr);
}

void iGraphics::drawString(float x, float y, int anc, const char* szFormat, ...)
{
	va_list args;
	va_start(args, szFormat);

	char szText[1024];
	_vsnprintf(szText, sizeof(szText), szFormat, args);
	va_end(args);

	iSize size = sizeOfString(szText);
	float width = size.width;
	float height = size.height;
	switch (anc) {
	case TOP | LEFT:                                         break;
	case TOP | HCENTER:     x -= width / 2;                  break;
	case TOP | RIGHT:       x -= width;                      break;
	case VCENTER | LEFT:                    y -= height / 2; break;
	case VCENTER | HCENTER: x -= width / 2; y -= height / 2; break;
	case VCENTER | RIGHT:   x -= width;     y -= height / 2; break;
	case BOTTOM | LEFT:                     y -= height;     break;
	case BOTTOM | HCENTER:  x -= width / 2; y -= height;     break;
	case BOTTOM | RIGHT:    x -= width;     y -= height;     break;
	}

	wchar_t* wStr = utf8_to_utf16(szText);

	GraphicsPath path;
	FontFamily  fontFamily;
	PointF      pointF(x, y);
	StringFormat sf;

	int fontStyle;
	checkFontFamily(&fontFamily, fontStyle);

	path.AddString(wStr, lstrlenW(wStr), &fontFamily, fontStyle,
		getStringSize(), pointF, &sf);

	float r, g, b, a;
	getStringRGBA(r, g, b, a);
	SolidBrush brush(Color(float2uint8(a),
		float2uint8(r),
		float2uint8(g),
		float2uint8(b)));
	gd->g->FillPath(&brush, &path);

	float sb = getStringBorder();
	if (sb)
	{
		getStringBorderRGBA(r, g, b, a);
		Pen pen(Color(float2uint8(a),
			float2uint8(r),
			float2uint8(g),
			float2uint8(b)));
		pen.SetWidth(sb);
		gd->g->DrawPath(&pen, &path);
	}

	free(wStr);
}

void iGraphics::drawLine(iPoint sp, iPoint ep) {
	drawLine(sp.x, sp.y, ep.x, ep.y);
}
void iGraphics::drawLine(float x0, float y0, float x1, float y1)
{
	float r, g, b, a;
	getRGBA(r, g, b, a);
	Pen pen(Color(float2uint8(a),
		float2uint8(r),
		float2uint8(g),
		float2uint8(b)));
	gd->g->DrawLine(&pen, x0, y0, x1, y1);
}

void iGraphics::drawRect(iRect rt, float radius) {
	drawRect(rt.origin.x, rt.origin.y, rt.size.width, rt.size.height, radius);
}
void iGraphics::drawRect(float x, float y, float width, float height, float radius)
{
	float r, g, b, a;
	getRGBA(r, g, b, a);
	Pen pen(Color(float2uint8(a),
		float2uint8(r),
		float2uint8(g),
		float2uint8(b)));

	GraphicsPath path;
	path.AddLine(x + radius, y, x + width - (radius * 2), y);
	path.AddArc(x + width - (radius * 2), y, radius * 2, radius * 2, 270, 90);
	path.AddLine(x + width, y + radius, x + width, y + height - (radius * 2));
	path.AddArc(x + width - (radius * 2), y + height - (radius * 2), radius * 2, radius * 2, 0, 90);
	path.AddLine(x + width - (radius * 2), y + height, x + radius, y + height);
	path.AddArc(x, y + height - (radius * 2), radius * 2, radius * 2, 90, 90);
	path.AddLine(x, y + height - (radius * 2), x, y + radius);
	path.AddArc(x, y, radius * 2, radius * 2, 180, 90);
	path.CloseFigure();

	gd->g->DrawPath(&pen, &path);
}

void iGraphics::fillRect(iRect rt, float radius) {
	fillRect(rt.origin.x, rt.origin.y, rt.size.width, rt.size.height, radius);
}
void iGraphics::fillRect(float x, float y, float width, float height, float radius)
{
	float r, g, b, a;
	getRGBA(r, g, b, a);
	SolidBrush brush(Color(float2uint8(a),
		float2uint8(r),
		float2uint8(g),
		float2uint8(b)));
	GraphicsPath path;
	path.AddLine(x + radius, y, x + width - (radius * 2), y);
	path.AddArc(x + width - (radius * 2), y, radius * 2, radius * 2, 270, 90);
	path.AddLine(x + width, y + radius, x + width, y + height - (radius * 2));
	path.AddArc(x + width - (radius * 2), y + height - (radius * 2), radius * 2, radius * 2, 0, 90);
	path.AddLine(x + width - (radius * 2), y + height, x + radius, y + height);
	path.AddArc(x, y + height - (radius * 2), radius * 2, radius * 2, 90, 90);
	path.AddLine(x, y + height - (radius * 2), x, y + radius);
	path.AddArc(x, y, radius * 2, radius * 2, 180, 90);
	path.CloseFigure();

	gd->g->FillPath(&brush, &path);
}

Texture* iGraphics::getTexture()
{
	int width, height;
	uint8* rgba = bmp2rgba(gd->bmp, width, height);
	Texture* tex = createImageWithRGBA(rgba, width, height);
	free(rgba);

	return tex;
}

	
