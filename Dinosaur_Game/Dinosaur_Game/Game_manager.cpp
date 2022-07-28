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
		// 점수 출력
		drawScore(nScore);

		// 키 입력 확인
		nCurKey = GetKeyDown();
		switch (nCurKey)
		{
		case KEY_ESC:		// ESC 키
			return;
		case KEY_SPACE:		// SPACE BAR 키
			bIsJumpping = true;
			break;
		default:
			break;
		}

		// 점프 관련
		// 점프 중인가
		if (bIsJumpping)
		{
			// 최고 지점에 이르지 않았다면
			if(dinoY < MAX_JUMP && bIsJumpped == false)
				dinoY++;
			// 최고 지점에 도달 후 점프가 끝났다면
			else if (bIsJumpped && dinoY == 0)
			{
				bIsJumpped = false;
				bIsJumpping = false;
			}
			// 최고 지점에 도달 후라면 (중력을 표현)
			else if (bIsJumpped)
				dinoY--;
			// 최고 지점에 도달했다면
			else if (dinoY == MAX_JUMP)
				bIsJumpped = true;
		}
		// 점프 중이 아니라면
		else
		{
			if (dinoY > 0)
				dinoY--;
		}

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
			if (dinoY < Y_COLLISION && treeX > TREE_END + 1)
				bIsCollision = true;
		}

		//엔티티 그리기
		entity->drawTree(treeX);
		entity->drawDino(dinoY);

		Sleep(SLEEP_TIME);
		system("cls");

		// 충돌 시 게임 오버
		if (bIsCollision)
		{
			std::cout<<"\n";
			std::cout << "\n";
			std::cout << "            Game Over\n";
			std::cout << "           "<< nScore<<"\n";
			system("pause");
			return;
		}
		// 충돌 상태가 아닐 때는 점수 증가
		else
		{
			nScore += 1;
		}
	}
	delete entity;
}