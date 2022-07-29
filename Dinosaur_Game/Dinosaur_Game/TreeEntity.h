#pragma once
#include"Entity.h"
#include"Game_manager.h"
#include<time.h>
class TreeEntity :public Entity
{
protected:
	int _tree=1;
public:
	TreeEntity();
	void setTree();
	void drawEntity();
};