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

