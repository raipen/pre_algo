#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

typedef struct {
	int index;
	int value;
}element;

//var
int NumSize, StackTop = -1;

element Input[MAX_SIZE];
element Stack[MAX_SIZE];
int Output[MAX_SIZE];

//main
int main(void)
{
	scanf_s("%d\n", &NumSize);
	//scanf("%d", &NumSize);

	for (int i = 0; i < NumSize; i++)
	{
		Output[i] = -1;

		Input[i].index = i;

		scanf_s("%d", &Input[i].value);
		//scanf("%d", &Input[i].value);

		if (i)
			while (Stack[StackTop].value < Input[i].value && StackTop != -1)
				Output[Stack[StackTop--].index] = Input[i].value;

		Stack[++StackTop] = Input[i];
	}

	for (int i = 0; i < NumSize; i++)
	{
		if (i) printf(" ");
		printf("%d", Output[i]);
	}

	return 0;
}