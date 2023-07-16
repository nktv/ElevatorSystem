#pragma once
#include "common.h"

class ILift
{
public:
	virtual int Drop(int StartFloor, int EndFloort) = 0;
};