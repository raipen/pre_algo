#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct item
{
	int zero;
	int one;
}item;
item seq[40];
int main()
{
	int num;
	int size;
	seq[0].zero = 1;
	seq[1].one = 1;
	scanf("%d", &size);
	while (size--)
	{
		scanf("%d", &num);
		if (num == 0)
		{
			printf("1 0\n");
		}
		else if (num == 1)
		{
			printf("0 1\n");
		}
		else
		{
			for (int i = 2; i <= num; i++)
			{
				seq[i].zero = seq[i - 1].zero + seq[i - 2].zero;
				seq[i].one = seq[i - 1].one + seq[i - 2].one;
			}
			printf("%d %d\n", seq[num].zero, seq[num].one);
		}
		
	}
	return 0;
}