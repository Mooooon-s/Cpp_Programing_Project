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
	bool _Collision = false;	// ���� ������ ������ �浹�Ͽ��°�
public:
	void Init();
	int GetKeyDown();
	void CursorSetting();
	void gotoXY(int X, int Y);
	void drawScore(int score);
	void drawEnd(int score);
	void GameStart();
};