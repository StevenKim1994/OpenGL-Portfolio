#include "iString.h"

#include "iStd.h"

iString::iString()
{
    strLength = 128;
    str = (char*)calloc(sizeof(char), 128);
}

iString::iString(const char* szFormat, ...)
{
    va_list args;
    va_start(args, szFormat);

    char szText[1024];
    _vsnprintf(szText, sizeof(szText), szFormat, args);
    va_end(args);

    strLength = 128;
    str = (char*)calloc(sizeof(char), 128);

    // szText
    int txtLength = strlen(szText);
    if (txtLength + 1 > strLength)
    {
        free(str);

        if (strLength < 1024)
            strLength *= 2;
        else
            strLength += 1024;
        str = (char*)calloc(sizeof(char), strLength);
    }
    strcpy(str, szText);
}


iString::~iString()
{
    free(str);
}

iString& iString::operator = (const char* s)
{
    int length = strlen(s);
    if (strLength < length + 1)
    {
        free(str);

        if (strLength < 1024)
            strLength *= 2;
        else
            strLength += 1024;
        str = (char*)calloc(sizeof(char), strLength);
    }
    strcpy(str, s);

    return *this;
}

iString& iString::operator = (iString& s)
{
    int length = strlen(s.str);
    if (strLength < length + 1)
    {
        free(str);

        if (strLength < 1024)
            strLength *= 2;
        else
            strLength += 1024;
        str = (char*)calloc(sizeof(char), strLength);
    }
    strcpy(str, s.str);

    return *this;
}

#if 0
iString& iString::operator + (const char* s)
{
    iString* newStr = new iString("%s%s", str, s);
    return *newStr;
}

iString& iString::operator + (iString& s)
{
    iString* newStr = new iString("%s%s", str, s.str);
    return *newStr;
}
#else
static char* _str_ = NULL;
static int _strLength_ = 1;

const char* iString::operator + (const char* s)
{
    int length = strlen(str) + strlen(s);
    if (_strLength_ < length + 1)
    {
        if (_str_)
            free(_str_);

        if (_strLength_ < 1024)
        {
            _strLength_ *= 2;
            if (_strLength_ < length + 1)
                _strLength_ = 128;
        }
        else
            _strLength_ += 1024;
        _str_ = (char*)calloc(sizeof(char), _strLength_);
    }
    sprintf(_str_, "%s%s", str, s);
    return _str_;
}

const char* iString::operator + (iString& s)
{
    int length = strlen(str) + strlen(s.str);
    if (_strLength_ < length + 1)
    {
        if (_str_)
            free(_str_);

        if (_strLength_ < 1024)
        {
            _strLength_ *= 2;
            if (_strLength_ < length + 1)
                _strLength_ = 128;
        }
        else
            _strLength_ += 1024;
        _str_ = (char*)calloc(sizeof(char), _strLength_);
    }
    sprintf(_str_, "%s%s", str, s.str);
    return _str_;
}
#endif

iString& iString::operator += (const char* s)
{
    int length = strlen(str) + strlen(s);
    if (strLength < length + 1)
    {
        if (strLength < 1024)
            strLength *= 2;
        else
            strLength += 1024;
        char* buf = (char*)calloc(sizeof(char), strLength);
        strcpy(buf, str);

        free(str);
        str = buf;
    }
    //sprintf(str, "%s%s", str, s);
    strcat(str, s);

    return *this;
}

iString& iString::operator += (iString& s)
{
    int length = strlen(str) + strlen(s.str);
    if (strLength < length + 1)
    {
        if (strLength < 1024)
            strLength *= 2;
        else
            strLength += 1024;
        char* buf = (char*)calloc(sizeof(char), strLength);
        strcpy(buf, str);

        free(str);
        str = buf;
    }
    sprintf(str, "%s%s", str, s.str);

    return *this;
}

bool iString::operator == (const char* s)
{
    return strcmp(str, s) == 0;
}
bool iString::operator == (iString& s)
{
    return strcmp(str, s.str) == 0;
}
bool iString::operator != (const char* s)
{
    return strcmp(str, s);
}
bool iString::operator != (iString& s)
{
    return strcmp(str, s.str);
}

char** iString::getStringLine(const char* str, int& lineNum, int d)
{
    int i, off, num = 1;
    for (i = 0; str[i]; i++)
    {
        if (str[i] == d)
            num++;
    }

    char** line = (char**)malloc(sizeof(char*) * num);
    num = 0;
    for (i = 0, off = 0; ; i++)
    {
        if (str[i] == d || str[i] == 0)
        {
            int len = i - off;
            char* s = (char*)calloc(sizeof(char), 1 + len);
            memcpy(s, &str[off], len);
            line[num] = s;
            num++;

            if (str[i] == 0)
                break;

            off = i + 1;
        }
    }

    lineNum = num;
    return line;
}

void iString::freeStringLine(char** line, int lineNum)
{
    for (int i = 0; i < lineNum; i++)
        free(line[i]);
    free(line);
}

bool iString::isUnicode(const char* str)
{
    return 	(str[0] & 0xF0) == 0xE0 &&
        (str[1] & 0xC0) == 0x80 &&
        (str[2] & 0xC0) == 0x80;
}
