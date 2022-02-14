#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

char string[MAX_SIZE];
char stack[MAX_SIZE];
int top = -1;
int first = 0;
int check_string(char c);
void push(char c);
char peek();
void pop();
int main()
{
	while(1)
	{ 
		top = -1;
		gets(string);
		if (strcmp(string, ".") == 0) break;
		for (int i = 0; string[i] != '.'; i++)
		{
			if (check_string(string[i]) > 0)
			{
				push(string[i]);
			}
			else if (string[i] == ')')
			{
				if (top>-1&&peek() == '(')
				{
					pop();
				}

				else if (top == -1)
				{
					printf("no\n");
					top--;
					break;
				}
				else
				{
					break;
				}
			}
			else if (string[i] == ']')
			{
				if (top > -1 && peek() == '[')
				{
					pop();
				}
				else if(top==-1)
				{
					printf("no\n");
					top--;
					break;
				}
				else
				{
					break;
				}
			}
		}
		if (top == -1)
		{
			printf("yes\n");
		}
		else if (top > -1)
		{
			printf("no\n");
		}
	}
	return 0;
}
int check_string(char c)
{
	if (c == '(')
	{
		return 1;
	}
	else if (c == ')')
	{
		return -1;
	}
	else if (c == '[')
	{
		return 2;
	}
	else if (c == ']')
	{
		return -2;
	}
	else
	{
		return 0;
	}
}
void push(char c)
{
	stack[++top] = c;
}
char peek()
{
	return stack[top];
}
void pop()
{
	top--;
}