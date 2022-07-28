#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"setting.h"
#include"DinoEntity.h"
#include"TreeEntity.h"

class Game_manager
{
public:
	int _Score = 0;				// 점수
	int _CurKey = -1;			// 현재 눌린 키
	bool _IsJumpping = false;	// 현재 공룡이 점프 중인가
	bool _maxHeight = false;	// 현재 공룡이 점프하여 최고 지점에 올랐는가
	bool bIsCollision = false;	// 현재 공룡이 나무와 충돌하였는가
public:
	void Init();
	int GetKeyDown();
	void CursorSetting();
	void MoveCursor(int dinoX, int dinoY);
	void drawScore(int score);
	void drawEnd(int score);
	void GameStart();
};