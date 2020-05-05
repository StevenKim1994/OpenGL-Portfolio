#pragma once

#pragma comment(lib, "OpenAL32.lib")

#include <al.h>
#include <alc.h>

class iOpenAL
{
public:
	iOpenAL(int audioNum);
	virtual ~iOpenAL();

public:
	void initBuffer(int idx, const char* szFormat, ...);
	void initSource(int idx, bool repeat);

	void play(int idx);
	void pause(int idx);
	void stop(int idx);
	void volume(int idx, float vol); 

public:
	ALuint* gBuffer;
	ALuint* gSource;
	int bufCount;
	float bgm, sfx;
	
};

struct AudioInfo
{
	char path[512];
	bool repeat;
	float volume;
	
};

void loadAudio(AudioInfo* ai, int aiNum); // 게임을 로딩할때
void freeAudio(); // 종료할때
void pauseAudio(); //멈출때
void resumeAudio(); // 재개할때
void audioPlay(int sndIdx);
void audioStop();
void audioStop(int sndIdx);
void audioVolume(float bgm, float sfx, int sfxNum);