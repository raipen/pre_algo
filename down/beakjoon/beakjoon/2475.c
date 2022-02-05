#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int num[5];
int main()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &num[i]);
		sum += num[i] * num[i];
	}
	printf("%d", sum % 10);
	return 0;
}