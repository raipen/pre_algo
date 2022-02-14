#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define V_MAX 1001
#define E_MAX 10000
int vertex[V_MAX];
int edge[E_MAX];
int check[V_MAX];
int ok[V_MAX];
int matrix[V_MAX][V_MAX];
int queue[E_MAX * 2];

int front = 0;
int rear = 0;
int ver_num, edge_num, start_num;
void dfs(int start);
void bfs(int start);
void init_check();
int is_gone(int start);
int main()
{
	int row, col;
	scanf("%d %d %d", &ver_num, &edge_num, &start_num);
	while (edge_num--)
	{
		scanf("%d %d", &row, &col);
		matrix[row][col] = 1;
		matrix[col][row] = 1;
	}
	
	dfs(start_num);
	printf("\n");
	init_check();
	bfs(start_num);
	return 0;
}
void dfs(int start)
{
	check[start] = 1;
	printf("%d ", start);
	for (int i = 1; i <= ver_num; i++)
	{
		if (matrix[start][i]&&!is_gone(i))
		{
			dfs(i);
		}
	}
}
void bfs(int start)
{
	check[start] = 1;
	printf("%d ", start);
	for (int i = 1; i <= ver_num; i++)
	{
		if (matrix[start][i] && !is_gone(i))
		{
			if (!ok[i])
			{
				ok[i] = 1;
				queue[++rear] = i;
			}
		}
	}

	if (front == rear)
		return;
	bfs(queue[++front]);
}
int is_gone(int start)
{
	if (check[start])
		return 1;
	else
		return 0;

}
void init_check()
{
	for (int i = 0; i <= ver_num; i++)
	{
		check[i] = 0;
	}
}