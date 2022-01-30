//1167 트리의 지름
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct node* Nodepointer;
typedef struct node
{
	int length;
	int vertex;
	Nodepointer link;
}node;
typedef struct answer
{
	int leaf;
	int sum;
}answer;
Nodepointer vertex_list[100001];
int check[100001];
void insert_edge(int start, int end, int value);
void find_depth(int length,int first);
void find_depth2(int length, int first);
void init(int size);
int leaf;
int solution;
int solution2;
int main()
{
	int vertex_num, start_ver, end_ver, value, tmp;
	scanf("%d", &vertex_num);
	tmp = vertex_num;
	while (vertex_num--)
	{
		scanf("%d", &start_ver);
		while (1)
		{
			scanf("%d", &end_ver);
			if (end_ver == -1)
				break;
			scanf("%d", &value);
			insert_edge(start_ver, end_ver, value);
		}
	}
	find_depth(0,1);
	init(tmp);
	find_depth2(0, leaf);
	if (solution > solution2)
	{
		printf("%d", solution);
	}
	else
		printf("%d", solution2);
	return 0;
}
void insert_edge(int start, int end, int value)
{
	Nodepointer tmp;
	tmp = malloc(sizeof(*tmp));
	tmp->length = value;
	tmp->vertex = end;
	tmp->link = NULL;
	if (!vertex_list[start])
	{
		vertex_list[start] = tmp;
	}
	else
	{
		tmp->link = vertex_list[start];
		vertex_list[start]=tmp;
	}
}
void find_depth(int length,int first)
{
	Nodepointer cur;
	check[first] = 1;
	cur = vertex_list[first];
	while (1)
	{
		if (check[cur->vertex])
		{
			cur = cur->link;
			if (!cur)
			{
				if (solution < length)
				{
					solution = length;
					leaf = first;
				}
				return;
			}
		}
		else
		{
			find_depth(length + cur->length, cur->vertex);
		}
		
	}
}
void find_depth2(int length, int first)
{
	Nodepointer cur;
	check[first] = 1;
	cur = vertex_list[first];
	while (1)
	{
		if (check[cur->vertex])
		{
			cur = cur->link;
			if (!cur)
			{
				if (solution2 < length)
				{
					solution2 = length;
					leaf = first;
				}
				return;
			}
		}
		else
		{
			find_depth2(length + cur->length, cur->vertex);
		}

	}
}
void init(int size)
{
	for (int i = 0; i <= size; i++)
	{
		check[i] = 0;
	}
}