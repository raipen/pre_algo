#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int oper[4];
int num_list[12];
int num;
void cal(int curr_op[], int op, int curr, int prev_num);
int min=2100000000;
int max=-2100000000;
int main()
{
	int curr_op[4] = { 0, };
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &num_list[i]);
	}
	for (int j = 0; j < 4; j++)
	{
		scanf("%d", &oper[j]);
	}
	for (int i = 0; i < 4; i++)
	{
		if (oper[i])
		{
			cal(curr_op, i, 1, num_list[0]);
		}
	}
	printf("%d\n%d", max, min);
	return 0;
}
void cal(int curr_op[],int op,int curr,int prev_num)
{
	int copy_op[4];
	for (int i = 0; i < 4; i++)
	{
		copy_op[i] = curr_op[i];
	}
	int curr_num=num_list[curr];
	copy_op[op]++;
	if (op == 0)
	{
		curr_num = prev_num+curr_num;
	}
	else if (op == 1)
	{
		curr_num = prev_num-curr_num;
	}
	else if (op == 2)
	{
		curr_num = prev_num*curr_num;
	}
	else
	{
		curr_num = prev_num/curr_num;
	}
	if (curr == num - 1)
	{
		if (curr_num < min)
			min = curr_num;
		if (curr_num > max)
			max = curr_num;
		return;
	}
	if (copy_op[0] < oper[0])
	{
		cal(copy_op, 0,curr+1,curr_num);
	}
	if (copy_op[1] < oper[1])
	{
		cal(copy_op, 1, curr + 1, curr_num);
	}
	if (copy_op[2] < oper[2])
	{
		cal(copy_op, 2, curr + 1, curr_num);
	}
	if (copy_op[3] < oper[3])
	{
		cal(copy_op, 3, curr + 1, curr_num);
	}
}