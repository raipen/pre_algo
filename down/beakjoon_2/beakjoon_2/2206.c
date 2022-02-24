#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
	int row;
	int col;
	int is_fire;
}item;
int d_row[4] = { 0,1,0,0-1};
int d_col[4] = { 1,0,-1,0 };
int row_num;
int col_num;

int front, rear;

int maze[1001][1001];
int result[1001][1001];
int visit[1001][1001][2];
int find_exit();
item queue[98765432];
void enq(item tmp);
item deq();
int main()
{
	char tmp;
	scanf("%d %d ", &row_num, &col_num);
	for (int i = 0; i < row_num; i++)
	{
		for (int j = 0; j < col_num; j++)
		{
			scanf("%c", &tmp);
			maze[i][j] = tmp - '0';
		}
		getchar();
	}
	printf("%d", find_exit());
	return 0;
}
int find_exit()
{
	item tmp = { 1,1,0 };
	item tmp2;
	int n_row, n_col;
	enq(tmp);
	result[0][0] = 1;
	visit[1][1][0] = 1;
	//visit[1][1][01] = 1;
	while (1)
	{
		if (front == rear)
			break;
		tmp2 = deq();
		for (int i = 0; i < 4; i++)
		{
			n_row = d_row[i] + tmp2.row;
			n_col = d_col[i] + tmp2.col;
			if (n_row >= 0 && n_col >= 0 && n_row < row_num && n_col < col_num)
			{
				if (maze[n_row][n_col] == 1 && !tmp2.is_fire && !visit[n_row][n_col][tmp2.is_fire + 1])
				{
					visit[n_row][n_col][tmp2.is_fire + 1] = 1;
					result[n_row][n_col] = result[tmp2.row][tmp2.col] + 1;
					item tmp3 = { n_row,n_col,tmp2.is_fire + 1 };
					enq(tmp3);
				}
				else if (maze[n_row][n_col] != 1 && !visit[n_row][n_col][tmp2.is_fire])
				{
					visit[n_row][n_col][tmp2.is_fire] = 1;
					result[n_row][n_col] = result[tmp2.row][tmp2.col] + 1;
					item tmp3 = { n_row,n_col,tmp2.is_fire};
					enq(tmp3);
				}
				else if (n_row == row_num - 1 && n_col == col_num - 1)
				{
					return result[n_row][n_col];
				}
				else
				{
					item tmp3 = { n_row,n_col,tmp2.is_fire };
					enq(tmp3);
				}
			}
		}

	}
	return -1;

}

void enq(item tmp)
{
	queue[++front] = tmp;
}
item deq()
{
	return queue[++rear];
}