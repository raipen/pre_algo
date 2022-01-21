#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char string[1000];
char driip[5] = "driip";
int compare(char save[]);
int main()
{
	int size;
	char save[5];
	scanf("%s", string);
	size = strlen(string);
	for (int i = size - 5, j = 0; i < size; i++, j++)
	{
		save[j] = string[i];
	}
	
	if (!compare(save)|| size < 5)
	{
		printf("not cute");
		return 0;
	}
	if (compare(save))
	{
		printf("cute");
	}
	return 0;
}
int compare(char save[])
{
	for (int i = 0; i < 5; i++)
	{
		if (save[i] != driip[i])
		{
			return 0;
		}
	}
	return 1;
}