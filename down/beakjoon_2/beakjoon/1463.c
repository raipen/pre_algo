//전형적인 dp문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int num;
int dp[1000000];
int main()
{
	int cnt = 0,min=987654321;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		if (i == 1)
		{
			dp[1] = 0;
			continue;
		}
		if (i % 3 == 0)
		{
			min = dp[i / 3] + 1;
		}
		if (i % 2 == 0)
		{
			if (dp[i/2] + 1 < min)
				min = dp[i/2] + 1;
		}
		if(dp[i-1]+1<min)
		{
			min = dp[i-1] + 1;
		}
		dp[i] = min;
		min = 987654321;
	}
	printf("%d", dp[num]);

	return 0;
}