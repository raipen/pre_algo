//카운팅을 이용한 소트
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int compare1(const void* a, const void* b);
int ary[10020];
int main()
{
	int size,num;
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &num);
		ary[num]++;
	}
	for (int i = 1; i <= 10010; i++)
	{
		if (ary[i] == 0)
			continue;
		for (int j = 0; j < ary[i]; j++)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}