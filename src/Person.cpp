#include "Person.h"
#include "LiftList.h"

CPerson::CPerson()
{

}

void CPerson::PrintDetails()
{
	cout << m_ArrivalTime << " " << m_StartFloor << " " << m_EndFloor << endl;
}
void CPerson::PopulateDetails(vector<int>& List)
{
	if (List.size() != 3)
	{
		cout << "Input is not valid" << endl;
		return;
	}

	m_ArrivalTime = List.at(0);
	m_StartFloor = List.at(1);
	m_EndFloor = List.at(2);

}

int CPerson::Drop()
{
	ILift* lift = CLiftList::GetAvailableLift(m_StartFloor);
	return lift->Drop(m_StartFloor, m_EndFloor);
}