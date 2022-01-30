#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000010
#define MAX 0
int size;
int dp[MAX_SIZE];
int main()
{
	int max;
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &dp[i]);
	}
	max = dp[0];
	for (int i = 1; i < size; i++)
	{
		if (dp[i - 1] > 0 && dp[i] + dp[i - 1] > 0) {
			dp[i] += dp[i - 1];
		}

		if (max < dp[i]) {
			max = dp[i];
		}

	}
	printf("%d", max);


	
	return 0;
}