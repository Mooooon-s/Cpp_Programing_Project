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
		gm->gotoXY(_X, TREE_BOTTOM_Y);	//���� �׸���, Ŀ�� ��ġ ����
		std::cout << "    ��\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 1);//�� ĭ�� �Ʒ���
		std::cout << "  ����\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 2);
		std::cout << " �����\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 3);
		std::cout << "    ��\n";
		delete gm;
	}
	else if(_tree==1) {
		gm->gotoXY(_X, TREE_BOTTOM_Y);	//���� �׸���, Ŀ�� ��ġ ����
		std::cout << "  ����\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 1);//�� ĭ�� �Ʒ���
		std::cout << "  ����\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 2);
		std::cout << "    ��\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 3);
		std::cout << "    ��\n";
		delete gm;
	}
	else {
		gm->gotoXY(_X, TREE_BOTTOM_Y);	//���� �׸���, Ŀ�� ��ġ ����
		std::cout << "	    ��\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 1);//�� ĭ�� �Ʒ���
		std::cout << "  ��  ��\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 2);
		std::cout << "  ����\n";
		gm->gotoXY(_X, TREE_BOTTOM_Y + 3);
		std::cout << "     ��\n";
		delete gm;
	}
}