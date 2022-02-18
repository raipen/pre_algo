#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int answer;
int N;
void find_queen();
int main()
{
	scanf("%d", &N);

	int board[16][16] = { 0, };
	for (int i = 1; i <= N; i++)
	{
		find_queen(1,i,board,0);
	}
	printf("%d", answer);
	return 0;
}
void find_queen(int row,int col,int board[][16],int queen_num)
{
	//printf("row,col:%d,%d\n", row, col);
	queen_num++;
	if (queen_num == N)
	{
		answer++;
		return;
	}

	int copy[16][16];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			copy[i][j] = board[i][j];

	for (int i = 1; row+i <= N; i++)
	{
		copy[row+i][col] = 1;
		if (col + i <= N)
			copy[row + i][col + i] = 1;
		if (col - i > 0)
			copy[row + i][col - i] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		if (!copy[row + 1][i])
		{
			find_queen(row + 1, i,copy,queen_num);
		}
	}
}