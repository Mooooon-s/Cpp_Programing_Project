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
	int _Score = 0;				// ����
	int _CurKey = -1;			// ���� ���� Ű
	bool _IsJumpping = false;	// ���� ������ ���� ���ΰ�
	bool _maxHeight = false;	// ���� ������ �����Ͽ� �ְ� ������ �ö��°�
	bool bIsCollision = false;	// ���� ������ ������ �浹�Ͽ��°�
public:
	void Init();
	int GetKeyDown();
	void CursorSetting();
	void MoveCursor(int dinoX, int dinoY);
	void drawScore(int score);
	void drawEnd(int score);
	void GameStart();
};