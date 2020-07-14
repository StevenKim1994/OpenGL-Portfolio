#include "game.h"


#include "intro.h"
#include "menu.h"
#include "sceneManager.h"
#include "trailer.h"
#include "stage.h"
#include "ending.h"
#include "endstage.h"
#include "vilege.h"

#include <process.h> // 쓰레드 헤더

#define SOUND_NUM 16

struct ThreadParm
{
	int x, y, z;
	
};

bool login;
#pragma comment(lib,"ws2_32.lib") 

char* getHttpHeader(const char* url, int port)
{
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return NULL;

	struct hostent* host_entry = gethostbyname(url);
	if (host_entry == NULL)
		return NULL;

	int client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (client_socket == -1)
		return NULL;

	struct sockaddr_in server_addr;
	memset(&server_addr, 0x00, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	memcpy((void*)&server_addr.sin_addr, (void*)(host_entry->h_addr), sizeof(host_entry->h_addr));

	if (connect(client_socket, (struct sockaddr*) & server_addr, sizeof(server_addr)) == -1)
		return NULL;

	const char* s = "HEAD / HTTP/1.0\r\n\r\n";// only http head
	send(client_socket, s, strlen(s), 0);

	char* buf = (char*)calloc(sizeof(char), 10000);
	int bufLen = 0;
	while (1)
	{
		char b[10000];
		size_t len = recv(client_socket, b, 10000, 0);
		if (len > 0)
		{
			memcpy(&buf[bufLen], b, len);
			bufLen += len;
		}
		else
			break;
	}
	return buf;
}



unsigned int _stdcall threadPrint(void* parm)
{
	char* buf = getHttpHeader("www.ncsoft.com", 80);
	saveFile("thread.txt", buf, 10000);
	free(buf);

	login = true;

	ThreadParm* tp = (ThreadParm*)parm;
	_endthreadex(tp->x); // 쓰레드가 종료했음을 알려주는거

	return 0;
}




void loadGame()
{
	login = false;

	ThreadParm* tp0 = (ThreadParm*)malloc(sizeof(ThreadParm));
	//ThreadParm* tp1 = (ThreadParm*)malloc(sizeof(ThreadParm));
	tp0->x = 0, tp0->y = 1, tp0->z = 2;
	//tp1->x = 0, tp1->y = 1, tp1->z = 2;
	//쓰레드 사용법
	unsigned int id; 
	HANDLE hand = (HANDLE)_beginthreadex(NULL, 0, threadPrint, (void*)tp0, NULL, &id);

	//WaitForSingleObject(hand, 1000); // 1초후에 밑에꺼 실행 1000자리에 INFINITE면 해당 스레드가 종료되어야지만 밑에 있는 코드가 실행될수 있다.
		//WaitForMultipleObjects(2, hand , TRUE, INFINITY) 이 함수는 쓰레드가 여러개일때 동시에 실행하고 끝날떄까지 기다림

	//HANDLE hadn2 = (HANDLE)_beginthreadex(NULL, 0, threadPrint, (void*)tp1 , NULL, &id);


	AudioInfo soundAssets[SOUND_NUM] = {
							{ "assets/intro/sound/bgm.wav", true, 1.0f},
							{ "assets/intro/sound/okay.wav", false, 1.0f},
							{ "assets/intro/sound/SHOT.wav", false, 1.0f},
							{"assets/menu/sound/menuBGM.wav", true, 1.0f},
							{"assets/stage/hero/Knight/skill/skill1sound.wav", false, 1.0f},
							{"assets/stage/goblin/sound/playerhit.wav", false, 1.0f},
	};


	if (login)
	{
		system("cls");
		printf("login!\n");
	}


	loadAudio(soundAssets, 6);


	//loadTrailer();
	//gameState = gs_trailer;
	audioPlay(0);

		
	loadIntro();
	gameState = gs_intro;
}

void freeGame()
{
	switch(gameState)
	{
	case gs_intro: freeIntro();	break;
	case gs_menu:	freeMenu(); break;
	case gs_stage:	freeStage(); break;
	case gs_ending: freeEnding(); break;
	case gs_trailer: freeTrailer(); break;
	case gs_endStage: freeEndStage(); break;
	case gs_villege: freeVillege(); break;
	}

	freeAudio();
}

void drawGame(float dt)
{
	switch(gameState)
	{
	case gs_intro:	drawIntro(dt); break;
	case gs_menu:	drawMenu(dt);  break;
	case gs_stage:  drawStage(dt);	break;
	case gs_ending:	drawEnding(dt);  break;
	case gs_trailer: drawTrailer(dt); break;
	case gs_endStage: drawEndStage(dt); break;
	case gs_villege: drawVillege(dt); break;
		
	}

	drawLoading(dt);
}

void keyGame(iKeyState stat, iPoint point)
{
	if (keyLoading(stat, point))
		return;

	switch(gameState)
	{
	case gs_intro:	keyIntro(stat, point);	break;
	case gs_menu:	keyMenu(stat, point);	break;
	case gs_stage:	keyStage(stat, point);	break;
	case gs_ending:	keyEnding(stat, point);	break;
	case gs_trailer: keyTrailer(stat, point); break;
	case gs_endStage: keyEndStage(stat, point); break;
	case gs_villege: keyVilliege(stat, point); break;
	}
}
