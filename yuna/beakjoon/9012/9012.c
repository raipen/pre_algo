//----- [9012] ½ºÅÃ/°ýÈ£ -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_L 50

int is_vps(char[]);

int main() {
	int t;
	char input[MAX_L + 2];

	scanf("%d\n", &t);
	for (int i = 0; i < t; i++)
	{
		fgets(input, MAX_L + 2, stdin);

		if (is_vps(input))
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}