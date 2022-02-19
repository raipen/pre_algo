#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct cow
{
	int arrived_time;
	int searching_time;
}cow;

int dp[101];
cow cow_list[101];

int compare(const void* a, const void* b);
int main()
{
	cow cow;
	int size;
	scanf("%d", &size);

	for (int i = 0; i < size; i++)
	{
		scanf("%d %d", &cow_list[i].arrived_time, &cow_list[i].searching_time);
	}
	qsort(cow_list, size, sizeof(cow), compare);
	dp[0] = cow_list[0].arrived_time + cow_list[0].searching_time;
	for (int i = 0; i < size; i++)
	{
		if (dp[i-1] <= cow_list[i].arrived_time)
		{
			dp[i] = cow_list[i].arrived_time + cow_list[i].searching_time;
		}
		else
		{
			dp[i] = dp[i - 1] + cow_list[i].searching_time;
		}
	}
	printf("%d", dp[size - 1]);
	return 0;
}
int compare(const void* a, const void* b)
{
	return ((cow*)a)->arrived_time == ((cow*)b)->arrived_time ? ((cow*)a)->searching_time - ((cow*)b)->searching_time : ((cow*)a)->arrived_time - ((cow*)b)->arrived_time;
}