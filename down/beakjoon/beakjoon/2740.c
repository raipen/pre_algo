#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary1[101][101];
int ary2[101][101];
int ary3[101][101];
int main()
{
	int row_1, col_1, row_2, col_2,sum=0;
	scanf("%d %d", &row_1, &col_1);
	for (int i = 0; i < row_1; i++)
	{
		for (int j = 0; j < col_1; j++)
		{
			scanf("%d", &ary1[i][j]);
		}
	}
	scanf("%d %d", &row_2, &col_2);
	for (int i = 0; i < row_2; i++)
	{
		for (int j = 0; j < col_2; j++)
		{
			scanf("%d", &ary2[i][j]);
		}
	}

	for (int i = 0; i < row_1; i++)
	{
		for (int j = 0; j < col_2; j++)
		{
			for (int k = 0; k < row_2; k++)
			{
				sum += ary1[i][k] * ary2[k][j];
			}
			ary3[i][j] = sum;
			sum = 0;

		}
	}
	for (int i = 0; i < row_1; i++)
	{
		for (int j = 0; j < col_2; j++)
		{
			printf("%d ", ary3[i][j]);
		}
		printf("\n");
	}

	return 0;
}