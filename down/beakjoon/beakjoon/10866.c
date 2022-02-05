#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 20002
int queue[INT_MAX];
int front = 10000;
int rear = 10000;
void push_front(int item);
void push_back(int item);
int pop_front();
int pop_back();
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
		if (strcmp(command, "push_front") == 0)
		{
			scanf("%d", &item);
			push_front(item);
		}
		else if (strcmp(command, "push_back") == 0)
		{
			scanf("%d", &item);
			push_back(item);
		}
		else if (strcmp(command, "pop_front") == 0)
		{
			printf("%d\n", pop_front());
		}
		else if (strcmp(command, "pop_back") == 0)
		{
			printf("%d\n", pop_back());
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
void push_back(int item)
{
	queue[++rear] = item;
}
void push_front(int item)
{
	queue[front--] = item;
}

int pop_front()
{
	if (rear > front)
		return queue[++front];
	else
		return -1;
}
int pop_back()
{
	if (rear > front)
		return queue[rear--];
	else
		return -1;
}
int size()
{
	return rear - front;
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
	if (rear > front)
	{
		return queue[front + 1];
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