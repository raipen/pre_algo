#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int CountMAX(int, vector<int>&);

int HouseCount, ObjCount;
int VStart = 1, VMid, VFin, Answer = 0;

int main()
{
	cin >> HouseCount >> ObjCount;

	vector<int> House(HouseCount);
	for (int i = 0; i < HouseCount; i++)
		cin >> House[i];


	sort(House.begin(), House.end());

	VFin = House[HouseCount - 1];

	while (VStart <= VFin)
	{
		VMid = (VStart + VFin) / 2;

		int MAXLenCount = CountMAX(VMid, House);

		if (MAXLenCount >= ObjCount) {
			Answer = max(Answer, VMid);
			VStart = VMid + 1;
		}
		else VFin = VMid - 1;
	}

	cout << Answer << endl;

	return 0;
}

int CountMAX(int mid, vector<int>& house)
{
	int StartLine = house[0];
	int MAXCount = 1;

	for (int i = 1; i < house.size(); i++) {
		if (house[i] - StartLine >= mid) {
			MAXCount++;
			StartLine = house[i];
		}
	}

	return MAXCount;
}