#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct member
{
	int time;
	int span_time;
}member;
member member_list[1001];
int sum_time;
int number;
int solu();
int compare(const void* a, const void* b);
int main()
{
	scanf("%d", &number);

	for (int i = 0; i < number; i++)
	{
		scanf("%d", &member_list[i].time);
	}
	qsort(member_list, number, sizeof(member), compare);
	printf("%d", solu());
}
int solu()
{
	int answer = 0;
	for (int i = 0; i < number; i++)
	{
		sum_time += member_list[i].time;
		member_list[i].span_time = sum_time;
	}
	for (int j = 0; j < number; j++)
	{
		answer += member_list[j].span_time;
	}
	return answer;
}
int compare(const void* a, const void* b)
{
	member num1 = *(member*)a;
	member num2 = *(member*)b;

	if (num1.time > num2.time)
		return 1;

	if (num1.time < num2.time)
		return -1;

	return 0;
}
