#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void dfs();
int arr[9];
int N, M;
int main()
{
	int check[9] = { 0, };
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		dfs(i, 1,check);
		for (int j = 1; j <= N; j++)
			check[j] = 0;
	}


	return 0;
}
void dfs(int k,int cnt,int check[9])
{
	int copy[9];
	for (int i = 1; i <= 8; i++)
		copy[i] = check[i];

	copy[k] = 1;
	arr[cnt] = k;
	if (cnt == M)
	{
		for (int i = 1; i <= M; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (!copy[i])
		{
			dfs(i, cnt + 1,copy);
		}
	}
	return;
}