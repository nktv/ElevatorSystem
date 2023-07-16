#pragma once
#include "common.h"
#include "ILift.h"

class CLiftList
{
public:
	CLiftList();

	static vector<ILift*> m_LiftList;
	static ILift* GetAvailableLift(int StartFloor);
	void UpdateToList(ILift* list);
};