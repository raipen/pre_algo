#include <iostream>
#include <vector>
using namespace std;

#define MAX_SIZE 101

int RowSize1, RowSize2, ColSize1, ColSize2;

vector<vector<int> > Matrix1(MAX_SIZE, vector<int>(MAX_SIZE, 0));
vector<vector<int> > Matrix2(MAX_SIZE, vector<int>(MAX_SIZE, 0));
vector<vector<int> > MatrixResult(MAX_SIZE, vector<int>(MAX_SIZE, 0));

int main(void)
{
	cin >> RowSize1;
	cin >> ColSize1;
	for (int i = 1; i <= RowSize1; i++)
	{
		for (int j = 1; j <= ColSize1; j++)
		{
			cin >> Matrix1[i][j];
		}
	}

	cin >> RowSize2;
	cin >> ColSize2;
	for (int i = 1; i <= RowSize2; i++)
	{
		for (int j = 1; j <= ColSize2; j++)
		{
			cin >> Matrix2[i][j];
		}
	}

	for (int i = 1; i <= RowSize1; i++)
	{
		for (int j = 1; j <= ColSize2; j++)
		{
			for (int k = 1; k <= ColSize1; k++)
			{
				MatrixResult[i][j] += Matrix1[i][k] * Matrix2[k][j];
			}
			cout << MatrixResult[i][j] << ' ';
		}
		cout << '\n';
	}
}