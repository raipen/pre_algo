#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 10001
int set[21];
void add(int item);
void remove_(int item);
int check(int item);
void toggle(int item);
void all();
void empty();
int main()
{
	int tmp, item;
	char command[20];
	scanf("%d", &tmp);
	for (int i = 0; i < tmp; i++)
	{
		scanf("%s", command);
		getchar();
		if (strcmp(command, "add") == 0)
		{
			scanf("%d", &item);
			add(item);
		}
		else if (strcmp(command, "remove") == 0)
		{
			scanf("%d", &item);
			remove_(item);
		}
		else if (strcmp(command, "check") == 0)
		{
			scanf("%d", &item);
			printf("%d\n",check(item));
		}
		else if (strcmp(command, "toggle") == 0)
		{
			scanf("%d", &item);
			toggle(item);
		}
		else if (strcmp(command, "all") == 0)
		{
			all();
		}
		else if (strcmp(command, "empty") == 0)
		{
			empty();
		}
	}

	return 0;
}
void add(int item)
{
	set[item] = item;
}
void remove_(int item)
{
	set[item] = 0;
}
int check(int item)
{
	if (set[item])
	{
		return 1;
	}
	else
		return 0;
}
void toggle(int item)
{
	if (set[item])
	{
		set[item] = 0;
	}
	else
	{
		set[item] = item;
	}
}
void all()
{
	for (int i = 1; i <= 20; i++)
	{
		set[i]=i;
	}
}
void empty()
{
	for (int i = 1; i <= 20; i++)
	{
		set[i] = 0;
	}
}