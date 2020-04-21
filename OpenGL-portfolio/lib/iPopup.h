#pragma once

#include "iType.h"

class iPopup;
typedef void (*IPOPUP_OPEN_METHOD)(iPopup* me);
typedef void (*IPOPUP_DRAW_METHOD)(iPopup* me, float dt);

enum iPopupStyle {
	iPopupStyleNone = 0,
	iPopupStyleAlpha,
	iPopupStyleMove,
	iPopupStyleZoom,

	iPopupStyleTong,
};

enum iPopupStat {
	iPopupStatOpen = 0,
	iPopupStatProc,
	iPopupStatClose,
};

extern Texture* texFboForiPopup;

class iPopup
{
public:
	iPopup(iPopupStyle style);
	virtual ~iPopup();

	static void freeImg(void* data);

	void addObject(void* img);

	void show(bool show);
	void paint(float dt);

public:
	iArray* arrayImg;

	iPopupStyle style;
	iPopupStat stat;
	bool bShow;
	float showDt, _showDt;

	iPoint openPosition, closePosition;
	IPOPUP_OPEN_METHOD methodOpen, methodClose;

	IPOPUP_DRAW_METHOD methodDrawBefore, methodDrawAfter;

	int selected;
};

#define default_showDt 0.2f
