#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void solu();
int queue[101];
char command[100001];
int front, rear,version;
void enq(int item);
void reverse();
void deq();
void print();
int main()
{

	int size;
	scanf("%d", &size);
	while (size--)
	{
		solu();
	}

	return 0;
}
void solu()
{
	int num,item,j=0;
	scanf("%s",command);
	scanf("%d", &num);
	getchar(); //\n ºñ¿ì±â
	getchar(); //'[' ¶¼±â

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &item);
		getchar();
		enq(item);
	}

	while (1)
	{
		if (front > rear)
		{
			printf("error\n");
			front = 0;
			rear = 0;
			version = 0;
			return;
		}
		if (command[j] == 'R')
		{
			reverse();
		}
		else if (command[j] == 'D')
		{
			deq();
		}
		else
			break;
		j++;
	}
	
	print();
	front = 0;
	rear = 0;
	version = 0;
}
void enq(int item)
{
	queue[++rear] = item;
}
void reverse()
{
	if (version == 1)
		version = 0;
	else
		version = 1;
}
void deq()
{
	if (version==0)
	{
		front++;
	}
	else if(version==1)
	{
		rear--;
	}
}
void print()
{
	printf("[");
	if (version==0)
	{
		for (int i = front + 1; i <= rear; i++)
		{
			if (i == rear)
				printf("%d", queue[i]);
			else
				printf("%d,", queue[i]);
		}
	}
	else if(version==1)
	{
		for (int i = rear; i > front; i--)
		{
			if(i==front+1)
				printf("%d", queue[i]);
			else
				printf("%d,", queue[i]);
		}
	}
	printf("]\n");
}