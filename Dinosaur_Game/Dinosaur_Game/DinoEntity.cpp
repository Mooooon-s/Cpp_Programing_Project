#include "DinoEntity.h"

DinoEntity::DinoEntity() {
	_X = 0;
	_Y = 0;
}

void DinoEntity::drawEntity()
{
	Game_manager* gm = new Game_manager;
	gm->MoveCursor(0, Y_BASE - _Y);	// ���� �׸���, Ŀ�� ��ġ ����
	std::cout << "    ���\n";
	std::cout << "    ��\n";
	std::cout << "�����\n";
	std::cout << "  ��  ��\n";
	delete gm;
}