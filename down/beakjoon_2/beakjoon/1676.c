#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct two_five
{
	int two_num;
	int five_num;
}two_five;
two_five save_xeno[501];
int main()
{
	int num,two=2,five=5,tmp;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		tmp = i;
		while (tmp)
		{
			if (!(tmp % 2))
			{
				save_xeno[1].two_num++;
				tmp = tmp / 2;
			}
			else
			{
				break;
			}
		}
		tmp = i;
		while (tmp)
		{
			if (!(tmp % 5))
			{
				save_xeno[1].five_num++;
				tmp = tmp / 5;
			}
			else
			{
				break;
			}
		}
	}
	if (save_xeno[1].five_num > save_xeno[1].two_num)
	{
		printf("%d", save_xeno[1].two_num);
	}
	else
	{
		printf("%d", save_xeno[1].five_num);
	}
	return 0;
}