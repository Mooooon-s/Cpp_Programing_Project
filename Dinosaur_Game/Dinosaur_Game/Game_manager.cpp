#include "Game_manager.h"
#include<iostream>


void Game_manager::Init() {
	system("mode con:cols=100 lines=25");
	system("title Dino");
}

int Game_manager::GetKeyDown() {
	if (_kbhit() != 0)
		return _getch();
	return 0;
}

void Game_manager::CursorSetting()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Game_manager::MoveCursor(int dinoX,int dinoY) {
	COORD cursorPos = { (SHORT)dinoX, (SHORT)dinoY };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
}

void Game_manager::drawScore(int score) {
	MoveCursor(0, 0);
	std::cout << "Score: " << score << "\n";
}

void Game_manager::GameStart() {
	
	Entity *entity=new Entity;

	while (true)
	{
		// ���� ���
		drawScore(nScore);

		// Ű �Է� Ȯ��
		nCurKey = GetKeyDown();
		switch (nCurKey)
		{
		case KEY_ESC:		// ESC Ű
			return;
		case KEY_SPACE:		// SPACE BAR Ű
			bIsJumpping = true;
			break;
		default:
			break;
		}

		// ���� ����
		// ���� ���ΰ�
		if (bIsJumpping)
		{
			// �ְ� ������ �̸��� �ʾҴٸ�
			if(dinoY < MAX_JUMP && bIsJumpped == false)
				dinoY++;
			// �ְ� ������ ���� �� ������ �����ٸ�
			else if (bIsJumpped && dinoY == 0)
			{
				bIsJumpped = false;
				bIsJumpping = false;
			}
			// �ְ� ������ ���� �Ķ�� (�߷��� ǥ��)
			else if (bIsJumpped)
				dinoY--;
			// �ְ� ������ �����ߴٸ�
			else if (dinoY == MAX_JUMP)
				bIsJumpped = true;
		}
		// ���� ���� �ƴ϶��
		else
		{
			if (dinoY > 0)
				dinoY--;
		}

		// ���� ��ġ ����
		treeX -= 2;
		if(treeX <=0)
			treeX = TREE_START;

		 //�浹 ����
		 //������ X��ġ�� �浹 ���� X��ġ���
		if (treeX < TREE_COLLISION)
		{
			// ������ Y��ġ�� �浹 ���� ��ġ�̰�
			// ������ X��ġ�� �浹 ���� ��ġ���
			if (dinoY < Y_COLLISION && treeX > TREE_END + 1)
				bIsCollision = true;
		}

		//��ƼƼ �׸���
		entity->drawTree(treeX);
		entity->drawDino(dinoY);

		Sleep(SLEEP_TIME);
		system("cls");

		// �浹 �� ���� ����
		if (bIsCollision)
		{
			std::cout<<"\n";
			std::cout << "\n";
			std::cout << "            Game Over\n";
			std::cout << "           "<< nScore<<"\n";
			system("pause");
			return;
		}
		// �浹 ���°� �ƴ� ���� ���� ����
		else
		{
			nScore += 1;
		}
	}
	delete entity;
}