#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"setting.h"
#include"Entity.h"

class Game_manager
{
public:
	int nScore = 0;				// ����
	int nCurKey = -1;			// ���� ���� Ű

	int dinoY = 0;				// ������ Y��ġ (������ ����)
	int treeX = TREE_START;	// ������ �����Ǵ� �ʱ� X��ġ
	bool bIsJumpping = false;	// ���� ������ ���� ���ΰ�
	bool bIsJumpped = false;	// ���� ������ �����Ͽ� �ְ� ������ �ö��°�
	bool bIsCollision = false;	// ���� ������ ������ �浹�Ͽ��°�
public:
	void Init();
	int GetKeyDown();
	void CursorSetting();
	void MoveCursor(int dinoX, int dinoY);
	void drawScore(int score);
	void GameStart();
};

