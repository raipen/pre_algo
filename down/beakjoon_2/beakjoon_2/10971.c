#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int city_num;
int edge[11][11];
void travel(int start, int check[11], int cost, int cnt);
int first=1;
int price=987654321;
int main()
{
	int check[11] = { 0, };
	scanf("%d", &city_num);
	for (int i = 1; i <= city_num; i++)
	{
		for (int j = 1; j <= city_num; j++)
		{
			scanf("%d", &edge[i][j]);
		}
	}
	travel(first, check, 0, 0);
	printf("%d", price);


	return 0;
}
void travel(int start,int check[11],int cost,int cnt)
{
	int copy[11];
	for (int i = 1; i <= city_num; i++)
		copy[i] = check[i];
	copy[start] = 1;
	if (cnt + 1 == city_num)
	{
		if (edge[start][first])
		{
			if (cost + edge[start][first] < price)
			{
				price = cost + edge[start][first];
			}
			return;
		}
		else
			return;
	}
	for (int i = 1; i <= city_num; i++)
	{
		if (!check[i] && edge[start][i])
		{
			travel(i,copy,cost+edge[start][i],cnt+1);
		}
	}
}