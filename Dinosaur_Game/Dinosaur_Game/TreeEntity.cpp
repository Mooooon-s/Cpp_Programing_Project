#include "TreeEntity.h"
TreeEntity::TreeEntity(){
	_X = 0;
	_Y = 0;
}

void TreeEntity::setTree() {
	srand((unsigned int)time(NULL));
	_tree = rand()%3;
}

void TreeEntity::drawEntity()
{
	Game_manager* gm = new Game_manager;
	if (_tree==0) {
		gm->gotoXY(_X, TREE_BOTTOM_Y);	//나무 그리기, 커서 위치 변경
		std::cout << "    ■\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 1);//한 칸씩 아래로
		std::cout << "  ■■■\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 2);
		std::cout << " ■■■■\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 3);
		std::cout << "    ■\n";
		delete gm;
	}
	else if(_tree==1) {
		gm->gotoXY(_X, TREE_BOTTOM_Y);	//나무 그리기, 커서 위치 변경
		std::cout << "  ■■■\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 1);//한 칸씩 아래로
		std::cout << "  ■■■\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 2);
		std::cout << "    ■\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 3);
		std::cout << "    ■\n";
		delete gm;
	}
	else {
		gm->gotoXY(_X, TREE_BOTTOM_Y);	//나무 그리기, 커서 위치 변경
		std::cout << "	    ■\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 1);//한 칸씩 아래로
		std::cout << "  ■  ■\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 2);
		std::cout << "  ■■■\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 3);
		std::cout << "     ■\n";
		delete gm;
	}
}