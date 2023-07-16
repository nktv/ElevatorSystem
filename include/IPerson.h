#pragma once
#include "common.h"
#include "ILift.h"

class IPerson
{
public:
	virtual void PopulateDetails(vector<int>& List) = 0;
	virtual void PrintDetails() = 0;
	virtual int Drop() = 0;
};