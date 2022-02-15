#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
char S[21];
int main()
{
	int T,num;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &num);
		scanf("%s", S);
		for (int i = 0; S[i] != '\0'; i++)
		{
			for (int j = 0; j < num; j++)
				printf("%c", S[i]);
		}
		printf("\n");
		
	}
	return 0;
}