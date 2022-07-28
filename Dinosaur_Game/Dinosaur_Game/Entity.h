#include<iostream>
#include"setting.h"
#pragma once
class Entity
{
protected:
	int _Y=0;
	int _X=0;
public:
	void setDinoY(int Y);
	void setTreeX(int X);
	inline int Y() { return _Y; }
	inline int X() { return _X; }
	virtual void drawEntity();
};
