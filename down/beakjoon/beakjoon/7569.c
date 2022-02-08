//익은 토마토가 없는 경우 체크하자!
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct tomato
{
	int row;
	int col;
	int height;
}tomato;
int box[111][111][111];
int row, col,height;
tomato queue[1202001];
int rear = 0;
int front = 0;
void find_ripen();
void how_long();
int is_all_ripen();
void inq(tomato item);
tomato deq();
int visited[111][111][111];
int main()
{
	scanf("%d %d %d", &col, &row,&height);
	for (int k = 0; k <= 110; k++)
		for (int i = 0; i <= 110; i++)
			for (int j = 0; j <= 110; j++)
				box[k][i][j] = -1;
	for (int k = 1; k <= height; k++)
	{
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				scanf("%d", &box[k][i][j]);
			}
		}
	}
	find_ripen();
	how_long();
	if (is_all_ripen())
	{
		printf("%d", is_all_ripen() - 1);
	}
	else
	{
		printf("-1");
	}


	return 0;
}
void find_ripen()
{
	tomato tmp;
	for (int k = 1; k <= height; k++)
	{
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (box[k][i][j] == 1)
				{
					tmp.height = k, tmp.col = j, tmp.row = i;
					inq(tmp);
				}
			}
		}
	}
}
void how_long()
{
	tomato tmp, tmp2;
	if (rear == front)
		return;
	tmp = deq();
	while (1)
	{
		tmp2 = tmp;
		if (box[tmp.height][tmp.row + 1][tmp.col] == 0 && !visited[tmp.height][tmp.row + 1][tmp.col])
		{
			box[tmp.height][tmp.row + 1][tmp.col] = box[tmp.height][tmp.row][tmp.col] + 1;
			tmp2.col = tmp.col;
			tmp2.row = tmp.row + 1;
			tmp2.height = tmp.height;
			inq(tmp2);
		}
		if (box[tmp.height][tmp.row - 1][tmp.col] == 0 && !visited[tmp.height][tmp.row - 1][tmp.col])
		{
			box[tmp.height][tmp.row - 1][tmp.col] = box[tmp.height][tmp.row][tmp.col] + 1;
			tmp2.col = tmp.col;
			tmp2.row = tmp.row - 1;
			tmp2.height = tmp.height;
			inq(tmp2);
		}
		if (box[tmp.height][tmp.row][tmp.col + 1] == 0 && !visited[tmp.height][tmp.row][tmp.col + 1])
		{
			box[tmp.height][tmp.row][tmp.col + 1] = box[tmp.height][tmp.row][tmp.col] + 1;
			tmp2.col = tmp.col + 1;
			tmp2.row = tmp.row;
			tmp2.height = tmp.height;
			inq(tmp2);
		}
		if (box[tmp.height][tmp.row][tmp.col - 1] == 0 && !visited[tmp.height][tmp.row][tmp.col - 1])
		{
			box[tmp.height][tmp.row][tmp.col - 1] = box[tmp.height][tmp.row][tmp.col] + 1;
			tmp2.col = tmp.col - 1;
			tmp2.row = tmp.row;
			tmp2.height = tmp.height;
			inq(tmp2);
		}
		if (box[tmp.height+1][tmp.row][tmp.col ] == 0 && !visited[tmp.height+1][tmp.row][tmp.col])
		{
			box[tmp.height+1][tmp.row][tmp.col ] = box[tmp.height][tmp.row][tmp.col] + 1;
			tmp2.col = tmp.col ;
			tmp2.row = tmp.row;
			tmp2.height = tmp.height+1;
			inq(tmp2);
		}
		if (box[tmp.height - 1][tmp.row][tmp.col] == 0 && !visited[tmp.height - 1][tmp.row][tmp.col])
		{
			box[tmp.height - 1][tmp.row][tmp.col] = box[tmp.height][tmp.row][tmp.col] + 1;
			tmp2.col = tmp.col;
			tmp2.row = tmp.row;
			tmp2.height = tmp.height - 1;
			inq(tmp2);
		}
		visited[tmp.height][tmp.row][tmp.col] = 1;
		if (rear == front)
			break;
		tmp = deq();
	}
}
int is_all_ripen()
{
	int day = -1;
	for (int k = 1; k <= height; k++)
	{
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (box[k][i][j] > day)
				{
					day = box[k][i][j];
				}
				if (box[k][i][j] == 0)
				{
					return 0;
				}
			}
		}
	}
	return day;
}
void inq(tomato item)
{
	queue[++rear] = item;
}
tomato deq()
{
	return queue[++front];
}