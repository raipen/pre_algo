#include<iostream>
using namespace std;

int HaveCount, ToMakeCount, ToMakeLen;
int LAN[10001];
int  MAXLen = 0;
long long M, T, B;

int main()
{
	cin >> HaveCount >> ToMakeCount;

	for (int i = 0; i < HaveCount; i++)
	{
		cin >> LAN[i];
		if (MAXLen < LAN[i]) MAXLen = LAN[i];
	}
	B = 1;
	T = MAXLen;
	ToMakeLen = 0;

	while (B <= T)
	{
		M = (B + T) / 2;
		int cnt = 0;
		for (int i = 0; i < HaveCount; i++)
			cnt += LAN[i] / M;

		if (cnt >= ToMakeCount) {
			B = M + 1;
			if (ToMakeLen < M) ToMakeLen = M;
		}
		else {
			T = M - 1;
		}
	}

	cout << ToMakeLen;
}