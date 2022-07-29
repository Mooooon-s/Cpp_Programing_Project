#pragma once
#include"setting.h"
#include"Entity.h"
#include"Game_manager.h"

class DinoEntity : public Entity
{
public:
	bool _leg=true;
public:	
	DinoEntity();
	void drawEntity();
};