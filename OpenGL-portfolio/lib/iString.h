#pragma once

class iString
{
public:
	iString();
	iString(const char* szFormat, ...);
	virtual ~iString();

	iString& operator = (const char* str);
	iString& operator = (iString& str);

#if 0
	iString& operator + (const char* str);
	iString& operator + (iString& str);
#else
	const char* operator + (const char* str);
	const char* operator + (iString& str);
#endif

	iString& operator += (const char* str);
	iString& operator += (iString& str);

	bool operator == (const char* str);
	bool operator == (iString& str);
	bool operator != (const char* str);
	bool operator != (iString& str);

	const char* cstr() { return str; }

	static char** getStringLine(const char* str, int& lineNum, int d = '\n');
	static void freeStringLine(char** line, int lineNum);

	static bool isUnicode(const char* str);

public:
	char* str;
	int strLength;
};

// 글자가 길떄 stringSize를 float 에 저장한다음 setStringSize의 인자로 넣고 버튼의 가로크기 보다 텍스트의 크기가 크다면 

// if(텍스트의 크기 > 버튼의 가로크기)
// setStringSize(stringSize * 버튼의 가로크기 / 텍스트의 크기) 로 설정하면 버튼에 맞는 텍스트의 크기가 적용이 된다.