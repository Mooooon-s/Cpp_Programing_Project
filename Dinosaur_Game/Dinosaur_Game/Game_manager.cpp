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
		// 키 입력 확인
		_CurKey = GetKeyDown();
		switch (_CurKey)
		{
		case KEY_ESC:		// ESC 키
			return;
		case KEY_SPACE:		// SPACE BAR 키
			_IsJumpping = true;
			break;
		default:
			break;
		}

		int Dinoy = dino->Y();
		// 점프 중인가
		if (_IsJumpping)
		{
			// 최고 지점에 이르지 않았다면
			if (Dinoy < MAX_JUMP && _maxHeight == false)
				Dinoy++;
			// 최고 지점에 도달 후 점프가 끝났다면
			else if (_maxHeight && Dinoy == 0)
			{
				_maxHeight = false;
				_IsJumpping = false;
			}
			// 최고 지점에 도달 후라면 (중력을 표현)
			else if (_maxHeight)
				Dinoy--;
			// 최고 지점에 도달했다면
			else if (Dinoy == MAX_JUMP)
				_maxHeight = true;
		}
		// 점프 중이 아니라면
		else
		{
			if (Dinoy > 0)
				Dinoy--;
		}

		dino->setDinoY(Dinoy);
		int treeX = tree->X();
		// 나무 위치 관련
		treeX -= 2;
		if(treeX <=0)
			treeX = TREE_START;

		 //충돌 관련
		 //나무의 X위치가 충돌 가능 X위치라면
		if (treeX < TREE_COLLISION)
		{
			// 공룡의 Y위치가 충돌 가능 위치이고
			// 나무의 X위치가 충돌 가능 위치라면
			if (Dinoy  < Y_COLLISION && treeX > TREE_END + 1)
				bIsCollision = true;
		}

		//엔티티 그리기
		tree->setTreeX(treeX);
		tree->drawEntity();
		dino->drawEntity();

		Sleep(SLEEP_TIME);
		system("cls");

		// 충돌 시 게임 오버
		if (bIsCollision)
		{
			// 점수 출력
			drawEnd(_Score);
			return ;
		}
		// 충돌 상태가 아닐 때는 점수 증가
		else
		{
			_Score += 1;
			drawScore(_Score);
		}
	}
}