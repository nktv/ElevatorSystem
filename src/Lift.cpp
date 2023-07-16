#include "Lift.h"

CLift::CLift()
{
	m_CurrentFloor = 0;
}

int CLift::Drop(int startFloor, int EndFloor)
{
	int timetaken(0);
	if (m_CurrentFloor == startFloor)
	{
		timetaken = EndFloor - startFloor;
	}
	else if (m_CurrentFloor > startFloor)
	{
		timetaken = (m_CurrentFloor - startFloor) + (EndFloor - startFloor);
	}
	else
	{
		timetaken = (startFloor - m_CurrentFloor) + (EndFloor - startFloor);
	}

	m_CurrentFloor = EndFloor;
	return timetaken;
}

int CLift::getCurrentFloor()
{
	return m_CurrentFloor;
}