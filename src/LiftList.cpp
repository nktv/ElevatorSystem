#include "LiftList.h"
#include "Lift.h"
#include "ILift.h"

vector<ILift*> CLiftList::m_LiftList;
CLiftList::CLiftList()
{
}

ILift* CLiftList::GetAvailableLift(int startfloor)
{
	CLift* AvailLift = static_cast<CLift*>(m_LiftList.at(0));
	uint16_t min = startfloor - AvailLift->getCurrentFloor();
	if (startfloor < AvailLift->getCurrentFloor())
	{
		min = AvailLift->getCurrentFloor() - startfloor;
	}

	for (int i = 1; i < m_LiftList.size(); i++)
	{
		CLift* lift = static_cast<CLift*>(m_LiftList.at(i));
		int FloorDiff = startfloor - AvailLift->getCurrentFloor();
		if (startfloor < AvailLift->getCurrentFloor())
		{
			FloorDiff = AvailLift->getCurrentFloor() - startfloor;
		}

		if (min > FloorDiff)
		{
			min = FloorDiff;
			AvailLift = lift;

		}
	}
	return AvailLift;
}

void CLiftList::UpdateToList(ILift* lift)
{
	if (!lift)
	{
		return;
	}

	m_LiftList.push_back(lift);
}