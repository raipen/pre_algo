#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int page[501];
int dp[501][501];
int pre_sum(int first,int end);
int sum[501][501];
int solu;
int find_min(int first, int end);
void init();
int main()
{
	int T,size;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &size);
		for (int i = 1; i <= size; i++)
		{
			scanf("%d", &page[i]);
		}
		pre_sum(1, size);
		printf("%d\n",find_min(1,size));
		init();
	}
	return 0;
}
int find_min(int first, int end)
{
	int tmp1, tmp2;
	int j;
	if (first == end)
		return page[first];
	for (j = 0; first + j < end; j++)
	{
		if (!dp[first][first + j])
			tmp1 = find_min(first, first + j);
		else
			tmp1 = dp[first][first + j];
		if (!dp[first + j + 1][end])
			tmp2 = find_min(first + j + 1, end);
		else
			tmp2 = dp[first + j + 1][end];
		if (!dp[first][end] || dp[first][first + j] + dp[first + j + 1][end] + sum[first][end]< dp[first][end])
		{
			dp[first][end] =dp[first][first+j]+dp[first+j+1][end]+sum[first][end];
		}
	}
	return dp[first][end];
	
}
void init()
{
	for (int i = 1; i <= 500; i++)
	{
		page[i] = 0;
		for (int j = 1; j <= 500; j++)
		{
			dp[i][j] = 0;
			sum[i][j] = 0;
		}
	}
}
int pre_sum(int first, int end)
{
	for (int i = 1; i <= 500; i++)
	{
		sum[i][i] = page[i];
		for (int j = 1; i+j <= 500; j++)
		{
			sum[i][i + j] += sum[i][i+j-1] + page[i+j];
		}
	}
	return sum;
}