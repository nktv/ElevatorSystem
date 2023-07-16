
#include "common.h"
#include "Person.h"
#include "ILift.h"
#include "Lift.h"
#include "LiftList.h"

vector<int> ParseInput(string& data)
{
	vector<int> List;
	std::istringstream ss(data);
	std::string val;
	while (std::getline(ss, val, ','))
	{
		List.push_back(atoi(val.c_str()));
	}
	return List;
}

int main()
{
	int NoOfFloors(0);
	int NoOfLifts(0);
	int NoOfPeople(0);

	cout << "Enter no of floors : ";
	cin >> NoOfFloors;

	cout << "Enter no of Lifts: ";
	cin >> NoOfLifts;

	cout << "Enter no of People: ";
	cin >> NoOfPeople;

	// Initializing person list
	vector<IPerson*> PersonList;
	std::string Input;
	for (int i=0;i<NoOfPeople;i++)
	{
		cout << "Enter the details for people " << i + 1 << ":" << endl;
		cin >> Input;

		IPerson* person = new CPerson();
		vector<int> InputVect;

#ifdef DEBUG
		if (i == 0)
		{

			InputVect.push_back(7);
			InputVect.push_back(3);
			InputVect.push_back(7);
		}
		else if(i==1)
		{
			InputVect.push_back(3);
			InputVect.push_back(4);
			InputVect.push_back(5);
		}
		else
		{
			InputVect.push_back(8);
			InputVect.push_back(1);
			InputVect.push_back(0);
		}
#endif // DEBUG

		InputVect = ParseInput(Input);
		person->PopulateDetails(InputVect);
		PersonList.push_back(person);
	}

#ifdef DEBUG
	for (int i = 0; i < NoOfPeople; i++)
	{
		PersonList[i]->PrintDetails();
	}
#endif

	// Initializing lift details
	CLiftList LiftList;
	for (int i = 0; i < NoOfLifts; i++)
	{
		ILift* lift = new CLift();
		LiftList.UpdateToList(lift);
	}

	//TODO: sort people by start time 

	int MinTimeToDrop(0);
	for (int i = 0; i < NoOfPeople; i++)
	{
		MinTimeToDrop += PersonList.at(i)->Drop();
	}

	cout << "MinTimeToDrop = " << MinTimeToDrop << endl;
	return 0;
}

