#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
//진짜 1도 이해 안됨

long long ArrSize, Answer;
long long Modular[16][101];
long long DP[100000][100];
string arr[16];

long long GCD(long long, long long);
long long RecvFunc(long long, long long);

int main(void) 
{
	cin >> ArrSize;

	for (int i = 0; i < ArrSize; i++) 
		cin >> arr[i];

	memset(DP, -1, sizeof(DP));

	cin >> Answer;

	for (long long i = 0; i < ArrSize; i++) 
	{
		int arrlen = arr[i].length();

		for (long long j = 0; j <= Answer; j++) 
		{
			long long tmp = j % Answer;
			for (int k = 0; k < arrlen; k++) 
			{
				tmp = tmp * 10 + (arr[i][k] - '0');
				tmp %= Answer;
			}
			Modular[i][j] = tmp;
		}
	}

	long long RecvRes = RecvFunc(0, 0);

	long long Tot = 1;
	for (long long i = ArrSize; i > 0; i--) 
		Tot *= i;

	if (RecvRes == 0) cout << "0/1";
	else 
	{
		long long GCDRes = GCD(RecvRes, Tot);
		cout << RecvRes / GCDRes << "/" << Tot / GCDRes;
	}
}

long long GCD(long long x, long long y)
{
	long long z = x % y;
	while (z)
	{
		x = y;
		y = z;
		z = x % y;
	}
	return y;
}

long long RecvFunc(long long state, long long m)
{
	if (state == (1 << ArrSize) - 1) return (m == 0);

	long long& res = DP[state][m];

	if (~res) return res;

	res = 0;
	for (int i = 0; i < ArrSize; i++)
	{
		if (state & (1 << i))	continue;

		long long modtmp = Modular[i][m];
		res += RecvFunc(state | (1 << i), modtmp);
	}

	return res;
}