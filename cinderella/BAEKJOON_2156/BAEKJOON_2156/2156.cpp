#include <iostream>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 10001;

int Glass[MAX_SIZE];
int QuantSum[MAX_SIZE] = { 0 };
int GlassCount;

int main()
{
	cin >> GlassCount;

	for (int i = 0; i < GlassCount; i++)
		cin >> Glass[i + 1];

	QuantSum[1] = Glass[1];
	QuantSum[2] = Glass[1] + Glass[2];

	for (int i = 3; i <= GlassCount; i++) 
	{
		QuantSum[i] = max(QuantSum[i - 3] + Glass[i - 1], QuantSum[i - 2]) + Glass[i];
		QuantSum[i] = max(QuantSum[i - 1], QuantSum[i]);
	}

	cout << QuantSum[GlassCount];
}