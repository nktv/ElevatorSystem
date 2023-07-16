#pragma once
#include "common.h"
#include "IPerson.h"
#include "ILift.h"

class CPerson : public IPerson
{
	int m_ArrivalTime;
	int m_StartFloor;
	int m_EndFloor;
public:
	CPerson();
	int Drop();
	void PopulateDetails(vector<int>& List);
	void PrintDetails();
};