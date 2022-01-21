//#1874
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000
int stack[MAX_SIZE];
int save[1000000];
int save_num;
int top = -1;
void solu(int num);
void push(int item);
int peek();
void print();
int main()
{
	int num;
	scanf("%d", &num);
	solu(num);
	print();
	return 0;
}
void solu(int num)
{
	int item, high = -1;
	while (num--)
	{
		scanf(" %d", &item);
		if (high == -1)
		{
			for (int i = 1; i <= item; i++)
			{
				push(i);
				save[save_num++] = 1;
			}
			high = item;
			pop();
			save[save_num++] = 0;
		}
		else
		{
			if (peek() < item)
			{
				for (int i = high + 1; i <= item; i++)
				{
					push(i);
					save[save_num++] = 1;
				}
				high = item;
				pop();
				save[save_num++] = 0;
			}
			else if (peek() == item)
			{
				pop();
				save[save_num++] = 0;
			}
			else
			{
				save[save_num] = -1;
				return;
			}
		}
	}
}
void push(int item)
{
	stack[++top] = item;
}
int peek()
{
	return stack[top];
}
int pop()
{
	return stack[--top];
}
void print()
{

	if (save[save_num] == -1)
	{
		printf("NO");
	}
	else
	{
		for (int i = 0; i < save_num; i++)
		{
			if (save[i] == 1)
			{
				printf("+\n");
			}
			else
			{
				printf("-\n");
			}
		}
	}
}