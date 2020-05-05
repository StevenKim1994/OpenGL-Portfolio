#include "menu.h"

Texture* menuBg;


void loadMenu()
{
	printf("loadMenu()\n");

	menuBg = createImage("assets/menu/menuBg.jpg");


	createPopMenuBtn();
}

void freeMenu()
{

	free(menuBg);
	freePopMenuBtn();
}

void drawMenu(float dt)
{
	printf("drawMenu()\n");

	drawImage(menuBg, 0, 0, TOP | LEFT);

#if 0 // 버튼이 위치할 좌표
	for (int i = 0; i < 3; i++)
		fillRect((devSize.width / 2) - 175, (250 * i) + 350, 350, 100);

#endif 

	drawPopMenubtn(dt);
	
}

void keyMenu(iKeyState stat, iPoint point)
{
	if (keyPopMenuBtn(stat, point))
		return;
}


//---------------PopMenuBtn-----------------------//

iPopup* PopMenuBtn;
void createPopMenuBtn()
{
	iPopup* pop = new iPopup(iPopupStyleAlpha);
	iImage** Buttons = (iImage**)malloc(sizeof(iImage*) * 3); 
	iSize btnSize = iSizeMake(350, 100);
	iGraphics* g = iGraphics::instance();

	setStringSize(5);
	setStringBorder(0);
	setStringRGBA(1, 1, 1, 1);

	const char* strBtnIndex[3] = { "게임시작", "게임옵션", "게임종료" };

	//팝업에 포함되는 내용 추가부분
	{
		for (int i = 0; i < 3; i++)
		{
			iImage* img = new iImage();
			for (int j = 0; j < 2; j++)
			{
				if (j == 0) setRGBA(1, 0, 0, 1); // 일단 선택되지 않았을때 버튼의 색은 Red...
				else if (j == 1) setRGBA(0, 1, 0, 1); // 선택되었을떄 버튼의 색은 Green
				
				g->init(btnSize);
				g->fillRect(0, 0, btnSize.width, btnSize.height, 10);
				g->drawString(0, 0, TOP | LEFT, strBtnIndex[i]);
				
			}


		}


	}




	iPoint op = iPointMake(devSize.width / 2, 400);
	pop->openPosition = op;
	pop->closePosition = op;



	PopMenuBtn = pop;
}

void freePopMenuBtn()
{
}

void drawPopMenubtn(float dt)
{
}

bool keyPopMenuBtn(iKeyState stat, iPoint point)
{
	return false;
}

void showPopMenuBtn(bool show)
{
}
