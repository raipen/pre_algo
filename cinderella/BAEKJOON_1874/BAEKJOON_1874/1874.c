#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100000
#define MAX_OUTPUT 10000000

//func
int SequenceByStack(int i);

//stack
int Stack[MAX_INPUT];
int StackTop = -1;

//input
int InputObj[MAX_INPUT];
int InputMaximum;

//output
char OutputObj[MAX_OUTPUT];
int OutputIndex = 0;

//var
int NumberSet = 0;

//main
int main(void)
{
	scanf_s("%d", &InputMaximum);
	//scanf("%d", &InputMaximum);

	for (int i = 0; i < InputMaximum; i++)
	{
		scanf_s("%d", &InputObj[i]);
		//scanf("%d", &InputObj[i]);

		if (!SequenceByStack(InputObj[i]))
		{
			printf("NO\n");
			return 0;
		}
	}

	for (int i = 0; i < strlen(OutputObj); i++)
		printf("%c\n", OutputObj[i]);

	return 0;
}

//func
int SequenceByStack(int toFind)
{
	while (1)
	{
		if (Stack[StackTop] < toFind)
		{
			Stack[++StackTop] = ++NumberSet;
			OutputObj[OutputIndex++] = '+';
		}
		else if (Stack[StackTop] == toFind)
		{
			OutputObj[OutputIndex++] = '-';
			StackTop--;
			return 1;
		}
		else if (Stack[StackTop] > toFind) return 0;
	}
}