#include "menu.h"

void loadMenu()
{
	printf("loadMenu()\n");
}

void freeMenu()
{
}

void drawMenu(float dt)
{
	printf("drawMenu()\n");

	setRGBA(1, 1, 1, 1);
	fillRect(0, 0, devSize.width, devSize.height);
	
}

void keyMenu(iKeyState stat, iPoint point)
{
}
