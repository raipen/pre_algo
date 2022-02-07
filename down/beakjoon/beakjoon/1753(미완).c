//메모리 초과때문에 인접행렬이아닌 인접그래프로 구현해야함
//시간 초과때문에 우선순위 큐 사용해야함
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999
typedef struct node* nodePointer;
typedef struct node
{
	int vertex;
	int length;
	nodePointer link;
}node;
nodePointer vertex_list[20001];
int length_save[20001];
int check[20001];
int ver_num, edge_num;
void input(int start, int vertex, int length);
void dikstra(int first);
int find_short();
int main()
{
	int first,start,end,length;
	scanf("%d %d", &ver_num, &edge_num);
	scanf("%d", &first);
	for (int i = 0; i < edge_num; i++)
	{
		scanf("%d %d %d", &start, &end, &length);
		input(start, end, length);
	}
	for (int i = 0; i <= 20000; i++)
	{
		length_save[i] = INF;
	}
	dikstra(first);
	for (int i = 1; i <= ver_num; i++)
	{
		if (length_save[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", length_save[i]);
	}
	return 0;
}
void input(int start, int vertex, int length)
{
	nodePointer tmp;
	tmp = malloc(sizeof(*tmp));
	tmp->vertex = vertex;
	tmp->link = NULL;
	tmp->length = length;
	if (!vertex_list[start])
	{
		vertex_list[start] = tmp;
	}
	else
	{
		tmp->link = vertex_list[start];
		vertex_list[start] = tmp;
	}
}
void dikstra(int first)
{
	int min = INF,current;
	nodePointer cur;
	cur = vertex_list[first];

	check[first] = 1;
	length_save[first] = 0;

	while (1)
	{
		if (!cur)
			break;
		length_save[cur->vertex] = cur->length;
		cur = cur->link;
	}
	for (int i = 0; i < ver_num - 1; i++)
	{
		current = find_short();
		cur = vertex_list[current];
		check[current] = 1;
		while (1)
		{
			if (!cur)
				break;
			if (length_save[current] + cur->length < length_save[cur->vertex])
			{
				length_save[cur->vertex] = length_save[current] + cur->length;
			}
			cur = cur->link;
		}
	}

}
int find_short()
{
	int min=INF, index = 0;
	for (int i = 1; i <= ver_num; i++)
	{
		if (length_save[i] < min&&!check[i])
		{
			min = length_save[i];
			index = i;
		}
	}
	return index;
}