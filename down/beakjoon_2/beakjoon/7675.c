#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct tomato
{
	int row;
	int col;
}tomato;
int box[1010][1010];
int row, col;
tomato queue[1002001];
int rear = 0;
int front = 0;
void find_ripen();
void how_long();
int is_all_ripen();
void inq(tomato item);
tomato deq();
int visited[1010][1010];
int main()
{
	scanf("%d %d", &col, &row);
	for (int i = 0; i <= row + 1; i++)
		for (int j = 0; j <= col+1; j++)
			box[i][j] = -1;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			scanf("%d", &box[i][j]);
		}
	}
	find_ripen();
	how_long();
	if (is_all_ripen())
	{
		printf("%d", is_all_ripen()-1);
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

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (box[i][j] == 1)
			{
				tmp.col = j,	tmp.row=i;
				inq(tmp);
			}
		}
	}
}
void how_long()
{
	tomato tmp,tmp2;
	tmp = deq();
	while (1)
	{
		tmp2 = tmp;
		if (box[tmp.row + 1][tmp.col] == 0&&!visited[tmp.row+1][tmp.col])
		{
			box[tmp.row + 1][tmp.col] = box[tmp.row][tmp.col]+1;
			tmp2.col = tmp.col;
			tmp2.row=tmp.row+1;
			inq(tmp2);
		}
		if (box[tmp.row -1][tmp.col] == 0 && !visited[tmp.row - 1][tmp.col])
		{
			box[tmp.row - 1][tmp.col] = box[tmp.row][tmp.col] + 1;
			tmp2.col = tmp.col;
			tmp2.row = tmp.row - 1;
			inq(tmp2);
		}
		if (box[tmp.row ][tmp.col+1] == 0 && !visited[tmp.row ][tmp.col+1])
		{
			box[tmp.row ][tmp.col+1] = box[tmp.row][tmp.col] + 1;
			tmp2.col=tmp.col+1;
			tmp2.row = tmp.row;
			inq(tmp2);
		}
		if (box[tmp.row ][tmp.col-1] == 0 && !visited[tmp.row ][tmp.col-1])
		{
			box[tmp.row ][tmp.col-1] = box[tmp.row][tmp.col] + 1;
			tmp2.col=tmp.col-1;
			tmp2.row = tmp.row;
			inq(tmp2);
		}
		visited[tmp.row][tmp.col] = 1;
		if (rear == front)
			break;
		tmp = deq();
	}
}
int is_all_ripen()
{
	int day = -1;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (box[i][j] > day)
			{
				day = box[i][j];
			}
			if (box[i][j] == 0)
			{
				return 0;
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