#include<iostream>
#include"Entity.h"
#include"Game_manager.h"
using namespace std;

int main(void) {
	Game_manager gm;
	gm.Init();
	gm.CursorSetting();
	gm.GameStart();
}