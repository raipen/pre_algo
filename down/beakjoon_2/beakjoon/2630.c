//#2630
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 128
int paper[MAX_SIZE][MAX_SIZE];
void solu_one(int row,int col,int size);
int is_same_one(int row,int col,int size);
void solu_zero(int row,int col,int size);
int is_same_zero(int row, int col, int size);
int count_one;
int count_zero;
int main()
{
	int size,item;
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			scanf("%d", &item);
			paper[i][j] = item;
		}
	}
	solu_one(0, 0, size);
	solu_zero(0, 0, size);
	printf("%d\n%d", count_zero, count_one);
	return 0;
}
void solu_one(int row,int col,int size)
{
	if (size ==1)
	{
		if (is_same_one(row, col, size))
		{
			count_one++;
			return;
		}
		else
			return;
	}
	if (is_same_one(row,col,size))
	{
		count_one++;
		return;
	}
	else
	{
		for (int i = row; i < row + size; i += size / 2)
		{
			for (int j = col; j < col + size; j += size / 2)
			{
				solu_one(i, j, size / 2);
			}
		}
	}
}
int is_same_one(int row, int col, int size)
{

	for (int i = row; i < row + size; i++)
	{
		for (int j = col; j < col + size; j++)
		{
			if (paper[i][j] != 1)
			{
				return 0;
			}
		}
	}
	return 1;
}
void solu_zero(int row, int col, int size)
{
	if (size == 1)
	{
		if (is_same_zero(row, col, size))
		{
			count_zero++;
			return;
		}
		else
			return;
	}
	if (is_same_zero(row,col,size))
	{
		count_zero++;
		return;
	}
	else
	{
		for (int i = row; i < row + size; i += size / 2)
		{
			for (int j = col; j < col + size; j += size / 2)
			{
				solu_zero(i, j, size / 2);
			}
		}
	}
}
int is_same_zero(int row, int col, int size)
{

	for (int i = row; i < row + size; i++)
	{
		for (int j = col; j < col + size; j++)
		{
			if (paper[i][j] != 0)
			{
				return 0;
			}
		}
	}
	return 1;
}