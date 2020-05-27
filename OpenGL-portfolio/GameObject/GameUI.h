#pragma once
#include "iStd.h"




Texture* methodTimeIndicator(const char* str);
Texture* methodKillIndicator(const char* str);
Texture* methodPlayerHPIndicator(const char* str);
Texture* methodPlayerMPIndicator(const char* str);
Texture* methodPlayerStaminaIndicator(const char* str);
Texture* methodPlayerExpIndicator(const char* str);

// 여기에 플레이어의 체력, 게임 플레이상의 UI 출력해야함 

//-------------PopPlayerUI----------------------//
void createPopPlayerUI();
void freePopPlayerUI();
void drawPopPlayerUI(float dt);
bool keyPopPlayerUI(iKeyState stat, iPoint point);
void showPopPlayerUI(bool show);

//------------PopMenuUI------------------------// 
void createPopMenuUI();
void freePopMenuUI();
void drawPopMenuUI(float dt);
bool keyPopMenuUI(iKeyState stat, iPoint point);
void showPopMenuUI(bool show);

//------------PopQuitAnswerUI------------------//
void createPopQuitAnswerUI();
void freePopQuitAnswerUI();
void drawPopQuitAnswerUI(float dt);
bool keyPopQuitAnswerUI(iKeyState stat, iPoint point);
void showPopQuitAnswerUI(bool show);



//-------------PopGameOverUI---------------------//
void createPopGameOverUI();
void freePopGameOverUI();
void drawPopGameOverUI(float dt);
bool keyPopGameOverUI(iKeyState stat, iPoint point);
void showPopGameOverUI(bool show);

//-------------PopStageNPCMenuUI----------------//
void createPopStageNPCMenuUI();
void freePopStageNPCMenuUI();
void drawPopStageNPCMenuUI(float dt);
bool keyPopStageNPCMenuUI(iKeyState stat, iPoint point);
void showPopStageNPCMenuUI(bool show);

//-------------PopPlayerInventory---------------//
void createPopPlayerInventory();
void freePopPlayerInventory();
void drawPopPlayerInventory(float dt);
bool keyPopPlayerInventory(iKeyState stat, iPoint point);
void showPopPlayerInventory(bool show);