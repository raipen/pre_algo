//초기화 잘하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int field[102][102];
int check[102][102];
int find_block(int field_row, int field_col);
void init_field();
void dfs(int row, int col);
int main()
{
	int T,max=1,tmp;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < T; j++)
		{
			scanf("%d", &field[i][j]);
		}
	}
	max = find_block(T, T);
	for (int i = 0; i < 101; i++)
	{
		init_field();
		for (int j = 0; j <= T; j++)
			for (int k = 0; k <= T; k++)
				field[j][k]--;

		tmp = find_block(T, T);

		if (tmp> max)
		{
			max = tmp;
		}
		
	}
	printf("%d", max);
	return 0;
}
int find_block(int field_row, int field_col)
{
	int cnt = 0;
	for (int i = 0; i < field_row; i++)
	{
		for (int j = 0; j < field_col; j++)
		{
			if (!check[i][j] && field[i][j]>0)
			{
				dfs(i, j);
				cnt++;
			}
		}
	}
	return cnt;
}
void dfs(int row, int col)
{
	if (row < 0 || col < 0 || check[row][col] || field[row][col]<=0)
		return;
	{
		check[row][col] = 1;
	}
	dfs(row, col + 1);
	dfs(row + 1, col);
	dfs(row, col - 1);
	dfs(row - 1, col);
}
void init_field()
{
	for (int i = 0; i <= 101; i++)
		for (int j = 0; j <= 101; j++)
		{
			 check[i][j] = 0;
		}
}