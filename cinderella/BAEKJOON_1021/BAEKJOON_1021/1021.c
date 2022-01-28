#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50


int maxsize, findsize, tofind;
int count = 0;
int queue[MAX_SIZE];


int main(void)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		queue[i] = i + 1;
	}


	scanf_s("%d %d", &maxsize, &findsize);
	//printf("max : %d find : %d", maxsize, findsize);
	int nowsize = maxsize;

	int qhead = 0, qtail = 0;

	for (int i = 0; i < findsize; i++)
	{
		qhead += maxsize;
		qtail += maxsize;
		scanf_s("%d", &tofind);


		puts("/////////////////////////////");
		for (int j = 0; j < maxsize; j++)
		{
			printf("%d  ", queue[j]);
		}
		puts("\n/////////////////////////////");
		printf("qhead : %d, qtail : %d, nowsize : %d tofind : %d\n", qhead%maxsize, qtail%maxsize, nowsize, tofind);


		if ((qtail - (nowsize / 2)) % maxsize <= (qhead + (nowsize / 2)) % maxsize)//조건변경
		{
			while (queue[qhead%maxsize] != tofind)
			{
				qhead--;
				qtail--;
				if (queue[qhead % maxsize])
				{
					count++;
					printf("count rev\n");
				}
			}
			queue[qhead%maxsize] = 0;
			qhead++;
			nowsize--;
		}
		else
		{
			while (queue[qhead % maxsize] != tofind)
			{
				qhead++;
				qtail++;
				if (queue[qhead % maxsize])
				{
					count++;
					printf("count front\n");
				}
			}
			queue[qhead%maxsize] = 0;
			qhead++;
			nowsize--;
		}

	}
	printf("count : %d", count);

	return 0;
}