#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct item
{
	int index;
	int jump_num;
}item;
int check[1001];
int jump[1001];
int bfs();
item queue[9876542];
void enq(item a);
item deq();
int front;
int rear;
int size;
int answer;
int main()
{
	scanf("%d", &size);
	answer = size;
	for (int i = 1; i <= size; i++)
	{
		scanf("%d", &jump[i]);
	}
	if (size == 1)
	{
		printf("0"); return 0;
	}
	printf("%d", bfs());
	return 0;
}

int bfs()
{
	item tmp;
	tmp.index = 1;
	tmp.jump_num = 0;
	enq(tmp);
	check[1] = 1;
	item parent;
	while (1)
	{
		if (front == rear)
			break;
		parent = deq();

		for (int i = parent.index + 1; i <= parent.index + jump[parent.index]; i++)
		{
			if (i == answer)
			{
				return parent.jump_num + 1;
			}
			if (i > answer)
				return -1;
			if (!check[i])
			{
				tmp.index = i;
				tmp.jump_num = parent.jump_num + 1;
				enq(tmp);
				check[i] = 1;
			}
		}
	}
	return -1;
}
void enq(item a)
{
	queue[++rear] = a;
}

item deq()
{
	return queue[++front];
}