#include<iostream>
#include"setting.h"
#pragma once
class Entity
{
protected:
	int _Y=0;
	int _X=0;
public:
	void setY(int Y);
	void setX(int X);
	int Y() { return _Y; }
	int X() { return _X; }
	virtual void drawEntity();
};