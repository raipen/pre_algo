//lis문제! dp로 최대연속수열찾기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct line
{
	int a_build;
	int b_build;
}line;

line line_set[102];
int size;
int cnt;
int depart[501];
int line_length(line a);
int is_crush(line a, line b);
int compare(const void* a, const void* b);
int dp[501];
int main()
{
	int start,max=0;
	scanf("%d", &size);
	for (int i = 1; i <= size; i++)
	{
		scanf("%d", &start);
		scanf("%d", &depart[start]);
	}
	//qsort(depart, size, sizeof(int), compare);

	for (int i = 1; i <= 500; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (depart[j]&&(depart[i] > depart[j]))
			{
				if (dp[j] > max)
				{
					max = dp[j];
				}
			}
		}
		dp[i] = max + 1;
		max = 0;
	}
	for (int i = 1; i <= 500; i++)
	{
		if (dp[i] > max)
			max = dp[i];
	}
	printf("%d", size-max);


	return 0;
}
int line_length(line a)
{
	int length;
	length = a.a_build - a.b_build;
	if (length < 0)
		return length * -1;
	return length;
}
int is_crush(line b, line a)
{
	if ((a.a_build < b.a_build) && (a.b_build < b.b_build))
	{
		return 0;
	}
	return 1;
}
int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1> num2)
		return 1;

	if (num1 < num2)
		return -1;

	return 0;
}