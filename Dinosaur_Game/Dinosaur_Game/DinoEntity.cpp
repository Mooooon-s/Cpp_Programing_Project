#include "DinoEntity.h"

DinoEntity::DinoEntity() {
	_X = 0;
	_Y = 0;
}

void DinoEntity::drawEntity()
{	//���� ��縸 ���߿� ����
	Game_manager* gm = new Game_manager;
	gm->gotoXY(0, Y_BASE - _Y);	// ���� �׸���, Ŀ�� ��ġ ����
	std::cout << "        ����� \n";
	std::cout << "       �� ����\n";
	std::cout << "      ������\n";
	std::cout << "��     ���      \n";
	std::cout << "��     �����  \n";
	std::cout << "���   ����     \n";
	std::cout << " �������� \n";
	std::cout << " ������    \n";
	std::cout << "  ������    \n";
	std::cout << "    �����    \n";
	std::cout << "     ����     \n";

	if (_leg) {
		std::cout << "  ��   ���\n";
		std::cout << "  ���   \n";
		_leg = false;
	}
	else {
		std::cout << "  ��� �� \n";
		std::cout << "       ��� \n";

		_leg = true;
	}
	delete gm;
} 