//bfs
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct position
{
	int row;
	int col;
}position;
int check[103][103];
char picture[103][103];
position queue[10501000];
int rear = 0;
int front;
int size;
int cnt=0;
void find_section();
void inq(position item);
position deq();
void init();
void bfs(int row,int col);
void divide_setion();
void make_blind();
int main()
{
	scanf("%d ", &size);
	for (int i = 0; i <= 102; i++)
	{
		for (int j = 0; j <=102 ; j++)
		{
			check[i][j] = -1;
		}
	}
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			scanf("%c", &picture[i][j]);
			check[i][j] = 0;
		}
		getchar();
	}
	divide_setion();
	printf("%d ", cnt);
	init();
	make_blind();
	divide_setion();
	printf("%d", cnt);
	return 0;
}
void find_section()
{
	check[1][1] = cnt;
	position tmp = { 1,1 },tmp2;
	inq(tmp);
	while (1)
	{
		if (front == rear)
			break;
		tmp = deq();
		if (!check[tmp.row + 1][tmp.col] && picture[tmp.row][tmp.col] == picture[tmp.row + 1][tmp.col])
		{
			check[tmp.row + 1][tmp.col] = check[tmp.row][tmp.col];
			tmp2.row = tmp.row + 1;
			tmp2.col = tmp.col;
			inq(tmp2);
		}
		else if ((!check[tmp.row + 1][tmp.col]) && (picture[tmp.row][tmp.col] != picture[tmp.row + 1][tmp.col]))
		{
			check[tmp.row + 1][tmp.col] = check[tmp.row][tmp.col]+1;
			tmp2.row = tmp.row + 1;
			tmp2.col = tmp.col;
			inq(tmp2);
		}
		if (!check[tmp.row - 1][tmp.col] && picture[tmp.row][tmp.col] == picture[tmp.row - 1][tmp.col])
		{
			check[tmp.row - 1][tmp.col] = check[tmp.row][tmp.col];
			tmp2.row = tmp.row - 1;
			tmp2.col = tmp.col;
			inq(tmp2);
		}
		else if ((!check[tmp.row - 1][tmp.col]) && (picture[tmp.row][tmp.col] != picture[tmp.row - 1][tmp.col]))
		{
			check[tmp.row - 1][tmp.col] = check[tmp.row][tmp.col] + 1;
			tmp2.row = tmp.row - 1;
			tmp2.col = tmp.col;
			inq(tmp2);
		}
	
		if (!check[tmp.row][tmp.col+1] && picture[tmp.row][tmp.col+1] == picture[tmp.row][tmp.col])
		{
			check[tmp.row ][tmp.col+1] = check[tmp.row][tmp.col];
			tmp2.row = tmp.row ;
			tmp2.col = tmp.col+1;
			inq(tmp2);
		}	
		else if ((!check[tmp.row][tmp.col+1]) && (picture[tmp.row][tmp.col+1] != picture[tmp.row ][tmp.col]))
		{
			check[tmp.row ][tmp.col+1] = check[tmp.row][tmp.col] + 1;
			tmp2.row = tmp.row;
			tmp2.col = tmp.col+1;
			inq(tmp2);
		}
		
		if (!check[tmp.row ][tmp.col-1] && picture[tmp.row][tmp.col-1] == picture[tmp.row ][tmp.col])
		{
			check[tmp.row ][tmp.col-1] = check[tmp.row][tmp.col];
			tmp2.row = tmp.row ;
			tmp2.col = tmp.col-1;
			inq(tmp2);
		}
		else if ((!check[tmp.row][tmp.col-1]) && (picture[tmp.row][tmp.col-1] != picture[tmp.row][tmp.col]))
		{
			check[tmp.row ][tmp.col-1] = check[tmp.row][tmp.col] + 1;
			tmp2.row = tmp.row ;
			tmp2.col = tmp.col-1;
			inq(tmp2);
		}
	}
}
void inq(position item)
{
	check[item.row][item.col] = 1;
	queue[++rear] = item;
}
position deq()
{
	return queue[++front];
}
void init()
{
	front = 0;
	rear = 0;
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			check[i][j] = 0;
		}
	}
	cnt = 0;
}
void divide_setion()
{
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			if (!check[i][j])
			{
				bfs(i, j);
				cnt++;
			}
		}
	}
}
void bfs(int row, int col)
{

	position tmp,tmp2;
	tmp.row = row;
	tmp.col = col;
	inq(tmp);
	check[row][col] = 1;
	while (1)
	{
		if (rear == front)
			break;
		tmp = deq();
		check[tmp.row][tmp.col] = 1;
		if (!check[tmp.row][tmp.col+1]&&(picture[tmp.row][tmp.col + 1] == picture[tmp.row][tmp.col]))
		{
			tmp2.row = tmp.row;
			tmp2.col = tmp.col + 1;
			inq(tmp2);
		}
		if (!check[tmp.row+1][tmp.col ] && (picture[tmp.row + 1][tmp.col] == picture[tmp.row][tmp.col]))
		{
			tmp2.row = tmp.row + 1;
			tmp2.col = tmp.col;
			inq(tmp2);
		}
		if (!check[tmp.row][tmp.col - 1] && (picture[tmp.row][tmp.col - 1] == picture[tmp.row][tmp.col]))
		{
			tmp2.row = tmp.row;
			tmp2.col = tmp.col - 1;
			inq(tmp2);
		}
		if (!check[tmp.row-1][tmp.col ] && (picture[tmp.row - 1][tmp.col] == picture[tmp.row][tmp.col]))
		{
			tmp2.row = tmp.row - 1;
			tmp2.col = tmp.col;
			inq(tmp2);
		}
	}
}
void make_blind()
{
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			if (picture[i][j] == 'G')
			{
				picture[i][j] = 'R';
			}
		}
	}
}