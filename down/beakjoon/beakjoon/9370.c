#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INFI 9999999//9999일때는 왜 안돼??
int ary[2001][2001];
int check[2001];
int hint_check[2001];
int shortest[2001];
int departed[2001];
int hint_path[2001];
int size,vertex_num=2000,edge_num,depart;
void init();
void dikstra(int start);
int find_short();
int hint_find_short();
void hint_dikstra(int start);
int compare(const void* a, const void* b);
int main()
{
	int start, end, length, hint_start, hint_end, first,
		arrived;
	scanf("%d", &size);
	init();
	while (size--)
	{
		scanf("%d %d %d", &vertex_num, &edge_num, &depart);
		scanf("%d %d %d", &first, &hint_start, &hint_end);
		for (int i = 0; i < edge_num; i++)
		{
			scanf("%d %d %d", &start, &end, &length);
			ary[start][end] = length;
			ary[end][start] = length;
		}
		for (int j = 0; j < depart; j++)
		{
			scanf("%d", &arrived);
			departed[j] = arrived;
		}
		qsort(departed, depart, sizeof(int), compare);
		dikstra(first);
		if (shortest[hint_start] > shortest[hint_end])
		{
			hint_dikstra(hint_start);
			for (int k = 0; k < depart; k++)
			{
				if (shortest[departed[k]] == hint_path[departed[k]] + shortest[hint_end] + ary[hint_start][hint_end])
				{
					printf("%d ", departed[k]);
				}
			}
			printf("\n");
		}
		else
		{
			hint_dikstra(hint_end);
			for (int k = 0; k < depart; k++)
			{
				if (shortest[departed[k]] == hint_path[departed[k]] + shortest[hint_start] + ary[hint_start][hint_end])
				{
					printf("%d ", departed[k]);
				}
			}
			printf("\n");
		}
		init();
	}
	return 0;
}
void init()
{
	for (int i = 0; i < 2001; i++)
	{
		for (int j = 0; j <2001; j++)
		{
			ary[i][j] = INFI;
			if (i == j)
				ary[i][j] = 0;
		}
	}
	for (int i = 0; i < 2001; i++)
	{
		check[i] = 0; shortest[i] = INFI;
	}
	
	for (int i = 0; i < 2001; i++)
	{
		hint_check[i] = 0; hint_path[i] = INFI;
	}
	for (int i = 0; i < 2001; i++)
	{
		departed[i] = 0;
	}
}
void dikstra(int start)
{
	int shorted;
	for (int i = 1; i <= vertex_num; i++)
	{
		shortest[i] = ary[start][i];
	}
	check[start] = 1;
	for (int i = 1; i < vertex_num - 1; i++)
	{
		shorted = find_short();
		check[shorted] = 1;
		for (int j = 1; j <= vertex_num; j++)
		{
			if (!check[j])
			{
				if (ary[shorted][j] + shortest[shorted] < shortest[j])
				{
					shortest[j] = ary[shorted][j] + shortest[shorted];
				}
			}
		}
	}
}
void hint_dikstra(int start)
{
	int shorted;
	for (int i = 1; i <= vertex_num; i++)
	{
		hint_path[i] = ary[start][i];
	}
	hint_check[start] = 1;
	for (int i = 1; i < vertex_num - 1; i++)
	{
		shorted = hint_find_short();
		hint_check[shorted] = 1;
		for (int j = 1; j <= vertex_num; j++)
		{
			if (!hint_check[j])
			{
				if (ary[shorted][j] + hint_path[shorted] < hint_path[j])
				{
					hint_path[j] = ary[shorted][j] + hint_path[shorted];
				}
			}
		}
	}
}
int find_short()
{
	int min = INFI;
	int ver;
	for (int i = 1; i <= vertex_num; i++)
	{
		if (shortest[i] < min&&!check[i])
		{
			min = shortest[i];
			ver = i;
		}
	}
	return ver;
}
int hint_find_short()
{
	int min = INFI;
	int ver;
	for (int i = 1; i <= vertex_num; i++)
	{
		if (shortest[i] < min && !hint_check[i])
		{
			min = shortest[i];
			ver = i;
		}
	}
	return ver;
}
int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2)
		return 1;

	if (num1 < num2)
		return -1;

	return 0;
}
