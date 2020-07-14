#include "iStd.h"

uint8 float2uint8(float f)
{
    return f * 0xFF;
}

int monitorSizeW, monitorSizeH;
iSize devSize;
iRect viewport;
static float _r, _g, _b, _a;

char* _stringName;
float _stringSize;
float _stringR, _stringG, _stringB, _stringA;
float _stringBorder;
float _stringBorderR, _stringBorderG, _stringBorderB, _stringBorderA;

DWORD prevTickCount;

static bool* keys;
static uint32 keyDown, keyStat;
uint32 getKeyDown() { return keyDown; }
bool getKeyDown(uint32 key) { return keyDown & key; }
uint32 getKeyStat() { return keyStat; }
bool getKeyStat(uint32 key) { return keyStat & key; }


iVBO* gVbo = NULL;
Texture** texGdi;

void loadLib(HDC hDC)
{
    setupOpenGL(true, hDC);
    startGLEW();
    initOpenGL();

    devSize = iSizeMake(DEVSIZE_WIDTH, DEVSIZE_HEIGHT);
    fbo = new iFBO(devSize.width, devSize.height);
    texFboForiPopup = createTexture(devSize.width, devSize.height);
    reshapeOpenGL(monitorSizeW, monitorSizeH);// App.cpp

    _r = 1.0f;
    _g = 1.0f;
    _b = 1.0f;
    _a = 1.0f;

    _stringName = NULL;
    setStringName("assets/font/Textregular.ttf");
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

    gVbo = new iVBO();
    texGdi = (Texture**)malloc(sizeof(Texture*) * 2);

    Texture* tex = createTexture(32, 32);
    setTexture(CLAMP, MIPMAP);
    fbo->bind(tex);
    // fbo->clear(1, 0, 1, 1);
    iSize s = devSize;

    devSize = iSizeMake(32, 32);
    iRect v = viewport;
    viewport = iRectMake(0, 0, 32, 32);
    float m[16];
    memcpy(m, mProjection->d(), sizeof(float) * 16);
    mProjection->loadIdentity();
    mProjection->ortho(0.0, 32.0, 32.0, 0, -1000, 1000);

    fillCircle(16, 16, 16);
    devSize = s;
    memcpy(mProjection->d(), m, sizeof(float) * 16);
    viewport = v;
    fbo->unbind();
    texGdi[0] = tex;

    tex = createTexture(32, 32);
    fbo->bind(tex);
    fbo->clear(1, 1, 1, 1);
    fbo->unbind();

    texGdi[1] = tex;

}

void freeLib()
{
    delete fbo;
    freeImage(texFboForiPopup);
    setupOpenGL(false, NULL);

    free(keys);

    delete gVbo;

    for (int i = 0; i < 2; i++)
        freeImage(texGdi[i]);
    free(texGdi);
}

bool takeScreenshot = false;
Texture* texScreenshot = NULL;
void drawScreenshot()
{
    return;
    Texture* tex = texScreenshot;
    if (tex)
    {
        drawImage(tex, devSize.width / 2, devSize.height / 2,
            0, 0, tex->width, tex->height, VCENTER | HCENTER,
            0.3f, 0.3f, 2, 0, REVERSE_HEIGHT);
    }
    else
    {
        setRGBA(1, 1, 1, 1);
        fillRect(devSize.width / 2 - 100, devSize.height / 2 - 100, 200, 200);
    }
}
void checkScreenshot()
{
    if (takeScreenshot)
    {
        takeScreenshot = false;

        int potW = nextPOT(devSize.width);
        int potH = nextPOT(devSize.height);
        uint8* rgba = (uint8*)calloc(sizeof(uint8), potW * potH * 4);
        glReadPixels(0, 0, potW, potH, GL_RGBA, GL_UNSIGNED_BYTE, rgba);
        if (texScreenshot)
            freeImage(texScreenshot);
        texScreenshot = createImageWithRGBA(rgba, potW, potH);

        saveImageFromRGBA("test.png", rgba, devSize.width, devSize.height);
        free(rgba);
    }
}



void drawLib(Method_Paint method)
{
    DWORD d = GetTickCount();
    float delta = (d - prevTickCount) / 1000.f;
    prevTickCount = d;

    fbo->bind();// --------------------

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    method(delta);
  
    keyDown = 0;


    checkScreenshot();
    fbo->unbind();// ------------------

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    setRGBA(1, 1, 1, 1);

    Texture* tex = fbo->getTexture();

    //drawImage(tex, 0, 0, TOP | LEFT);
    drawImage(tex, 0, 0,
        0, 0, tex->width, tex->height, TOP | LEFT,
        1.0f, 1.0f, 2, 0, REVERSE_HEIGHT);


    drawScreenshot();


}




float iMouse[4] = { 0, 0,0,0 };

float _lineWidth = 1.0f;

void drawCircle(float x, float y, float radius)
{
    static GLuint pid = 0;


    if (pid == 0)
    {
        int length;
        char* str = loadFile("assets/shader/gdi/gdi.vert", length);
        GLuint vid = createShader(str, GL_VERTEX_SHADER);
        str = loadFile("assets/shader/gdi/circle.frag", length);
        GLuint fid = createShader(str, GL_FRAGMENT_SHADER);
        pid = createProgramID(vid, fid);
        destroyShader(vid);
        destroyShader(fid);
    }
    glUseProgram(pid);

    float p[4][4] =
    {
        {x - radius - _lineWidth / 2, y + radius + _lineWidth / 2, 0, 1} , { x + radius + _lineWidth / 2 , y + radius + _lineWidth / 2, 0,1},
        {x - radius - _lineWidth / 2, y - radius - _lineWidth / 2, 0, 1}, { x + radius + _lineWidth / 2, y - radius - _lineWidth / 2, 0,1}
    };

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * 16, p);

    GLuint positionAttr = glGetAttribLocation(pid, "position");
    glEnableVertexAttribArray(positionAttr);
    glVertexAttribPointer(positionAttr, 4, GL_FLOAT, GL_FALSE, 0, (const void*)0);

    GLuint mp = glGetUniformLocation(pid, "mProjection");
    glUniformMatrix4fv(mp, 1, false, mProjection->d());

    GLuint mm = glGetUniformLocation(pid, "mModelview");
    glUniformMatrix4fv(mm, 1, false, mModelview->d());

    GLuint uCenter = glGetUniformLocation(pid, "center");

    glUniform2f(uCenter, x, devSize.height - y);

    GLuint uLineWidth = glGetUniformLocation(pid, "lineWidth");
    glUniform1f(uLineWidth, _lineWidth);


    GLuint uRadius = glGetUniformLocation(pid, "radius");
    glUniform1f(uRadius, radius);



    GLuint uColor = glGetUniformLocation(pid, "color");
    glUniform4f(uColor, _r, _g, _b, _a);


    GLuint uViewport = glGetUniformLocation(pid, "viewport");
    glUniform4fv(uViewport, 1, (float*)&viewport);

    GLuint uDevSize = glGetUniformLocation(pid, "devSize");
    glUniform2fv(uDevSize, 1, (float*)&devSize);

    uint8 indices[6] = { 0, 1, 2, 1, 2, 3 };
    glDrawElements(GL_TRIANGLES, 6 * 1, GL_UNSIGNED_BYTE, indices);


    glDisableVertexAttribArray(positionAttr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

static void keyLib(uint32& key, iKeyState stat, int c)
{
    if (stat == iKeyState::iKeyStateBegan)
    {
        switch (c) {
        case 'a':case 'A':
        case VK_LEFT:   key |= keyboard_left; break;
        case 'd':case 'D':
        case VK_RIGHT:  key |= keyboard_right; break;
        case 'w':case 'W':
        case VK_UP:     key |= keyboard_up; break;
        case 's':case 'S':
        case VK_DOWN:   key |= keyboard_down; break;

        case VK_SPACE:  key |= keyboard_space; break;

        case VK_RETURN: key |= keyboard_enter; break;

        case 49: key |= keyboard_num1; break;

        case 50: key |= keyboard_num2; break;

        case 51: key |= keyboard_num3; break;
        }
    }
    else if (stat == iKeyState::iKeyStateEnded)
    {
        switch (c) {
        case 'a':case 'A':
        case VK_LEFT:   key &= ~keyboard_left; break;
        case 'd':case 'D':
        case VK_RIGHT:  key &= ~keyboard_right; break;
        case 'w':case 'W':
        case VK_UP:     key &= ~keyboard_up; break;
        case 's':case 'S':
        case VK_DOWN:   key &= ~keyboard_down; break;

        case VK_SPACE:  key &= ~keyboard_space; break;


        case VK_RETURN: key &= keyboard_enter; break;

        case 49: key &= keyboard_num1; break;

        case 50: key &= keyboard_num2; break;

        case 51: key &= keyboard_num3; break;


        }
    }
}

void keyLib(iKeyState stat, int c)
{
    if (stat == iKeyState::iKeyStateBegan)
    {
        takeScreenshot = true;
        xprintf("%d\n", c);
        if (keys[c] == false)
            keyLib(keyDown, stat, c);
        keys[c] = true;
    }
    else if (stat == iKeyState::iKeyStateEnded)
    {
        keys[c] = false;
    }
    keyLib(keyStat, stat, c);
}
void resizeLib(int width, int height)
{
    reshapeOpenGL(width, height);
}




iFBO::iFBO(int width, int height)
{
    // renderBuffer(depthBuffer)
    glGenRenderbuffers(1, &depthBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, depthBuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);

    // colorBuffer
    tex = createTexture(width, height, false);
    GLuint texID = tex->texID;

    // frameBuffer
    glGenFramebuffers(1, &fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    GLenum fboBuffs[1] = { GL_COLOR_ATTACHMENT0, };
    glDrawBuffers(1, fboBuffs);//glDrawBuffer(GL_COLOR_ATTACHMENT0);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texID, 0);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthBuffer);
    GLenum stat = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if (stat != GL_FRAMEBUFFER_COMPLETE)
        printf("checkFrameBufferStatus( %d, %d )\n", stat, GL_FRAMEBUFFER_COMPLETE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    prevFbo = 0;
    listTex = (Texture**)malloc(sizeof(Texture*) * 10);
    listNum = 0;
}

iFBO* fbo = NULL;
iFBO::~iFBO()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    glDeleteRenderbuffers(1, &depthBuffer);
    freeImage(tex);

    glDeleteFramebuffers(1, &fbo);

    free(listTex);
}

void iFBO::clear(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void iFBO::bind()
{
    bind(tex);
}

void iFBO::bind(Texture* tex)
{
    if (listNum == 0)
        glGetIntegerv(GL_FRAMEBUFFER_BINDING, &prevFbo);
    listTex[listNum] = tex;
    listNum++;

    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    GLenum fboBuffs[1] = { GL_COLOR_ATTACHMENT0, };
    glDrawBuffers(1, fboBuffs);//glDrawBuffer(GL_COLOR_ATTACHMENT0);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, tex->texID, 0);

    glViewport(0, 0, tex->width, tex->height);
}

void iFBO::unbind()
{
    listNum--;
    if (listNum)
    {
        bind(listTex[listNum - 1]);
        listNum--;
    }
    else
    {
        glBindFramebuffer(GL_FRAMEBUFFER, prevFbo);
        glViewport(viewport.origin.x, viewport.origin.y, viewport.size.width, viewport.size.height);
    }
}

Texture* iFBO::getTexture()
{
    return tex;
}

uint32 iFBO::bindingTexID()
{
    return 0;
}

void setRGBA(float r, float g, float b, float a)
{
    _r = r;
    _g = g;
    _b = b;
    _a = a;
}

void getRGBA(float& r, float& g, float& b, float& a)
{
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void setLineWidth(float lineWidth)
{
    // glLineWidth(lineWidth);
    _lineWidth = lineWidth;
}

void drawLine(float x0, float y0, float x1, float y1)
{
    drawLine(iPointMake(x0, y0), iPointMake(x1, y1));
}



void drawLine(iPoint sp, iPoint ep)
{
    static GLuint pid = 0;


    if (pid == 0)
    {
        int length;
        char* str = loadFile("assets/shader/gdi/gdi.vert", length);
        GLuint vid = createShader(str, GL_VERTEX_SHADER);
        str = loadFile("assets/shader/gdi/line.frag", length);
        GLuint fid = createShader(str, GL_FRAGMENT_SHADER);
        pid = createProgramID(vid, fid);
        destroyShader(vid);
        destroyShader(fid);
    }
    glUseProgram(pid);



    float lw = _lineWidth / 2;
    iPoint c = (sp + ep) / 2;
    float d = iPointDistance(sp, ep) / 2;
    float p[4][4] = {
        { -d - lw , lw , 0 , 1}, { d + lw ,lw, 0,1},
        { -d - lw , -lw , 0 , 1}, {d + lw, -lw, 0 ,1},
    };
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * 16, p);

    GLuint mp = glGetUniformLocation(pid, "mProjection");
    glUniformMatrix4fv(mp, 1, false, mProjection->d());

    GLuint mm = glGetUniformLocation(pid, "mModelview");

    iMatrix mv;
    mv.loadIdentity();
    mv.translate(c.x, c.y, 0);
    float theta = iPointAngle(iPointMake(1, 0), iPointZero, ep - sp);

    mv.rotate(0, 0, 1, theta);
    glUniformMatrix4fv(mm, 1, false, mv.d());

    GLuint positionAttr = glGetAttribLocation(pid, "position");
    glEnableVertexAttribArray(positionAttr);
    glVertexAttribPointer(positionAttr, 4, GL_FLOAT, GL_FALSE, 0, (const void*)0);

    glUniform2f(glGetUniformLocation(pid, "sp"), sp.x, devSize.height - sp.y);
    glUniform2f(glGetUniformLocation(pid, "ep"), ep.x, devSize.height - ep.y);
    glUniform1f(glGetUniformLocation(pid, "lineWidth"), _lineWidth);
    glUniform4f(glGetUniformLocation(pid, "color"), _r, _g, _b, _a);

    uint8 indices[6] = { 0,1,2, 1,2,3 };
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);

    glDisableVertexAttribArray(positionAttr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}



void drawRect(float x, float y, float width, float height, float radius, float degree)
{

    static GLuint pid = 0;

    if (pid == 0)
    {
        int length;
        char* str = loadFile("assets/shader/gdi/gdi.vert", length);
        GLuint vid = createShader(str, GL_VERTEX_SHADER);
        str = loadFile("assets/shader/gdi/rect2.frag", length);
        GLuint fid = createShader(str, GL_FRAGMENT_SHADER);
        pid = createProgramID(vid, fid);
        destroyShader(vid);
        destroyShader(fid);
    }
    glUseProgram(pid);

    float p[4][4] =
    {
        {-width / 2 , height / 2, 0 , 1}, {width / 2, height / 2, 0, 1},
        {-width / 2, -height / 2, 0, 1} , {width / 2, -height / 2, 0, 1},
    };

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * 16, p);



    glUniformMatrix4fv(glGetUniformLocation(pid, "mProjection"), 1, false, mProjection->d());
    iMatrix mv;
    mv.loadIdentity();
    mv.translate((x + width) / 2, (y + height / 2), 0);

    GLuint positionAttr = glGetAttribLocation(pid, "position");
    glEnableVertexAttribArray(positionAttr);
    glVertexAttribPointer(positionAttr, 4, GL_FLOAT, GL_FALSE, 0, (const void*)0);

    glUniformMatrix4fv(glGetUniformLocation(pid, "mModelview"), 1, false, mv.d());
    glUniform4f(glGetUniformLocation(pid, "rect"), x, devSize.height - y, width, height);
    glUniform1f(glGetUniformLocation(pid, "radius"), radius);
    glUniform4f(glGetUniformLocation(pid, "color"), _r, _g, _b, _a);
    glUniform1f(glGetUniformLocation(pid, "lineWidth"), _lineWidth);
    glUniform1f(glGetUniformLocation(pid, "degree"), degree);

    uint8 indices[6] = { 0, 1, 2, 1, 2, 3 };
    glDrawElements(GL_TRIANGLES, 6 * 1, GL_UNSIGNED_BYTE, indices);

    glDisableVertexAttribArray(positionAttr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);


}
void drawRect(iRect rt, float radius, float degree)
{
    drawRect(rt.origin.x, rt.origin.y, rt.size.width, rt.size.height, degree);
}

void fillRect(float x, float y, float width, float height, float radius, float degree)
{


    static GLuint pid = 0;

    if (pid == 0)
    {
        int length;
        char* str = loadFile("assets/shader/gdi/gdi.vert", length);
        GLuint vid = createShader(str, GL_VERTEX_SHADER);
        str = loadFile("assets/shader/gdi/rect.frag", length);
        GLuint fid = createShader(str, GL_FRAGMENT_SHADER);
        pid = createProgramID(vid, fid);
        destroyShader(vid);
        destroyShader(fid);
    }
    glUseProgram(pid);

    float p[4][4] =
    {
        {-width / 2 , height / 2, 0 , 1}, {width / 2, height / 2, 0, 1},
        {-width / 2, -height / 2, 0, 1} , {width / 2, -height / 2, 0, 1},
    };

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * 16, p);



    glUniformMatrix4fv(glGetUniformLocation(pid, "mProjection"), 1, false, mProjection->d());
    iMatrix mv;
    mv.loadIdentity();
    mv.translate((x + width) / 2, (y + height / 2), 0);

    GLuint positionAttr = glGetAttribLocation(pid, "position");
    glEnableVertexAttribArray(positionAttr);
    glVertexAttribPointer(positionAttr, 4, GL_FLOAT, GL_FALSE, 0, (const void*)0);

    glUniformMatrix4fv(glGetUniformLocation(pid, "mModelview"), 1, false, mv.d());
    glUniform4f(glGetUniformLocation(pid, "rect"), x, devSize.height - y, width, height);
    glUniform1f(glGetUniformLocation(pid, "radius"), radius);
    glUniform4f(glGetUniformLocation(pid, "color"), _r, _g, _b, _a);
    glUniform1f(glGetUniformLocation(pid, "degree"), degree);

    uint8 indices[6] = { 0, 1, 2, 1, 2, 3 };
    glDrawElements(GL_TRIANGLES, 6 * 1, GL_UNSIGNED_BYTE, indices);

    glDisableVertexAttribArray(positionAttr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void fillRect(iRect rt, float radius, float degree)
{
    fillRect(rt.origin.x, rt.origin.y, rt.size.width, rt.size.height, radius, degree);
}


void drawCircle(iPoint p, float radius)
{
    drawCircle(p.x, p.y, radius);
}

void fillCircle(iPoint p, float radius)
{
    fillCircle(p.x, p.y, radius);
}

void fillCircle(float x, float y, float radius)
{
    static GLuint pid = 0;


    if (pid == 0)
    {
        int length;
        char* str = loadFile("assets/shader/gdi/gdi.vert", length);
        GLuint vid = createShader(str, GL_VERTEX_SHADER);
        str = loadFile("assets/shader/gdi/circle2.frag", length);
        GLuint fid = createShader(str, GL_FRAGMENT_SHADER);
        pid = createProgramID(vid, fid);
        destroyShader(vid);
        destroyShader(fid);
    }
    glUseProgram(pid);

    float p[4][4] =
    {
        {x - radius - _lineWidth / 2, y + radius + _lineWidth / 2, 0, 1} , { x + radius + _lineWidth / 2 , y + radius + _lineWidth / 2, 0,1},
        {x - radius - _lineWidth / 2, y - radius - _lineWidth / 2, 0, 1}, { x + radius + _lineWidth / 2, y - radius - _lineWidth / 2, 0,1}
    };

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * 16, p);

    GLuint positionAttr = glGetAttribLocation(pid, "position");
    glEnableVertexAttribArray(positionAttr);
    glVertexAttribPointer(positionAttr, 4, GL_FLOAT, GL_FALSE, 0, (const void*)0);

    GLuint mp = glGetUniformLocation(pid, "mProjection");
    glUniformMatrix4fv(mp, 1, false, mProjection->d());

    GLuint mm = glGetUniformLocation(pid, "mModelview");
    glUniformMatrix4fv(mm, 1, false, mModelview->d());


    glUniform2f(glGetUniformLocation(pid, "center"), x, devSize.height - y);
    glUniform1f(glGetUniformLocation(pid, "lineWidth"), _lineWidth);
    glUniform1f(glGetUniformLocation(pid, "radius"), radius);
    glUniform4f(glGetUniformLocation(pid, "color"), _r, _g, _b, _a);



    uint8 indices[6] = { 0, 1, 2, 1, 2, 3 };
    glDrawElements(GL_TRIANGLES, 6 * 1, GL_UNSIGNED_BYTE, indices);


    glDisableVertexAttribArray(positionAttr);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

Texture* createTexture(int width, int height, bool rgba32f)
{
    GLuint texID;
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);

    setTexture(CLAMP, LINEAR);

    if (rgba32f == false)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    }
    else
    {
        //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, width, height, 0, GL_RGBA, GL_HALF_FLOAT, NULL);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_FLOAT, NULL);
    }

    glBindTexture(GL_TEXTURE_2D, 0);

    Texture* tex = (Texture*)malloc(sizeof(Texture));
    tex->texID = texID;
    tex->width = width;
    tex->height = height;
    tex->potWidth = width;
    tex->potHeight = height;
    tex->retainCount = 1;

    return tex;
}

void setTexture(TextureWrap wrap, TextureFilter filter)
{
    GLenum e = (wrap == CLAMP ? GL_CLAMP_TO_EDGE : GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, e);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, e);

    if (filter != MIPMAP)
    {
        e = (filter == NEAREST ? GL_NEAREST : GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, e);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, e);
    }
    else
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
}

int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
    UINT  num = 0;          // number of image encoders
    UINT  size = 0;         // size of the image encoder array in bytes

    ImageCodecInfo* pImageCodecInfo = NULL;

    GetImageEncodersSize(&num, &size);
    if (size == 0)
        return -1;  // Failure

    pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
    if (pImageCodecInfo == NULL)
        return -1;  // Failure

    GetImageEncoders(num, size, pImageCodecInfo);

    for (UINT j = 0; j < num; ++j)
    {
        if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
        {
            *pClsid = pImageCodecInfo[j].Clsid;
            free(pImageCodecInfo);
            return j;  // Success
        }
    }

    free(pImageCodecInfo);
    return -1;  // Failure
}

void saveImageFromRGBA(const char* path, uint8* rgba, int width, int height)
{
    int potWidth = nextPOT(width);
    //int potHeight = nextPOT(height);

    Bitmap* bmp = new Bitmap(width, height, PixelFormat32bppARGB);
    BitmapData bmpData;
    Rect rt(0, 0, width, height);
    bmp->LockBits(&rt, ImageLockModeRead | ImageLockModeWrite, PixelFormat32bppARGB, &bmpData);

    int stride = bmpData.Stride / 4;
    uint8* bgra = (uint8*)bmpData.Scan0;
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            uint8* dst = &bgra[stride * 4 * j + 4 * i];
            uint8* src = &rgba[potWidth * 4 * (height - 1 - j) + 4 * i];
            dst[2] = src[0];
            dst[1] = src[1];
            dst[0] = src[2];
            dst[3] = src[3];
        }
    }

    bmp->UnlockBits(&bmpData);

    wchar_t* wPath = utf8_to_utf16(path);
    CLSID pngClsid;
    GetEncoderClsid(L"image/png", &pngClsid);
    bmp->Save(wPath, &pngClsid);
    free(wPath);
    delete bmp;
}

uint8* bmp2rgba(Bitmap* bmp, int& width, int& height)
{
    width = bmp->GetWidth();
    height = bmp->GetHeight();
    int potWidth = nextPOT(width);
    int potHeight = nextPOT(height);

    BitmapData bmpData;
    Rect rt(0, 0, width, height);
    bmp->LockBits(&rt, ImageLockModeRead, PixelFormat32bppARGB, &bmpData);

    int stride = bmpData.Stride / 4;
    uint8* argb = (uint8*)bmpData.Scan0;
    uint8* rgba = (uint8*)calloc(sizeof(uint8), potWidth * potHeight * 4);
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            uint8* dst = &rgba[potWidth * 4 * j + 4 * i];
            uint8* src = &argb[stride * 4 * j + 4 * i];
            dst[0] = src[2];
            dst[1] = src[1];
            dst[2] = src[0];
            dst[3] = src[3];
        }
    }

    bmp->UnlockBits(&bmpData);

    return rgba;
}

Texture* createImage(const char* szFormat, ...)
{
    va_list args;
    va_start(args, szFormat);

    char szText[1024];
    _vsnprintf(szText, sizeof(szText), szFormat, args);
    va_end(args);

    wchar_t* ws = utf8_to_utf16(szText);
    Bitmap* bmp = new Bitmap(ws);
    free(ws);

    int width, height;
    uint8* rgba = bmp2rgba(bmp, width, height);
    delete bmp;

    Texture* tex = createImageWithRGBA(rgba, width, height);
    free(rgba);

    return tex;
}

void convertGrey(uint8* rgba, int width, int height, int potWidth)
{
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            uint8* c = &rgba[potWidth * 4 * j + 4 * i];
            uint8 grey = (299 * c[0] + 587 * c[1] + 114 * c[2]) / 1000.f;
            c[0] = grey;
            c[1] = grey;
            c[2] = grey;
        }
    }
}

Texture* createGreyImage(const char* szFormat, ...)
{
    va_list args;
    va_start(args, szFormat);

    char szText[1024];
    _vsnprintf(szText, sizeof(szText), szFormat, args);
    va_end(args);

    wchar_t* ws = utf8_to_utf16(szText);
    Bitmap* bmp = new Bitmap(ws);
    free(ws);

    int width, height;
    uint8* rgba = bmp2rgba(bmp, width, height);
    delete bmp;

    convertGrey(rgba, width, height, nextPOT(width));

    Texture* tex = createImageWithRGBA(rgba, width, height);
    free(rgba);

    return tex;
}

uint8* convertReflect(uint8* rgba, int width, int& height, int potWidth, float rateY)
{
    int newHeight = height * rateY;
    int newPotHeight = nextPOT(newHeight);
    uint8* buf = (uint8*)calloc(sizeof(uint8), potWidth * newPotHeight * 4);
    memcpy(buf, rgba, sizeof(uint8) * potWidth * height * 4);

    int remindHeight = newPotHeight - height;
    for (int j = 0; j < remindHeight; j++)
    {
        int J = height * (1.0f * j / remindHeight);
        uint8 a = 0xFF * (1.0f - 1.0f * j / remindHeight);
        for (int i = 0; i < width; i++)
        {
            uint8* dst = &buf[potWidth * 4 * (height + j) + 4 * i];
            uint8* src = &rgba[potWidth * 4 * (height - 1 - J) + 4 * i];
            memcpy(dst, src, sizeof(uint8) * 3);
            dst[3] = a;
        }
    }

    height = newHeight;

    return buf;
}

Texture* createReflectImage(float rateY, const char* szFormat, ...)
{
    va_list args;
    va_start(args, szFormat);

    char szText[1024];
    _vsnprintf(szText, sizeof(szText), szFormat, args);
    va_end(args);

    wchar_t* ws = utf8_to_utf16(szText);
    Bitmap* bmp = new Bitmap(ws);
    free(ws);

    int width, height;
    uint8* rgba = bmp2rgba(bmp, width, height);
    delete bmp;

    uint8* tmp = convertReflect(rgba, width, height, nextPOT(width), rateY);
    free(rgba);

    Texture* tex = createImageWithRGBA(tmp, width, height);
    free(tmp);

    return tex;
}

Texture** createDivideImage(int wNum, int hNum, const char* szFormat, ...)
{
    va_list args;
    va_start(args, szFormat);

    char szText[1024];
    _vsnprintf(szText, sizeof(szText), szFormat, args);
    va_end(args);

    wchar_t* ws = utf8_to_utf16(szText);
    Bitmap* bmp = new Bitmap(ws);
    free(ws);

    int width, height;
    uint8* rgba = bmp2rgba(bmp, width, height);
    delete bmp;

    int potWidth = nextPOT(width);
    int potHeight = nextPOT(height);

    int w = width / wNum;
    int h = height / hNum;
    int potW = nextPOT(w);
    int potH = nextPOT(h);

    Texture** texs = (Texture**)malloc(sizeof(Texture*) * wNum * hNum);
#if 0
    uint8* buf = (uint8*)malloc(sizeof(uint8) * potW * potH * 4);
    for (int j = 0; j < hNum; j++)
    {
        for (int i = 0; i < wNum; i++)
        {
            memset(buf, 0x00, sizeof(uint8) * potW * potH * 4);
            for (int k = 0; k < h; k++)
                memcpy(&buf[potW * 4 * k], &rgba[potWidth * 4 * (h * j + k) + w * 4 * i],
                    sizeof(uint8) * w * 4);

            texs[wNum * j + i] = createImageWithRGBA(buf, w, h);
        }
    }
#else
    int* RGBA = (int*)rgba;
    int* buf = (int*)calloc(sizeof(int), potW * potH);
    for (int j = 0; j < hNum; j++)
    {
        for (int i = 0; i < wNum; i++)
        {
            // BUF <=   w * i, h * j    RGBA
            for (int n = 0; n < h; n++)
            {
                //for (int m = 0; m < w; m++)
                //    buf[potW * n + m] = RGBA[potWidth * (h * j + n) + w * i + m];
                memcpy(&buf[potW * n], &RGBA[potWidth * (h * j + n) + w * i], sizeof(int) * w);
            }
            texs[wNum * j + i] = createImageWithRGBA((GLubyte*)buf, w, h);
        }
    }
#endif

    free(buf);

    return texs;
}


void freeImage(Texture* tex)
{
    if (tex->retainCount > 1)
    {
        tex->retainCount--;
        return;
    }
    glDeleteTextures(1, &tex->texID);
    free(tex);
#ifdef _DEBUG
    texNum--;
#endif
}

#ifdef _DEBUG
int texNum = 0;
#endif

void drawImageLikeCircle(Texture* tex, int x, int y, float rate)
{
#define DEGREE 360//360
    float position[DEGREE][6];
    float coordinate[DEGREE][6];
    short indices[DEGREE][3];
    for (int i = 0; i < DEGREE; i++)
    {
        //////////////////////////////////////
        position[i][0] = x;
        position[i][1] = y;

        iPoint p0 = { x + tex->width / 2 * rate, y };
        iPoint p1 = iPointRotate(p0, iPointMake(x, y), i);
        if (p1.x < x - tex->width / 2) p1.x = x - tex->width / 2;
        else if (p1.x > x + tex->width / 2) p1.x = x + tex->width / 2;
        if (p1.y < y - tex->height / 2) p1.y = y - tex->height / 2;
        else if (p1.y > y + tex->height / 2) p1.y = y + tex->height / 2;
        position[i][2] = p1.x;
        position[i][3] = p1.y;

        p1 = iPointRotate(p0, iPointMake(x, y), 1 + i);
        if (p1.x < x - tex->width / 2) p1.x = x - tex->width / 2;
        else if (p1.x > x + tex->width / 2) p1.x = x + tex->width / 2;
        if (p1.y < y - tex->height / 2) p1.y = y - tex->height / 2;
        else if (p1.y > y + tex->height / 2) p1.y = y + tex->height / 2;
        position[i][4] = p1.x;
        position[i][5] = p1.y;
        ///////////////////////////////////////
        coordinate[i][0] = tex->width / tex->potWidth / 2;
        coordinate[i][1] = tex->height / tex->potHeight / 2;

        iPoint c0 = { coordinate[i][0] + 0.5f * rate, coordinate[i][1] };
        iPoint c1 = iPointRotate(c0, iPointMake(coordinate[i][0], coordinate[i][1]), i);
        if (c1.x < 0.0f) c1.x = 0.0f; else if (c1.x > 1.0f) c1.x = 1.0f;
        if (c1.y < 0.0f) c1.y = 0.0f; else if (c1.y > 1.0f) c1.y = 1.0f;
        coordinate[i][2] = c1.x;
        coordinate[i][3] = c1.y;

        c1 = iPointRotate(c0, iPointMake(coordinate[i][0], coordinate[i][1]), 1 + i);
        if (c1.x < 0.0f) c1.x = 0.0f; else if (c1.x > 1.0f) c1.x = 1.0f;
        if (c1.y < 0.0f) c1.y = 0.0f; else if (c1.y > 1.0f) c1.y = 1.0f;
        coordinate[i][4] = c1.x;
        coordinate[i][5] = c1.y;

        //////////////////////////////////////
        indices[i][0] = 3 * i + 0;
        indices[i][1] = 3 * i + 1;
        indices[i][2] = 3 * i + 2;
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    //glEnableClientState(GL_COLOR_ARRAY);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex->texID);

    glVertexPointer(2, GL_FLOAT, 0, position);
    glTexCoordPointer(2, GL_FLOAT, 0, coordinate);
    //glColorPointer(4, GL_FLOAT, 0, color);

    glDrawElements(GL_TRIANGLES, DEGREE * 3, GL_UNSIGNED_SHORT, indices);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    //glDisableClientState(GL_COLOR_ARRAY);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void drawImage(Texture* tex, int x, int y, int anc)
{
    drawImage(tex, x, y,
        0, 0, tex->width, tex->height,
        anc, 1.0f, 1.0f, 2, 0, REVERSE_NONE);
}

void drawImage(Texture* tex, int x, int y,
    int ix, int iy, int iw, int ih, int anc,
    float ratX, float ratY,
    int xyz, float degree, int reverse)
{

    int width = tex->width * ratX;
    int height = tex->height * ratY;
    switch (anc) {
    case TOP | LEFT:                                         break;
    case TOP | HCENTER:     x -= width / 2;                  break;
    case TOP | RIGHT:       x -= width;                      break;
    case VCENTER | LEFT:                    y -= height / 2; break;
    case VCENTER | HCENTER: x -= width / 2; y -= height / 2; break;
    case VCENTER | RIGHT:   x -= width;     y -= height / 2; break;
    case BOTTOM | LEFT:                     y -= height;     break;
    case BOTTOM | HCENTER:  x -= width / 2; y -= height;     break;
    case BOTTOM | RIGHT:    x -= width;     y -= height;     break;
    }
    gVbo->qNum = 1;
    iQuad* q = &gVbo->q[0];
    q->tl.p[0] = x, q->tl.p[1] = y;
    q->tr.p[0] = x + width, q->tr.p[1] = y;
    q->bl.p[0] = x, q->bl.p[1] = y + height;
    q->br.p[0] = x + width, q->br.p[1] = y + height;

    q->tl.uv.x = ix / tex->potWidth, q->tl.uv.y = iy / tex->potHeight;
    q->tr.uv.x = (ix + iw) / tex->potWidth, q->tr.uv.y = iy / tex->potHeight;
    q->bl.uv.x = ix / tex->potWidth, q->bl.uv.y = (iy + ih) / tex->potHeight;
    q->br.uv.x = (ix + iw) / tex->potWidth, q->br.uv.y = (iy + ih) / tex->potHeight;

    iColor4b c = iColor4bMake(_r * 0xff, _g * 0xff, _b * 0xff, _a * 0xff);
    q->tl.c = c;
    q->tr.c = c;
    q->bl.c = c;
    q->br.c = c;

    if (reverse & REVERSE_WIDTH)
    {
        float t = q->tl.p[0];
        q->tl.p[0] = q->tr.p[0];
        q->tr.p[0] = t;

        t = q->bl.p[0];
        q->bl.p[0] = q->br.p[0];
        q->br.p[0] = t;
    }
    if (reverse & REVERSE_HEIGHT)
    {
        float t = q->tl.p[1];
        q->tl.p[1] = q->bl.p[1];
        q->bl.p[1] = t;

        t = q->tr.p[1];
        q->tr.p[1] = q->br.p[1];
        q->br.p[1] = t;

    }

    float m[16];
    memcpy(m, mModelview->d(), sizeof(float) * 16);

    if (degree)
    {
        iPoint t = iPointMake(x + width / 2, y + height / 2);
        q->tl.p[0] -= t.x, q->tl.p[1] -= t.y;
        q->tr.p[0] -= t.x, q->tr.p[1] -= t.y;
        q->bl.p[0] -= t.x, q->bl.p[1] -= t.y;
        q->br.p[0] -= t.x, q->br.p[1] -= t.y;
        mModelview->translate(t.x, t.y, 0);

        float _xyz[3] = { 0, 0, 0 };
        _xyz[xyz] = 1.0f;
        while (degree > 360) degree -= 360;
        degree = 360 - degree;
        mModelview->rotate(_xyz[0], _xyz[1], _xyz[2], degree);
    }

    gVbo->tex = tex;
    gVbo->programID = getProgramID();
    gVbo->paint(0.0f);


    memcpy(mModelview->d(), m, sizeof(float) * 16);

}

void setClip(int x, int y, int width, int height)
{
    if (x == 0 && y == 0 && width == 0 && height == 0)
        glDisable(GL_SCISSOR_TEST);
    else
    {
        glEnable(GL_SCISSOR_TEST);
        glScissor(x, devSize.height - y - height, width, height);// 반전되어있기 때문임.
    }
}

void setClip(iRect rt)
{
    setClip(rt.origin.x, rt.origin.y, rt.size.width, rt.size.height);
}

void setStringName(const char* name)
{
    if (_stringName)
    {
        if (strcmp(_stringName, name) == 0)
            return;
        free(_stringName);
    }

    char* s = (char*)calloc(sizeof(char), 1 + strlen(name));
    strcpy(s, name);
    _stringName = s;
}

const char* getStringName() { return _stringName; }
float getStringSize() { return _stringSize; }

void setStringSize(float size)
{
    _stringSize = size;
}

void setStringRGBA(float r, float g, float b, float a)
{
    _stringR = r;
    _stringG = g;
    _stringB = b;
    _stringA = a;
}

void getStringRGBA(float& r, float& g, float& b, float& a)
{
    r = _stringR;
    g = _stringG;
    b = _stringB;
    a = _stringA;
}

void setStringBorder(float size)
{
    _stringBorder = size;
}

float getStringBorder()
{
    return _stringBorder;
}

void setStringBorderRGBA(float r, float g, float b, float a)
{
    _stringBorderR = r;
    _stringBorderG = g;
    _stringBorderB = b;
    _stringBorderA = a;
}
void getStringBorderRGBA(float& r, float& g, float& b, float& a)
{
    r = _stringBorderR;
    g = _stringBorderG;
    b = _stringBorderB;
    a = _stringBorderA;
}
#if 1

iRect rectOfString(uint8* rgba, int width, int height)
{
    iRect rt;

    // 왼쪽에서 오른쪽 찾아감
    for (int i = 0; i < width; i++)
    {
        bool found = false;
        for (int j = 0; j < height; j++)
        {
            if (rgba[width * 4 * j + 4 * i + 3])
            {
                rt.origin.x = i;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    // 오른쪽에서 왼쪽 찾아감
    for (int i = width - 1; i > -1; i--)
    {
        bool found = false;
        for (int j = 0; j < height; j++)
        {
            if (rgba[width * 4 * j + 4 * i + 3])
            {
                rt.size.width = i - rt.origin.x - 1;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    // 위에서 아래로 찾아감
    for (int j = 0; j < height; j++)
    {
        bool found = false;
        for (int i = 0; i < width; i++)
        {
            if (rgba[width * 4 * j + 4 * i + 3])
            {
                rt.origin.y = j;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    // 아래에서 위로 찾아감
    for (int j = height - 1; j > -1; j--)
    {
        bool found = false;
        for (int i = 0; i < width; i++)
        {
            if (rgba[width * 4 * j + 4 * i + 3])
            {
                rt.size.height = j - rt.origin.y - 1;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    return rt;
}

iSize sizeOfString(const char* szFormat, ...)
{
    /////////////////////////////////////////////////////// initialize
    static Bitmap* bmp = NULL;
    static Graphics* g;
    if (bmp == NULL)
    {
        bmp = new Bitmap(devSize.width, devSize.height, PixelFormat32bppARGB);
        g = Graphics::FromImage(bmp);
        g->SetPageUnit(UnitPixel);
        g->SetPixelOffsetMode(PixelOffsetModeHalf);
        g->SetTextRenderingHint(TextRenderingHintClearTypeGridFit);
        g->SetSmoothingMode(SmoothingModeAntiAlias8x8);
        g->SetInterpolationMode(InterpolationModeHighQualityBicubic);
    }
    g->Clear(Color(0, 0, 0, 0));

    /////////////////////////////////////////////////////// drawString
    va_list args;
    va_start(args, szFormat);

    char szText[1024];
    _vsnprintf(szText, sizeof(szText), szFormat, args);
    va_end(args);

    wchar_t* wStr = utf8_to_utf16(szText);

    GraphicsPath path;
    FontFamily  fontFamily;
    PointF      pointF(0, 0);
    StringFormat sf;

    int fontStyle;
    checkFontFamily(&fontFamily, fontStyle);

    path.AddString(wStr, lstrlenW(wStr), &fontFamily, fontStyle,
        getStringSize(), pointF, &sf);

    float gr, gg, gb, ga;
    getStringRGBA(gr, gg, gb, ga);
    SolidBrush brush(Color(float2uint8(ga),
        float2uint8(gr),
        float2uint8(gg),
        float2uint8(gb)));
    g->FillPath(&brush, &path);

    float sb = getStringBorder();
    if (sb)
    {
        getStringBorderRGBA(gr, gg, gb, ga);
        Pen pen(Color(float2uint8(ga),
            float2uint8(gr),
            float2uint8(gg),
            float2uint8(gb)));
        pen.SetWidth(sb);
        g->DrawPath(&pen, &path);
    }

    free(wStr);

    /////////////////////////////////////////////////////// rectOfString
    BitmapData bmpData;
    Rect rt(0, 0, devSize.width, devSize.height);
    bmp->LockBits(&rt, ImageLockModeRead, PixelFormat32bppARGB, &bmpData);

    uint8* argb = (uint8*)bmpData.Scan0;
    iRect rect = rectOfString(argb, devSize.width, devSize.height);

    bmp->UnlockBits(&bmpData);

    return rect.size;
}

#else
iSize sizeOfString(const char* szFormat, ...)
{
    va_list args;
    va_start(args, szFormat);
    char szText[1024];
    _vsnprintf(szText, sizeof(szText), szFormat, args);
    va_end(args);
    wchar_t* wStringName = utf8_to_utf16(_stringName);
    wchar_t* wStr = utf8_to_utf16(szText);
    GraphicsPath path;
    FontFamily  fontFamily(wStringName);
    PointF      pointF(0, 0);
    StringFormat sf;// top|left
    //sf.SetFormatFlags();
    GraphicsPath p;
    p.AddString(wStr, lstrlenW(wStr), &fontFamily, FontStyleRegular,
        _stringSize, pointF, &sf);
    Rect rt;
    p.GetBounds(&rt);
    free(wStringName);
    free(wStr);
    return iSizeMake(rt.Width, rt.Height);
}
#endif
void drawString(int x, int y, int anc, const char* szFormat, ...)
{
    // #bug
}

#define W 32
#define R 16
#define P 0
#define M1 13
#define M2 9
#define M3 5

#define MAT0POS(t,v) (v^(v>>t))
#define MAT0NEG(t,v) (v^(v<<(-(t))))
#define MAT3NEG(t,v) (v<<(-(t)))
#define MAT4NEG(t,b,v) (v ^ ((v<<(-(t))) & b))

#define V0            STATE[state_i                   ]
#define VM1           STATE[(state_i+M1) & 0x0000000fU]
#define VM2           STATE[(state_i+M2) & 0x0000000fU]
#define VM3           STATE[(state_i+M3) & 0x0000000fU]
#define VRm1          STATE[(state_i+15) & 0x0000000fU]
#define VRm2          STATE[(state_i+14) & 0x0000000fU]
#define newV0         STATE[(state_i+15) & 0x0000000fU]
#define newV1         STATE[state_i                 ]
#define newVRm1       STATE[(state_i+14) & 0x0000000fU]

#define FACT 2.32830643653869628906e-10

static unsigned int state_i = 0;
static unsigned int STATE[R];
static unsigned int z0, z1, z2;

void sRandom() {
    int j;
    state_i = 0;
    for (j = 0; j < R; j++)
        STATE[j] = rand();
}

uint32 random()
{
#if 1
    return rand();
#else
    z0 = VRm1;
    z1 = MAT0NEG(-16, V0) ^ MAT0NEG(-15, VM1);
    z2 = MAT0POS(11, VM2);
    newV1 = z1 ^ z2;
    newV0 = MAT0NEG(-2, z0) ^ MAT0NEG(-18, z1) ^ MAT3NEG(-28, z2) ^ MAT4NEG(-5, 0xda442d24U, newV1);
    state_i = (state_i + 15) & 0x0000000fU;
    return STATE[state_i] * FACT;
#endif
}

float _sin(float degree)
{
    return sin(M_PI / 180 * degree);
}

float _cos(float degree)
{
    return cos(M_PI / 180 * degree);
}

float linear(float r, float a, float b)
{
    return a + (b - a) * r;
}

iPoint linear(float r, iPoint a, iPoint b)
{
    return a + (b - a) * r;
}

float easeIn(float r, float a, float b)
{
    return a + (b - a) * _sin(90 * r);
}

iPoint easeIn(float r, iPoint a, iPoint b)
{
    return a + (b - a) * _sin(90 * r);
}

float easeOut(float r, float a, float b)
{
    return a + (b - a) * (1 + _sin(270 + 90 * r));
    //return a + (b - a) * r * r;
}

iPoint easeOut(float r, iPoint a, iPoint b)
{
    return a + (b - a) * (1 + _sin(270 + 90 * r));
    //return a + (b - a) * r * r;
}

float easeInOut(float r, float a, float b)
{
    if (r < 0.5f)
        easeIn(r * 2.0f, a, a + (b - a) / 2);
    return easeOut((r - 0.5f) * 2.0f, a + (b - a) / 2, b);
}

iPoint easeInOut(float r, iPoint a, iPoint b)
{
    if (r < 0.5f)
        easeIn(r * 2.0f, a, a + (b - a) / 2);
    return easeOut((r - 0.5f) * 2.0f, a + (b - a) / 2, b);
}

bool containPoint(iPoint p, iRect rt)
{
    if (p.x < rt.origin.x ||
        p.x > rt.origin.x + rt.size.width ||
        p.y < rt.origin.y ||
        p.y > rt.origin.y + rt.size.height)
        return false;
    return true;
}

bool containRect(iRect src, iRect dst)
{
    if (src.origin.x + src.size.width < dst.origin.x ||
        src.origin.x > dst.origin.x + dst.size.width ||
        src.origin.y + src.size.height < dst.origin.y ||
        src.origin.y > dst.origin.y + dst.size.height)
        return false;

    return true;
}

char* loadFile(const char* filePath, int& length)
{
    FILE* pf = fopen(filePath, "rb");

    fseek(pf, 0, SEEK_END);
    length = ftell(pf);
    char* buf = (char*)calloc(sizeof(char), 1 + length);
    fseek(pf, 0, SEEK_SET);//rewind(pf);
    fread(buf, length, 1, pf);

    fclose(pf);

    return buf;
}

void saveFile(const char* filePath, char* buf, int bufLength)
{
    FILE* pf = fopen(filePath, "wb");

    fwrite(buf, bufLength, 1, pf);

    fclose(pf);
}

iVBO::iVBO(int qNum_)
{
    _qNum = qNum_;
    qNum = 0;
    q = (iQuad*)malloc(sizeof(iQuad) * _qNum);

    indices = (short*)malloc(sizeof(short) * 6 * _qNum);

    for (int i = 0; i < _qNum; i++)
    {
        iQuad* quad = &q[i];
        quad->tl.p[2] = 0; quad->tl.p[3] = 1;
        quad->tr.p[2] = 0; quad->tr.p[3] = 1;
        quad->bl.p[2] = 0; quad->bl.p[3] = 1;
        quad->br.p[2] = 0; quad->br.p[3] = 1;
        quad->tl.uv = iPointMake(0, 0);
        quad->tr.uv = iPointMake(1, 0);
        quad->bl.uv = iPointMake(0, 1);
        quad->br.uv = iPointMake(1, 1);

        indices[6 * i + 0] = 4 * i + 0;
        indices[6 * i + 1] = 4 * i + 1;
        indices[6 * i + 2] = 4 * i + 2;
        indices[6 * i + 3] = 4 * i + 1;
        indices[6 * i + 4] = 4 * i + 2;
        indices[6 * i + 5] = 4 * i + 3;
    }

    tex = NULL;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(iQuad) * _qNum, NULL, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    programID = 0;
}

iVBO::~iVBO()
{
    free(q);
    free(indices);
    freeImage(tex);
    glDeleteBuffers(1, &vbo);
}

void iVBO::paint(float dt)
{
    glUseProgram(programID);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(iQuad) * qNum, q);

    GLuint positionAttr = glGetAttribLocation(programID, "position");
    GLuint texCoordAttr = glGetAttribLocation(programID, "texCoord");
    GLuint colorAttr = glGetAttribLocation(programID, "color");

    glEnableVertexAttribArray(positionAttr);
    glEnableVertexAttribArray(texCoordAttr);
    glEnableVertexAttribArray(colorAttr);

    glVertexAttribPointer(positionAttr, 4, GL_FLOAT, GL_FALSE, sizeof(iVertex), (const void*)0);
    glVertexAttribPointer(texCoordAttr, 2, GL_FLOAT, GL_FALSE, sizeof(iVertex), (const void*)offsetof(iVertex, uv));
    glVertexAttribPointer(colorAttr, 4, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(iVertex), (const void*)offsetof(iVertex, c));

    GLuint tid = glGetUniformLocation(programID, "texID");
    glUniform1i(tid, 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex->texID);


    GLuint mp = glGetUniformLocation(programID, "mProjection");
    glUniformMatrix4fv(mp, 1, false, mProjection->d());
    GLuint mm = glGetUniformLocation(programID, "mModelview");
    glUniformMatrix4fv(mm, 1, false, mModelview->d());

    glDrawElements(GL_TRIANGLES, 6 * qNum, GL_UNSIGNED_SHORT, indices);

    glDisableVertexAttribArray(positionAttr);
    glDisableVertexAttribArray(texCoordAttr);
    glDisableVertexAttribArray(colorAttr);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void convertColor(iColor4f color, uint8* rgba, int width, int height, int potWidth)
{
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            uint8* c = &rgba[potWidth * 4 * j + 4 * i];
            c[0] *= color.r;
            c[1] *= color.g;
            c[2] *= color.b;
            c[3] *= color.a;
        }
    }
}


Texture* createColorImage(iColor4f c, const char* szFormat, ...)
{
    va_list args;
    va_start(args, szFormat);

    char szText[1024];
    _vsnprintf(szText, sizeof(szText), szFormat, args);
    va_end(args);

    wchar_t* ws = utf8_to_utf16(szText);
    Bitmap* bmp = new Bitmap(ws);
    free(ws);

    int width, height;
    uint8* rgba = bmp2rgba(bmp, width, height);
    delete bmp;

    convertColor(c, rgba, width, height, nextPOT(width));

    Texture* tex = createImageWithRGBA(rgba, width, height);
    free(rgba);

    return tex;
}