#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"Entity.h"
#include"Game_manager.h"
#include"setting.h"
using namespace std;

int main(void) {
	Game_manager gm;
	gm.Init();
	gm.CursorSetting();
	gm.GameStart();
}