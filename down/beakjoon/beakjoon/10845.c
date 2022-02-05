#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 10001
int queue[INT_MAX];
int front = 0;
int rear = 0;
void push(int item);
int pop();
int size();
int empty();
int front_();
int back();
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
		else if (strcmp(command, "front") == 0)
		{
			printf("%d\n", front_());
		}
		else if (strcmp(command, "back") == 0)
		{
			printf("%d\n", back());
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
	queue[++rear] = item;
}
int pop()
{
	if (rear > front)
		return queue[++front];
	else
		return -1;
}
int size()
{
	return rear-front;
}
int empty()
{
	if (rear > front)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int front_()
{
	if (rear>front)
	{
		return queue[front+1];
	}
	else
	{
		return -1;
	}
}
int back()
{
	if (rear > front)
	{
		return queue[rear];
	}
	else
	{
		return -1;
	}
}