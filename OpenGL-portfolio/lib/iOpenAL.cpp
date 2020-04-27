#include "iOpenAL.h"

#include "iStd.h"

static iOpenAL* al;

iOpenAL::iOpenAL(int audioNum)
{
	bufCount = audioNum;
	gBuffer = (ALuint*)malloc(sizeof(ALuint) * audioNum);
	gSource = (ALuint*)malloc(sizeof(ALuint) * audioNum);

	ALCdevice* newDevice = NULL;
	ALCcontext* newContext = NULL;

	ALenum error;

	newDevice = alcOpenDevice(NULL);

	if(newDevice)
	{
		const ALCint context_atrribs[] = { ALC_FREQUENCY, 22050, 0 };
		newContext = alcCreateContext(newDevice, context_atrribs);

		if(newContext)
		{
			alcMakeContextCurrent(newContext);

			alGenBuffers(bufCount, gBuffer);

			if((error = alGetError()) != AL_NO_ERROR)
			{
				printf("alGenBuffers: %d\n", error);
				return;
			}

			alGenSources(bufCount, gSource);
			if((error = alGetError()) != AL_NO_ERROR)
			{
				printf("alGenSOurces : %d\n", error);
				return;
			}
		}
	}

	alGetError();

	bgm = 1.0f;
	sfx = 1.0f;
}

ALvoid* gStaticBufferData = NULL;

iOpenAL::~iOpenAL()
{
	ALCcontext* context = NULL;
	ALCdevice* device = NULL;

	ALCuint returnedNames[1024];

	alDeleteBuffers(bufCount, returnedNames);
	alDeleteBuffers(bufCount, returnedNames);

	context = alcGetCurrentContext();
	device = alcGetContextsDevice(context);

	alcDestroyContext(context);
	alcCloseDevice(device);

	if (gStaticBufferData)
		free(gStaticBufferData);
}

typedef struct _WaveHeader0 {
	char riff[4];            // Chunk ID: "RIFF"
	unsigned int riffSize;      // Chunk size: 4+n
	char wave[4];            // WAVE ID: "WAVE"

	char fmt[4];            // Chunk ID: "fmt"
	unsigned int fmtSize;      // Chunk size: 16 or 18 or 40
	unsigned short format;      // Format code
	unsigned short channels;   // Number of interleaved channels
	unsigned int samplesPerSec;   // Sampling rate (blocks per second)
	unsigned int bytesPerSec;   // Data rate
	unsigned short blockAlign;   // Data block size(bytes)
	unsigned short bitsPerSample;// Bits per sample
} WaveHeader0;

typedef struct _WaveHeader1 {
	char data[4];            //'data'
	unsigned int dataSize;
} WaveHeader1;


void iOpenAL::initBuffer(int idx, const char* szFormat, ...)
{
	va_list args;
	va_start(args, szFormat);

	char szText[1024];
	_vsnprintf(szText, sizeof(szText), szFormat, args);
	va_end(args);

	int bufLen;
	char* buf = loadFile(szText, bufLen);

	WaveHeader0* head0 = (WaveHeader0*)buf;
	WaveHeader1* head1 = (WaveHeader1*)&buf[sizeof(WaveHeader0) + (head0->fmtSize - 16)];

	ALuint buffer = 0;
	ALuint format = 0;

	switch (head0->bitsPerSample)
	{
	case 8: format = (head0->channels == 1 ? AL_FORMAT_MONO8 : AL_FORMAT_STEREO8); break;
	case 16: format = (head0->channels == 1 ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16); break;
	default: return;
	}

	ALsizei samplesPerSec = head0->samplesPerSec;

	char* data = &buf[sizeof(WaveHeader0) + (head0->fmtSize - 16) + sizeof(WaveHeader1)];
	int dataLength = head1->dataSize;

	alBufferData(gBuffer[idx], format, data, dataLength, samplesPerSec);

	free(buf);

	ALenum error;
	if ((error = alGetError()) != AL_NO_ERROR)
		printf("initBuffer %s %d\n", szText, error);

}

void iOpenAL::initSource(int idx, bool repeat)
{
	ALenum error;
	error = alGetError(); // clear the error

	alSourcei(gSource[idx], AL_LOOPING, repeat);


	const float sourcePosAL[] = { 0.0f, 0.0f, 0.0f };
	alSourcefv(gSource[idx], AL_POSITION, sourcePosAL);

	alSourcef(gSource[idx], AL_REFERENCE_DISTANCE, 50.0f);

	alSourcei(gSource[idx], AL_BUFFER, gBuffer[idx]);

	if ((error = alGetError()) != AL_NO_ERROR)
		printf("initSource %d\n", error);


}

void iOpenAL::play(int idx)
{
	alSourcePlay(gSource[idx]);

	ALenum error;
	if ((error = alGetError()) != AL_NO_ERROR)
		printf("play %d\n", error);

}

void iOpenAL::pause(int idx)
{
	alSourcePause(gSource[idx]);
}

void iOpenAL::stop(int idx)
{
	alSourceStop(gSource[idx]);
}

void iOpenAL::volume(int idx, float vol)
{
	alSourcef(gSource[idx], AL_GAIN, vol);
}



int prevBgm;


void loadAudio(AudioInfo* ai, int aiNum)
{
	al = new iOpenAL(aiNum);

	for (int i = 0; i < aiNum; i++)
	{
		al->initBuffer(i, ai[i].path);
		al->initSource(i, ai[i].repeat);
		al->volume(i, ai[i].volume);
	}

	prevBgm = -1; // -1이면 이전에 bgm재생을 하지 않았음.

}

void freeAudio()
{
	delete al;
}

void pauseAudio()
{
	for (int i = 0; i < al->bufCount; i++)
		al->pause(i);
}

void resumeAudio()
{
	if (prevBgm != -1)
		audioPlay(prevBgm);


}

void audioPlay(int sndIdx)
{
	al->play(sndIdx);

	//prevBgm

	ALint repeat;
	alGetSourcei(al->gSource[sndIdx], AL_LOOPING, &repeat);
	if (repeat)
		prevBgm = sndIdx;
}

void audioStop()
{
	for (int i = 0; i < al->bufCount; i++)
		al->stop(i);
}

void audioStop(int sndIdx)
{
	al->stop(sndIdx);
}

void audioVolume(float bgm, float sfx, int sfxNum)
{
	// 밑 두줄은 그냥 편의를 위해 추가함... 무시해도됨.
	//if (bgm < 0.1) bgm = 0; else if (bgm > 0.9) bgm = 1.0; 
	//if (sfx < 0.1) sfx = 0; else if (sfx > 0.9) sfx = 1.0;


	int i;

	float vol;

	// 볼륨을 바꿀때 다시 원래 초기값으로 되돌린후 그후 다시볼륨을 조절한다.

	// 예를 들어 초기값 0.6이 100%일때 90%로 내리면 0.54가 90% 근데 여기서 다시 내리면 0.54에서 내리는게 아니라 0.6에서 내리는 비율을 조절한다는 말임.

	for (i = 0; i < sfxNum; i++)
	{
		alGetSourcef(al->gSource[i], AL_GAIN, &vol);

		vol /= al->sfx;

		al->volume(i, sfx);
	}




	for (i = sfxNum; i < al->bufCount; i++)
	{
		alGetSourcef(al->gSource[i], AL_GAIN, &vol);

		vol /= al->bgm;

		al->volume(i, bgm);
	}

}

