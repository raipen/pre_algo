//#17298
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000000
int ary[MAX_SIZE];
int stack[MAX_SIZE];
int answer[MAX_SIZE];
int top = -1;
int size;
void push(int item);
int peek();
void find();
int main()
{
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &ary[i]);
	}
	find();

	for (int i = 0; i < size; i++)
	{
		printf("%d ", answer[i]);
	}


	return 0;
}

void find()
{
	for (int i = size - 1; i >= 0; i--)
	{
		if (top == -1)
		{
			push(ary[i]);
			answer[i] = -1;
		}
		else
		{
			while (1)
			{
				if (ary[i] < peek())
				{
					answer[i] = peek();
					push(ary[i]);
					break;
				}
				else
				{
					top--;
					if (top == -1)
					{
						answer[i] = -1;
						push(ary[i]);
						break;
					}

				}
			}
		}
	}
}
void push(int item)
{
	stack[++top] = item;
	return;
}
int peek()
{
	return stack[top];
}