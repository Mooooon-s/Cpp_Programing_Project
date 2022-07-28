#include "TreeEntity.h"

TreeEntity::TreeEntity(){
	_X = 0;
	_Y = 0;
}

void TreeEntity::drawEntity()
{
	Game_manager* gm = new Game_manager;
	gm->MoveCursor(_X, TREE_BOTTOM_Y);	//나무 그리기, 커서 위치 변경
	std::cout << "  ■■■\n";
	gm->MoveCursor(_X, TREE_BOTTOM_Y + 1);//한 칸씩 아래로
	std::cout << "    ■\n";
	gm->MoveCursor(_X, TREE_BOTTOM_Y + 2);
	std::cout << "    ■\n";
	gm->MoveCursor(_X, TREE_BOTTOM_Y + 3);
	std::cout << "    ■\n";
	delete gm;
}