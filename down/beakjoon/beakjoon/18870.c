#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000001
typedef struct item
{
	int num;
	int index;
}item;
item ary[MAX_SIZE];
int size;
void solu();
int compare(const void* a, const void* b);
int compare1(const void* a, const void* b);
int cnt;
int main()
{
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &ary[i].num);
		ary[i].index = i;
	}

	qsort(ary, size, sizeof(*ary), compare);
	solu();
	qsort(ary, size, sizeof(*ary), compare1);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", ary[i].num);
	}
	return 0;
}

int compare(const void* a, const void* b)
{
	item num1 = *(item*)a;
	item num2 = *(item*)b;

	if (num1.num > num2.num)
		return 1;

	if (num1.num < num2.num)
		return -1;

	return 0;
}
int compare1(const void* a, const void* b)
{
	item num1 = *(item*)a;
	item num2 = *(item*)b;

	if (num1.index > num2.index)
		return 1;

	if (num1.index < num2.index)
		return -1;

	return 0;
}
void solu()
{
	for (int i = 0; i < size-1; i++)
	{
		if (ary[i + 1].num != ary[i].num)
			ary[i].num = cnt++;
		else
			ary[i].num = cnt;
	}
	ary[size - 1].num = cnt;
}