#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void floyd();
int ary[101][101];
int ver_num;
int main()
{
	scanf("%d", &ver_num);
	for (int i = 1; i <= ver_num; i++)
	{
		for (int j = 1; j <= ver_num; j++)
		{
			scanf("%d", &ary[i][j]);
		}
	}
	floyd();
	for (int i = 1; i <= ver_num; i++)
	{
		for (int j = 1; j <= ver_num; j++)
		{
			printf("%d ", ary[i][j]);
		}
		printf("\n");
	}
	return 0;
}
void floyd()
{
	for (int i = 1; i <= ver_num; i++)//���İ��� ���
	{
		for (int j = 1; j <= ver_num; j++)//���
		{
			for (int k = 1; k <= ver_num; k++)//����
			{
				if (ary[j][i] && ary[i][k])
				{
					ary[j][k] = 1;
				}
			}
		}
	}
}