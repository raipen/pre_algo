#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int N, r, c;
void solve();
int sum;
int pow_dawns(int item, int doublling);
int main()
{
	scanf("%d %d %d", &N, &r, &c);
	solve();
	printf("%d", sum);

	return 0;
}
void solve()
{
	if (N == 0)
	{
		return;
	}
	if (!(r / pow_dawns(2,(N - 1))) && !(c / pow_dawns(2, (N - 1))))
	{
		N -= 1;
		solve();
	}
	else if (!(r / pow_dawns(2, (N - 1))) && c / pow_dawns(2, (N - 1)))
	{
		sum += pow_dawns(4, (N - 1));
		c -= pow_dawns(2, (N - 1));
		N -= 1;
		solve();
	}
	else if (r / pow_dawns(2, (N - 1)) && !(c/pow_dawns(2, (N - 1))))
	{
		sum += pow_dawns(4, (N - 1)) * 2;
		r -= pow_dawns(2, (N - 1));
		N -= 1;
		solve();
	}
	else
	{
		sum += pow_dawns(4, (N - 1)) * 3;
		r -= pow_dawns(2, (N - 1));
		c -= pow_dawns(2, (N - 1));
		N -= 1;
		solve();
	}
}
int pow_dawns(int item, int doublling)
{
	int tmp = item;
	if (doublling == 0)
		return 1;
	if (doublling == 1)
		return item;
	for (int i = 0; i < doublling-1; i++)
	{
		item *= tmp;
	}
	return item;
}