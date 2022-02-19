#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int cnt=0;
int ver_num;
int edge_num;
int parent[500100];
void init();
void union_ver(int start, int end);
int is_same_parent(int start,int end);
int find_parent(int sibiling);
int main()
{
	int start, end;
	scanf("%d %d", &ver_num,&edge_num);
	init();
	for (int i = 0; i < edge_num; i++)
	{
		scanf("%d %d", &start, &end);

		if (is_same_parent(start,end))
		{
			printf("%d",++cnt);
			return 0;
		}
		else
		{
			union_ver(start, end);
			++cnt;
		}
	}
	printf("0");
	return 0;
}
void init()
{
	for (int i = 0; i < ver_num; i++)
	{
		parent[i] = i;
	}
}
void union_ver(int start, int end)
{
	int a, b;
	a = find_parent(start);
	b = find_parent(end);
	if (a < b)
	{
		parent[b] = a;
	}
	else
	{
		parent[a] = b;
	}
}
int is_same_parent(int start,int end)
{
	int parent1, parent2;
	parent1=find_parent(start);
	parent2 = find_parent(end);
	if (parent1 == parent2)
		return 1;
	return 0;
}
int find_parent(int sibiling)
{
	if (parent[sibiling] == sibiling)
	{
		return sibiling;
	}
	else
	{
		int parent3 = find_parent(parent[sibiling]);
		return parent[sibiling] = parent3;
	}
}