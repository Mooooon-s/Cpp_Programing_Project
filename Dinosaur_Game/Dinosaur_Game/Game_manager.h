#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"setting.h"
#include"Entity.h"

class Game_manager
{
public:
	int nScore = 0;				// 점수
	int nCurKey = -1;			// 현재 눌린 키

	int dinoY = 0;				// 공룡의 Y위치 (점프에 쓰임)
	int treeX = TREE_START;	// 나무가 생성되는 초기 X위치
	bool bIsJumpping = false;	// 현재 공룡이 점프 중인가
	bool bIsJumpped = false;	// 현재 공룡이 점프하여 최고 지점에 올랐는가
	bool bIsCollision = false;	// 현재 공룡이 나무와 충돌하였는가
public:
	void Init();
	int GetKeyDown();
	void CursorSetting();
	void MoveCursor(int dinoX, int dinoY);
	void drawScore(int score);
	void GameStart();
};

