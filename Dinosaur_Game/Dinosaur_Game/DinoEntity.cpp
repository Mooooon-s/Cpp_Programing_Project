#include "DinoEntity.h"

DinoEntity::DinoEntity() {
	_X = 0;
	_Y = 0;
}

void DinoEntity::drawEntity()
{	//대충 모양만 나중에 수정
	Game_manager* gm = new Game_manager;
	gm->gotoXY(0, Y_BASE - _Y);	// 공룡 그리기, 커서 위치 변경
	std::cout << "        ■■■■ \n";
	std::cout << "       ■ ■■■\n";
	std::cout << "      ■■■■■\n";
	std::cout << "■     ■■      \n";
	std::cout << "■     ■■■■  \n";
	std::cout << "■■   ■■■     \n";
	std::cout << " ■■■■■■■ \n";
	std::cout << " ■■■■■    \n";
	std::cout << "  ■■■■■    \n";
	std::cout << "    ■■■■    \n";
	std::cout << "     ■■■     \n";

	if (_leg) {
		std::cout << "  ■   ■■\n";
		std::cout << "  ■■   \n";
		_leg = false;
	}
	else {
		std::cout << "  ■■ ■ \n";
		std::cout << "       ■■ \n";

		_leg = true;
	}
	delete gm;
} 