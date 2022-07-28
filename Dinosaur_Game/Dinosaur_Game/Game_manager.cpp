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

void Game_manager::drawEnd(int score) {
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "            Game Over\n";
	std::cout << "           " << _Score << "\n";
	system("pause");
}

void Game_manager::GameStart() {
	
	DinoEntity* dino = new DinoEntity;
	TreeEntity* tree = new TreeEntity;

	while (true)
	{
		// Ű �Է� Ȯ��
		_CurKey = GetKeyDown();
		switch (_CurKey)
		{
		case KEY_ESC:		// ESC Ű
			return;
		case KEY_SPACE:		// SPACE BAR Ű
			_IsJumpping = true;
			break;
		default:
			break;
		}

		int Dinoy = dino->Y();
		// ���� ���ΰ�
		if (_IsJumpping)
		{
			// �ְ� ������ �̸��� �ʾҴٸ�
			if (Dinoy < MAX_JUMP && _maxHeight == false)
				Dinoy++;
			// �ְ� ������ ���� �� ������ �����ٸ�
			else if (_maxHeight && Dinoy == 0)
			{
				_maxHeight = false;
				_IsJumpping = false;
			}
			// �ְ� ������ ���� �Ķ�� (�߷��� ǥ��)
			else if (_maxHeight)
				Dinoy--;
			// �ְ� ������ �����ߴٸ�
			else if (Dinoy == MAX_JUMP)
				_maxHeight = true;
		}
		// ���� ���� �ƴ϶��
		else
		{
			if (Dinoy > 0)
				Dinoy--;
		}

		dino->setDinoY(Dinoy);
		int treeX = tree->X();
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
			if (Dinoy  < Y_COLLISION && treeX > TREE_END + 1)
				bIsCollision = true;
		}

		//��ƼƼ �׸���
		tree->setTreeX(treeX);
		tree->drawEntity();
		dino->drawEntity();

		Sleep(SLEEP_TIME);
		system("cls");

		// �浹 �� ���� ����
		if (bIsCollision)
		{
			// ���� ���
			drawEnd(_Score);
			return ;
		}
		// �浹 ���°� �ƴ� ���� ���� ����
		else
		{
			_Score += 1;
			drawScore(_Score);
		}
	}
}