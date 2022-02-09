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
position queue[10501];
int rear = 0;
int front;
int size;
int cnt=0;
void find_section();
void inq(position item);
position deq();
int save_section();
void blind_section();
void init();
void bfs(int row,int col);
void divide_setion();
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
}
void blind_section()
{
	check[1][1] = cnt;
	position tmp = { 1,1 }, tmp2;
	inq(tmp);
	while (1)
	{
		if (front == rear)
			break;
		tmp = deq();
		if (picture[tmp.row][tmp.col] == 'R' || picture[tmp.row][tmp.col] == 'G')
		{
			if (!check[tmp.row - 1][tmp.col] && (picture[tmp.row - 1][tmp.col] == 'R' || picture[tmp.row - 1][tmp.col] == 'G'))
			{
				check[tmp.row - 1][tmp.col] = check[tmp.row][tmp.col];
				tmp2.row = tmp.row - 1;
				tmp2.col = tmp.col;
				inq(tmp2);
			}
			else if(!check[tmp.row - 1][tmp.col] && (picture[tmp.row - 1][tmp.col] == 'B'))
			{
				check[tmp.row - 1][tmp.col] = check[tmp.row][tmp.col]+1;
				tmp2.row = tmp.row - 1;
				tmp2.col = tmp.col;
				inq(tmp2);
			}
			if (!check[tmp.row + 1][tmp.col] && (picture[tmp.row + 1][tmp.col] == 'R' || picture[tmp.row + 1][tmp.col] == 'G'))
			{
				check[tmp.row + 1][tmp.col] = check[tmp.row][tmp.col];
				tmp2.row = tmp.row + 1;
				tmp2.col = tmp.col;
				inq(tmp2);
			}
			else if (!check[tmp.row + 1][tmp.col] && (picture[tmp.row + 1][tmp.col] == 'B'))
			{
				check[tmp.row + 1][tmp.col] = check[tmp.row][tmp.col] + 1;
				tmp2.row = tmp.row + 1;
				tmp2.col = tmp.col;
				inq(tmp2);
			}
			if (!check[tmp.row ][tmp.col-1] && (picture[tmp.row ][tmp.col-1] == 'R' || picture[tmp.row ][tmp.col-1] == 'G'))
			{
				check[tmp.row ][tmp.col-1] = check[tmp.row][tmp.col];
				tmp2.row = tmp.row ;
				tmp2.col = tmp.col-1;
				inq(tmp2);
			}
			else if (!check[tmp.row][tmp.col-1] && (picture[tmp.row ][tmp.col-1] == 'B'))
			{
				check[tmp.row ][tmp.col-1] = check[tmp.row][tmp.col] + 1;
				tmp2.row = tmp.row ;
				tmp2.col = tmp.col-1;
				inq(tmp2);
			}
			if (!check[tmp.row][tmp.col + 1] && (picture[tmp.row][tmp.col + 1] == 'R' || picture[tmp.row][tmp.col + 1] == 'G'))
			{
				check[tmp.row][tmp.col + 1] = check[tmp.row][tmp.col];
				tmp2.row = tmp.row;
				tmp2.col = tmp.col + 1;
				inq(tmp2);
			}
			else if (!check[tmp.row][tmp.col + 1] && (picture[tmp.row][tmp.col + 1] == 'B'))
			{
				check[tmp.row][tmp.col + 1] = check[tmp.row][tmp.col] + 1;
				tmp2.row = tmp.row;
				tmp2.col = tmp.col + 1;
				inq(tmp2);
			}
		}
		else
		{
			if (!check[tmp.row + 1][tmp.col] && picture[tmp.row][tmp.col] == picture[tmp.row + 1][tmp.col])
			{
				check[tmp.row + 1][tmp.col] = check[tmp.row][tmp.col];
				tmp2.row = tmp.row + 1;
				tmp2.col = tmp.col;
				inq(tmp2);
			}
			else if ((!check[tmp.row + 1][tmp.col]) && (picture[tmp.row][tmp.col] != picture[tmp.row + 1][tmp.col]))
			{
				check[tmp.row + 1][tmp.col] = check[tmp.row][tmp.col] + 1;
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

			if (!check[tmp.row][tmp.col + 1] && picture[tmp.row][tmp.col + 1] == picture[tmp.row][tmp.col])
			{
				check[tmp.row][tmp.col + 1] = check[tmp.row][tmp.col];
				tmp2.row = tmp.row;
				tmp2.col = tmp.col + 1;
				inq(tmp2);
			}
			else if ((!check[tmp.row][tmp.col + 1]) && (picture[tmp.row][tmp.col + 1] != picture[tmp.row][tmp.col]))
			{
				check[tmp.row][tmp.col + 1] = check[tmp.row][tmp.col] + 1;
				tmp2.row = tmp.row;
				tmp2.col = tmp.col + 1;
				inq(tmp2);
			}

			if (!check[tmp.row][tmp.col - 1] && picture[tmp.row][tmp.col - 1] == picture[tmp.row][tmp.col])
			{
				check[tmp.row][tmp.col - 1] = check[tmp.row][tmp.col];
				tmp2.row = tmp.row;
				tmp2.col = tmp.col - 1;
				inq(tmp2);
			}
			else if ((!check[tmp.row][tmp.col - 1]) && (picture[tmp.row][tmp.col - 1] != picture[tmp.row][tmp.col]))
			{
				check[tmp.row][tmp.col - 1] = check[tmp.row][tmp.col] + 1;
				tmp2.row = tmp.row;
				tmp2.col = tmp.col - 1;
				inq(tmp2);
			}
		}
		
	}
}
int save_section()
{
	int max = 0;
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			if (check[i][j] > max)
			{
				max = check[i][j];
			}
		}
	}
	return max;
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
		if (picture[tmp.row][tmp.col + 1] == picture[tmp.row][tmp.col])
		{
			tmp2.row = tmp.row;
			tmp2.col = tmp.col + 1;
			inq(tmp2);
		}
		if (picture[tmp.row + 1][tmp.col] == picture[tmp.row][tmp.col])
		{
			tmp2.row = tmp.row + 1;
			tmp2.col = tmp.col;
			inq(tmp2);
		}
		if (picture[tmp.row][tmp.col - 1] == picture[tmp.row][tmp.col])
		{
			tmp2.row = tmp.row;
			tmp2.col = tmp.col - 1;
			inq(tmp2);
		}
		if (picture[tmp.row - 1][tmp.col] == picture[tmp.row][tmp.col])
		{
			tmp2.row = tmp.row - 1;
			tmp2.col = tmp.col;
			inq(tmp2);
		}
	}
}