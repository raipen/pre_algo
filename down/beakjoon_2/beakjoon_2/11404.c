#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 987654321
void floyd();
int ary[101][101];
int ver_num;
int edge_num;

int main()
{
	int tmp;
	scanf("%d", &ver_num);
	scanf("%d", &edge_num);
	for (int i = 1; i <= ver_num; i++)
		for (int j = 1; j <= ver_num; j++)
		{
			ary[i][j] = INF;
			if (i == j)
				ary[i][j] = 0;
		}
	for (int k = 1; k <= edge_num; k++)
	{
		int i, j;
		scanf("%d %d", &i, &j);
		scanf("%d", &tmp);
		if (tmp < ary[i][j])
			ary[i][j] = tmp;
	}
	floyd();
	for (int i = 1; i <= ver_num; i++)
	{
		for (int j = 1; j <= ver_num; j++)
		{
			if (ary[i][j] == INF)
				printf("0 ");
			else
				printf("%d ", ary[i][j]);
		}
		printf("\n");
	}
	return 0;
}
void floyd()
{
	for (int i = 1; i <= ver_num; i++)//거쳐가는 노드
	{
		for (int j = 1; j <= ver_num; j++)//출발
		{
			for (int k = 1; k <= ver_num; k++)//도착
			{
				if (ary[j][i] + ary[i][k]<ary[j][k])
				{
					ary[j][k] = ary[j][i] + ary[i][k];
				}
			}
		}
	}
}