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
