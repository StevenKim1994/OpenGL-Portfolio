#include "iStd.h"

uint8 float2uint8(float f)
{
	return f * 0xFF;
}
int monitorSizeW, monitorSizeH;
iSize devSize;
iRect viewport;
static float _r, _g, _b, _a; // rgba 백업받는 전역변수...

char* _stringName;
float _stringSize;
float _stringR, _stringG, _stringB, _stringA; // Graphics::instance()를 호출해서 그릴떄의 글 색상 백업받는 변수...
float _stringBorder; // 글자의 테두리두께 백업변수
float _stringBorderR, _stringBoderG, _stringBorderB, _stringBorderA; // 테두리 색상 백업변수

DWORD prevTickCount;

static bool* keys;
static uint32 keyDown, keyStat;
uint32 getKeyDown() { return keyDown; }
bool getKeyDown(uint32 key) { return keyDown & key; }
uint32 getKeyStat() { return keyStat;  }
bool getKeyStat(uint32 key) { return keyStat & key; }

void loadLib(HDC hDC)
{
	setupOpenGL(true, hDC);
	startGLEW();
	initOpenGL();

	devSize = iSizeMake(DEVSIZE_WIDTH, DEVSIZE_HEIGHT);
	fbo = new iFBO(devSize.width, devSize.height);
 //#bug texFboFor
	reshapeOpenGL(monitorSizeW, monitorSizeH);

	_r = 1.0f;
	_g = 1.0f;
	_b = 1.0f;
	_a = 1.0f;

	_stringName = NULL;
	setStringName("궁서체");
	setStringSize(10);
	setStringRGBA(1, 1, 1, 1);
	setStringBorder(1);
	setStringBorderRGBA(0, 0, 0, 1);

	glEnable(GL_LINE_SMOOTH);

	prevTickCount = GetTickCount();

	keys = (bool*)calloc(sizeof(bool), 256);
	keyDown = 0;
	keyStat = 0;

	srand(time(NULL));
	void sRandom();
	sRandom();
	
}

void freeLib()
{
	delete fbo;
	//#bug freeImage(texFboForiPopup);
	setupOpenGL(false, NULL);

	free(keys);
	
}

bool takeScreenshot = false;
Texture* texScreenshot = NULL;
void drawScreenshot()
{
	return;
	Texture* tex = texScreenshot;
	if(tex)
	{
		drawImage(tex, devSize.width / 2, devSize.height / 2, 0, 0, tex->width, tex->height, VCENTER | HCENTER, 0.3f, 0.3f, 2, 0, REVERSE_HEIGHT); // REVESER_HEIGHT를 하는이유는 반전으로 찍히기 떄문에...
	}
	else
	{
		setRGBA(1, 1, 1, 1);
		fillRect(devSize.width / 2 - 100, devSize.height / 2 - 100, 200, 200);
	}
}

void checkScreenshot()
{
	if(takeScreenshot)
	{
		takeScreenshot = false;

		int potW = nextPot(devSize.width);
		int potH = nextPot(devSize.height);
		// 여기서 부터 수정하면됨...
	}
}


float _sin(float degree)
{
	return sin(M_PI / 180 * degree);
}

float _cos(float degree)
{
	return cos(M_PI / 180 * degree);
}
