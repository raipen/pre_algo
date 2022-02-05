#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 51
int queue[MAX_SIZE];
int check[MAX_SIZE];
int front = 1;
int rear = 0;
int count;
int capacity;
void pick_first_item(int key);
void turn_left();
void turn_right();
void solu(int repeat_num);
int is_search(int key);
int which_drctn(int key);
void init();
int main()
{
	int repeat_num;
	scanf("%d %d", &capacity,&repeat_num);

	solu(repeat_num);
	printf("%d", count);
	return 0;
}

int which_drctn(int key)
{
	int cur = front,left=0,right=0;
	while (1)
	{
		if (cur == key)
		{
			break;
		}
		if (cur == capacity)
		{
			cur = 0;
		}
		if (!check[(cur + 1)])
		{
			cur++;
			right++;
		}
		else
		{
			cur++;
		}
	}
	cur = front;
	while (1)
	{
		if (cur == key)
			break;
		if (cur == 1)
		{
			cur = capacity+1;
		}
		if (!check[cur-1])
		{
			cur--;
			left++;
		}
		else
		{
			cur--;
		}
	}
	if (left >= right)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
int is_search(int key)
{
	if (queue[front] == key)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void pick_first_item(int key)
{
	int cnt=0;
	check[key] = 1;
	while (1)
	{
		if (front == capacity)
		{
			front = 0;
		}
		if (!check[(front + 1)])
		{
			front++;
			break;
		}
		else
		{
			front++;
		}
		cnt++;
		if (cnt == capacity)
			break;
	}
}
void turn_left()
{
	while (1)
	{
		if (front == capacity)
		{
			front = 0;
		}
		if (!check[(front + 1)])
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
		if (rear == capacity)
		{
			rear = 0;
		}
		if (!check[(rear + 1)])
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
void turn_right()
{
	while (1)
	{
		if (front == 1)
		{
			front = capacity+1;
		}
		if (!check[front-1])
		{
			front--;
			break;
		}
		else
		{
			front--;
		}
	}
	while (1)
	{
		if (rear == 1)
		{
			rear = capacity+1;
		}
		if (!check[rear-1])
		{
			rear--;
			break;
		}
		else
		{
			rear--;
		}
	}
}
void solu(int repeat_num)

{
	int key;
	rear = capacity;
	init();
	while (repeat_num--)
	{
		scanf("%d", &key);
		if (is_search(key))
		{
			pick_first_item(key);
		}
		else
		{
			if (which_drctn(key) == -1)//왼쪽이 더 가까울떄
			{
				while (1)
				{
					if (is_search(key))
					{
						break;
					}
					turn_left();
					count++;
				}
				pick_first_item(key);
			}
			else if (which_drctn(key) == 1)//오른쪽이 더 가까울때
			{
				while (1)
				{
					if (is_search(key))
					{
						break;
					}
					turn_right();
					count++;
				}
				pick_first_item(key);
			}
		}
	}
}
void init()
{
	for (int i = 1; i <= capacity; i++)
	{
		queue[i] = i;
	}
}