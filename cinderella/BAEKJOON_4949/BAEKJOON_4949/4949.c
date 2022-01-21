#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 100

enum {
	PAR = 1,
	SQB
};

int IsBalanced(char*);

int main(void)
{
	char Input_Buffer[MAX_STR_SIZE];
	int Input_LineBalanced;

	do {
		gets(Input_Buffer);
		
		if (Input_Buffer[0] == '.') break;

		if (IsBalanced(Input_Buffer)) printf("yes\n");
		else printf("no\n");
	} while (1);

	return 0;
}

int IsBalanced(char* Buffer)
{
	int Stack[MAX_STR_SIZE];
	for (int i = 0; i < MAX_STR_SIZE; i++)
		Stack[i] = 0;
	int Stack_Top = -1;

	for (int i = 0; Buffer[i] != '.' && i < MAX_STR_SIZE; i++)
	{
		if (Buffer[i] == '(') Stack[++Stack_Top] = PAR;
		else if (Buffer[i] == ')' && (Stack_Top == -1 || Stack[Stack_Top--] != PAR)) return 0;
		else if (Buffer[i] == '[') Stack[++Stack_Top] = SQB;
		else if (Buffer[i] == ']' && (Stack_Top == -1 || Stack[Stack_Top--] != SQB)) return 0;
	}

	if (Stack_Top == -1) return 1;
	else return 0;
}