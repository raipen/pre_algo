#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CASE_SIZE 100000
#define MAX_ARR_SIZE 100000

int LoopCounter;
int QHead, QTail;
int FrontStart = 0;
int Error_t = 0;
char InputFunc[MAX_CASE_SIZE];
int InputNumOrder[MAX_ARR_SIZE];
char TrashBuffer[3];


int main(void)
{
	scanf_s("%d\n", &LoopCounter);

	for (int i = 0; i < LoopCounter; i++)
	{
		gets(InputFunc);
		scanf_s("%d%*c", &QTail);

		if (!QTail)
			gets(TrashBuffer);
		else if (QTail == 1)
			scanf_s("[%d]%*c", &InputNumOrder[0]);
		else
		{
			scanf_s("[%d", &InputNumOrder[0]);
			for (int i = 1; i < QTail - 1; i++)
				scanf_s(",%d", &InputNumOrder[i]);
			scanf_s(",%d]%*c", &InputNumOrder[QTail - 1]);
		}

		QHead = FrontStart = Error_t = 0;

		for (int i = 0; i < strlen(InputFunc); i++)
		{
			if (InputFunc[i] == 'R')
				FrontStart = (FrontStart + 1) % 2;
			else if (InputFunc[i] == 'D')
			{
				if (QHead == QTail)
				{
					printf("error\n");
					Error_t = 1;
					break;
				}
				if (FrontStart) --QTail;
				else QHead++;
			}
		}

		if (Error_t) continue;

		if (QHead == QTail)
		{
			printf("[]\n");
			continue;
		}

		if (FrontStart)
		{
			printf("[");
			for (int i = QTail - 1; i > QHead; i--)
				printf("%d,", InputNumOrder[i]);
			printf("%d]\n", InputNumOrder[QHead]);
		}
		else
		{
			printf("[");
			for (int i = QHead; i < QTail - 1; i++)
				printf("%d,", InputNumOrder[i]);
			printf("%d]\n", InputNumOrder[QTail - 1]);
		}
	}

	return 0;
}