#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 51;

bool Ground[MAX][MAX];
bool check[MAX][MAX];
int xVal[] = { -1, 1, 0, 0 };
int yVal[] = { 0, 0, 1, -1 };

int xSize, ySize, CabCount, xPos, yPos;

void DFS(int x, int y);

int main(void)
{
	int TestCaseCount;
	cin >> TestCaseCount;

	for (int i = 0; i < TestCaseCount; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			for (int k = 0; k < MAX; k++)
			{
				check[j][k] = false;
				Ground[j][k] = false;
			}
		}

		cin >> xSize >> ySize >> CabCount;

		for (int j = 0; j < CabCount; j++)
		{
			cin >> xPos >> yPos;
			Ground[xPos][yPos] = true;
		}

		int Count = 0;

		for (int j = 0; j < xSize; j++)
		{
			for (int k = 0; k < ySize; k++)
			{
				if (Ground[j][k] && !check[j][k])
				{
					Count++;
					DFS(j, k);
				}
			}
		}
		cout << Count << endl;
	}
}
void DFS(int x, int y)
{
	check[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int xPosNext = x + xVal[i];
		int yPosNext = y + yVal[i];

		if (0 <= xPosNext && xPosNext < xSize && 0 <= yPosNext && yPosNext < ySize)
			if (Ground[xPosNext][yPosNext] && !check[xPosNext][yPosNext])	DFS(xPosNext, yPosNext);
	}
}