#pragma once
#include "ILift.h"

class CLift : public ILift
{
	int m_CurrentFloor;
public:
	CLift();
	int Drop(int startFloor, int endFloor);
	int getCurrentFloor();
};