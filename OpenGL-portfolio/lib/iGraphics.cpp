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

// 여기 수정중... #bug