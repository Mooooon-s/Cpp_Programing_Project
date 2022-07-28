#include "DinoEntity.h"

DinoEntity::DinoEntity() {
	_X = 0;
	_Y = 0;
}

void DinoEntity::drawEntity()
{
	Game_manager* gm = new Game_manager;
	gm->MoveCursor(0, Y_BASE - _Y);	// 공룡 그리기, 커서 위치 변경
	std::cout << "    ■■\n";
	std::cout << "    ■\n";
	std::cout << "■■■■\n";
	std::cout << "  ■  ■\n";
	delete gm;
}