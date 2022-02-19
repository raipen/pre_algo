#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int field[52][52];
int check[52][52];
int find_block(int field_row,int field_col);
void init_field();
void dfs(int row,int col);
int main()
{
	int T,field_row,field_col,num,row,col;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d", &field_row, &field_col, &num);
		for (int i = 0; i < num; i++)
		{
			scanf("%d %d", &row, &col);
			field[row][col] = 1;
		}
		printf("%d\n",find_block(field_row,field_col));
		init_field();
	}
	return 0;
}
int find_block(int field_row,int field_col)
{
	int cnt=0;
	for (int i = 0; i < field_row; i++)
	{
		for (int j = 0; j < field_col; j++)
		{
			if (!check[i][j] && field[i][j])
			{
				dfs(i,j);
				cnt++;
			}
		}
	}
	return cnt;
}
void dfs(int row,int col)
{
	if (row<0||col<0||check[row][col]||!field[row][col])
		return;
	{
		check[row][col] = 1;
	}
	dfs(row, col + 1);
	dfs(row + 1, col);
	dfs(row, col -1);
	dfs(row-1, col );
}
void init_field()
{
	for(int i=0;i<=51;i++)
		for (int j = 0; j <= 51; j++)
		{
			field[i][j] = 0; check[i][j] = 0;
		}
}