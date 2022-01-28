#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 102
typedef struct cell
{
	int row;
	int col;
	int move;
	int length;
}cell;
cell maze[MAX_SIZE][MAX_SIZE];
cell queue[20001];
int row_size,col_size;
void find_length();
void inq(cell item,cell tmp);
cell deq();
int rear;
int front;
int main()
{
	char num;
	scanf("%d %d", &row_size, &col_size);
	getchar();
	for (int i = 1; i <= row_size; i++)
	{
		for (int j = 1; j <= col_size; j++)
		{
			scanf("%c",&num);
			maze[i][j].move = num - '0';
			maze[i][j].row = i;
			maze[i][j].col = j;
		}
		getchar();
	}
	find_length();
	printf("%d", maze[row_size][col_size].length);
	return 0;
}
void find_length()
{
	cell tmp;
	inq(maze[1][1],maze[1][1]);
	tmp = deq();
	while (1)
	{
		if (tmp.col == col_size && tmp.row == row_size)
			break;
		if (maze[tmp.row][tmp.col + 1].move)
		{
			inq(maze[tmp.row][tmp.col + 1],tmp);
		}
		if (maze[tmp.row + 1][tmp.col].move)
		{
			inq(maze[tmp.row + 1][tmp.col],tmp);
		}
		if (maze[tmp.row][tmp.col - 1].move)
		{
			inq(maze[tmp.row][tmp.col - 1],tmp);
		}
		if (maze[tmp.row - 1][tmp.col].move)
		{
			inq(maze[tmp.row - 1][tmp.col],tmp);
		}
		tmp = deq();

	}
}
void inq(cell item,cell tmp)
{
	maze[item.row][item.col].move = 0;
	maze[item.row][item.col].length = tmp.length + 1;
	queue[++front] = maze[item.row][item.col];
}
cell deq()
{
	return queue[++rear];
}