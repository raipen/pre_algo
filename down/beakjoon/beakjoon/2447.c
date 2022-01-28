#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 7000
int ary[MAX_SIZE][MAX_SIZE];
int make_size;
void make_star(int row, int col, int size);
void print();
int main()
{
	scanf("%d", &make_size);
	make_star(0, 0, make_size);
	print();
	return 0;
}
void make_star(int row, int col, int size)
{
	if (size == 3)
	{
		for (int i = row; i < row + 3; i++)
		{
			for (int j = col; j < col + 3; j++)
			{
				if (i == row + 1 && j == col + 1)
					continue;
				ary[i][j] = 1;
			}
		}

		return;
	}
	for (int i = row; i < row + size; i+=size/3)
	{
		for (int j = col; j < col + size; j+=size/3)
		{
			if (i == row + (size) / 3 && j == col + (size) / 3)
			{
				continue;
			}
			make_star(i, j, size / 3);
		}
	}
}
void print()
{
	for (int i = 0; i < make_size; i++)
	{
		for (int j = 0; j < make_size; j++)
		{
			if (ary[i][j])
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}