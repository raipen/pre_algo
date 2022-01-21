//#2493
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5000000
int ary[MAX_SIZE];
int answer[MAX_SIZE];
int stack[MAX_SIZE];
int top = -1;
void solu(int size);
void push(int item);
int peek();
void print();
int main()
{
	int size,item;
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &ary[i]);
	}
	solu(size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", answer[i]);
	}
}
void solu(int size)
{
	for(int i = 0; i < size; i++)
	{
		if (top == -1)
		{
			answer[i] = 0;
			push(i);
		}
		else
		{
			while (1)
			{
				if (ary[peek()] < ary[i])
				{
					top--;
					if (top == -1)
					{
						answer[i] = 0;
						push(i);
						break;
					}
				}
				else
				{
					answer[i] = peek()+1;
					push(i);
					break;
				}
			}
		}
	}
}
void push(int item)
{
	stack[++top]=item;
}
int peek()
{
	return stack[top];
}