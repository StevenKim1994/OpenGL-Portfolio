#include "Orc.h"

#define Orc_HP 20
#define Orc_MP 100
#define Orc_Stamina 100

#define Orc_Width 10
#define Orc_Height 10


Orc::Orc()
{
	HP = Orc_HP;
	MP = Orc_MP;
	Stamina = Orc_Stamina;


	size = iSizeMake(Orc_Width, Orc_Height);
	struct OrcInfo
	{
		const char* path;
		int num;
		float sizeRate;
		iPoint p; // 축 조절하는 거

	};

	OrcInfo _oi[6] = {
		"assets/stage/goblin/goblin idle (%d).png", 4, 2.0f, {-75, -90} ,
		"assets/stage/goblin/goblin attack (%d).png", 8, 2.0f, {-75,-90},
		"assets/stage/goblin/goblin move (%d).png", 8, 2.0f, {-75, -90},
		"assets/stage/goblin/goblin move (%d).png", 8, 2.0f, {-75, -90},
		"assets/stage/goblin/goblin hurt (%d).png", 4, 2.0f, {-75, -90},
		"assets/stage/goblin/goblin death (%d).png", 4, 2.0f, {-75, -90},


	};

	iGraphics* g = iGraphics::instance();
	iSize size;

	imgs = (iImage**)malloc(sizeof(iImage*) * 4);

	for (int i = 0; i < 3; i++)
	{
		OrcInfo* oi = &_oi[i];

		iImage* img = new iImage();

		for (int j = 0; j < oi->num; j++)
		{
			igImage* ig = g->createIgImage(oi->path, j + 1);
			size = iSizeMake(g->getIgImageWidth(ig) * oi->sizeRate,
				g->getIgImageHeight(ig) * oi->sizeRate);

			g->init(size);
			g->drawImage(ig, 0, 0, oi->sizeRate, oi->sizeRate, TOP | LEFT);

			Texture* tex = g->getTexture();
			img->addObject(tex);
			freeImage(tex);
		}

		img->_aniDt = 0.1f;

		switch (i)
		{
		case 0:
		case 2:
			img->_repeatNum = 0; // 무한반복
			break;

		default:
			img->_repeatNum = 1;

			break;
		}

		img->position = oi->p * 2;

		imgs[i] = img;

	}

	behave = (EnermyBehave)-1;
	setBehave(EnermyBehave_idle, 0);
	direction = 0;
	jumpNum = 0;
	_jumpNum = 2;


}

Orc::~Orc()
{
	for (int i = 0; i < 3; i++)
		delete imgs[i];

	free(imgs);

	
}

void Orc::cbBehave(iImage* img)
{
}

void Orc::cbSkill(iImage* skillimg)
{
}

void Orc::setBehave(EnermyBehave be, int dir)
{
	if (behave != be || direction != dir)
	{
		behave = be;
		img = imgs[be];
		img->startAnimation(cbBehave);
		direction = dir;
	}
}

void Orc::paint(float dt, iPoint offset)
{
	img->paint(dt, position + offset, direction);
	
}

void Orc::Skill1()
{
	printf("orc skill1! on!\n");

}

void Orc::Skill2()
{
}

void Orc::setDetected_Player(bool check)
{
	detected_Player = check;
}

void Orc::setTarget(Object* obj)
{
	Target = obj;
	Target_Pos = obj->getPosition();
}

bool Orc::getDetected_Player()
{
	return detected_Player;
}

Object* Orc::getTarget()
{
	return Target;
}
