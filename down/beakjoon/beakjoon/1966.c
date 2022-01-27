#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101
int queue[MAX_SIZE];
int check[MAX_SIZE];
int num,size,find,count;
void enq(int item);
void deq();
void solu();
void init();
void check_sort();
void turn_queue();
int is_gone(int num);
int compare(const void* a, const void* b);
int check_seq;
int front=1, rear;
int main()
{

	scanf("%d", &num);
	while (num--)
	{
		scanf("%d %d", &size, &find);
		solu();
		init();
		printf("%d\n", count);
		count = 0;
	}
	return 0;
}
void solu()
{
	int item;
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &item);
		enq(item);
		check[i] = item;
	}
	check_sort();
	while (1)
	{
		if (queue[find+1] == 0)
			break;
		if (queue[front] == check[check_seq])
		{
			deq();
			count++;
			check_seq++;
		}
		else
		{
			turn_queue();
		}
	}
}
void init()
{
	for (int i = 0; i < size; i++)
	{
		queue[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		check[i] = 0;
	}
	front = 1;
	rear = 0;
	check_seq = 0;
}
void check_sort()
{
	qsort(check, size, sizeof(int), compare);
}
void turn_queue()
{
	while (1)
	{
		if (front == size)
		{
			front = 0;
		}
		if (queue[(front + 1)])
		{
			front++;
			break;
		}
		else
		{
			front++;
		}
	}
	while (1)
	{
		if (rear == size)
		{
			rear = 0;
		}
		if (queue[(rear + 1)])
		{
			rear++;
			break;
		}
		else
		{
			rear++;
		}
	}

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
void enq(int item)
{
	queue[++rear] = item;
}
void deq()
{
	queue[front] = 0;
	if (queue[(find + 1)%size] == 0)
		return;
	while (1)
	{
		if (front!=size&&queue[(front+1)])
		{
			++front;
			if (front > size)
			{
				front = front % size;
			}
			break;
		}
		else if(queue[(front+1)%size])
		{
			++front;
			if (front > size)
			{
				front = front % size;
			}
			break;
		}
		else
		{
			++front;
			if (front > size)
			{
				front = front % size;
			}
		}
	}
}