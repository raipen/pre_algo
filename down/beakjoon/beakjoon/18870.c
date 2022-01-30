//대체 어떻게 분할정복???????????
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000001
int ary[MAX_SIZE];
int tmp[MAX_SIZE];
int solution[MAX_SIZE];
int size;
void solu();
void remove();
int press(int item);
int compare(const void* a, const void* b);
int main()
{
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &ary[i]);
		tmp[i] = ary[i];
	}
	qsort(tmp, size, sizeof(int), compare);
	solu();
	for (int i = 0; i < size; i++)
	{
		printf("%d ", solution[i]);
	}
	return 0;
}
void solu()
{
	int tmp;
	for (int i = 0; i < size; i++)
	{
		tmp = i;
	}
}
int press(int num)
{
	int cnt=0;
	int save=num;
	for (int i = 0; i < size; i++)
	{
		if (tmp[i] < num && tmp[i] != save)
		{
			cnt++;
			save = tmp[i];
		}
	}
	return cnt;
}
int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2)
		return -1;

	if (num1 < num2)
		return 1;

	return 0;
}
void remove()
{
	for (int i = 0; i < size; i++)
	{
		tmp[i]
	}
}