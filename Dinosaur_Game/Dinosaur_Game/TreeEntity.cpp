#include "TreeEntity.h"

TreeEntity::TreeEntity(){
	_X = 0;
	_Y = 0;
}

void TreeEntity::drawEntity()
{
	Game_manager* gm = new Game_manager;
	gm->MoveCursor(_X, TREE_BOTTOM_Y);	//���� �׸���, Ŀ�� ��ġ ����
	std::cout << "  ����\n";
	gm->MoveCursor(_X, TREE_BOTTOM_Y + 1);//�� ĭ�� �Ʒ���
	std::cout << "    ��\n";
	gm->MoveCursor(_X, TREE_BOTTOM_Y + 2);
	std::cout << "    ��\n";
	gm->MoveCursor(_X, TREE_BOTTOM_Y + 3);
	std::cout << "    ��\n";
	delete gm;
}