#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 10000
int stack[INT_MAX];
int top = -1;
void push(int item);
int pop();
int size();
int empty();
int peek();
int main()
{
	int tmp, item;
	char command[20];
	scanf("%d", &tmp);
	for (int i = 0; i < tmp; i++)
	{
		scanf("%s", command);
		getchar();
		if (strcmp(command, "push") == 0)
		{
			scanf("%d", &item);
			push(item);
		}
		else if (strcmp(command, "pop") == 0)
		{
			printf("%d\n", pop());
		}
		else if (strcmp(command, "size") == 0)
		{
			printf("%d\n", size());
		}
		else if (strcmp(command, "top") == 0)
		{
			printf("%d\n", peek());
		}

		else if (strcmp(command, "empty") == 0)
		{
			printf("%d\n", empty());
		}
	}

	return 0;
}
void push(int item)
{
	stack[++top] = item;
}
int pop()
{
	if (top > -1)
	{
		return stack[top--];
	}
	else
	{
		return -1;
	}
}
int size()
{
	return top + 1;
}
int empty()
{
	if (top > -1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int peek()
{
	if (top > -1)
	{
		return stack[top];
	}
	else
	{
		return -1;
	}
}