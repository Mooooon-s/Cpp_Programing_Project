#include "Entity.h"
#include"Game_manager.h"

void Entity::drawDino(int dinoY)
{
	Game_manager *gm=new Game_manager;		
	gm->MoveCursor(0, Y_BASE - dinoY);	// ���� �׸���, Ŀ�� ��ġ ����
	std::cout<<"    ���\n";
	std::cout<<"    ��\n";
	std::cout << "�����\n";
	std::cout << "  ��  ��\n";
	delete gm;
}

void Entity::drawTree(int treeX) {
	Game_manager* gm = new Game_manager;
	gm->MoveCursor(treeX, TREE_BOTTOM_Y);	//���� �׸���, Ŀ�� ��ġ ����
	std::cout << "  ����\n";
	gm->MoveCursor(treeX, TREE_BOTTOM_Y+1);//�� ĭ�� �Ʒ���
	std::cout << "    ��\n";
	gm->MoveCursor(treeX, TREE_BOTTOM_Y+2);
	std::cout << "    ��\n";
	gm->MoveCursor(treeX, TREE_BOTTOM_Y+3);
	std::cout << "    ��\n";
	delete gm;
}