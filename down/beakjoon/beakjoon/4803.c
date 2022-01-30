//#4803 Æ®¸®
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int relation[501][501];
int check[501];
void dfs(int start);
int ver_num, edge_num;
int vertex;
int check_ver;
void init();
int main()
{
	int start, end,tree_num=0,case_num=0;
	while (1)
	{
		scanf("%d %d", &ver_num, &edge_num);
		if (!ver_num && !edge_num)
			break;
		for (int i = 0; i < edge_num; i++)
		{
			scanf("%d %d", &start,&end);
			relation[end][start] = 1;
			relation[start][end] = 1;
		}
		for (int i = 1; i <= ver_num; i++)
		{
			if (!check[i])
			{
				dfs(i);
				if ((vertex / 2) + 1 == check_ver)
				{
					tree_num++;
				}
			}
			check_ver = 0;
			vertex = 0;
		}
		init();
		case_num++;
		if(tree_num>1)
			printf("Case %d: A forest of %d trees.\n",case_num, tree_num);
		else if(tree_num==1)
			printf("Case %d: There is one tree.\n",case_num);
		else
			printf("Case %d: No trees.\n",case_num);
		tree_num = 0;
	}
	return 0;
}
void dfs(int start)
{
	check[start] = 1;
	check_ver++;
	for (int i = 1; i <= ver_num; i++)
	{
		if (relation[start][i])
		{
			vertex++;
			if (!check[i])
			{
				dfs(i);
			}
		}
	}
}
void init()
{
	for (int i = 0; i <= ver_num; i++)
	{
		check[i] = 0;
	}
	for (int i = 0; i <= ver_num; i++)
		for (int j = 0; j <= ver_num; j++)
			relation[i][j] = 0;
	vertex = 0;
}