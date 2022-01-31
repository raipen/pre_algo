#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[200001];
int func(int synth_num,int item);
int dp[500001];
int main()
{
	int size,qurry_num, synth_num,item;
	scanf("%d", &size);
	for (int i = 1; i <= size; i++)
	{
		scanf("%d", &ary[i]);
	}
	scanf("%d", &qurry_num);
	while (qurry_num--)
	{
		scanf("%d %d", &synth_num, &item);
		printf("%d\n",func(synth_num,item));
	}
	return 0;
}
int func(int synth_num, int item)
{
	if (synth_num == 1)
	{
		dp[synth_num]=
		return ary[item];
	}
	synth_num /= 2;
	func(synth_num, item);
	return ary[item];
}
