//----- [5430] Å¥,µ¦/AC -----//
// ±»ÀÌ µ¦À¸·Î Ç®¾î¾ßÇÏ³ª...

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_N 100000
#define MAX_D 100001
#define MAX_P 100002

void input_x(int x[], int n);
int AC(char p[], int x[], int n);

int main() {
	int t, n, x[MAX_N];
	char p[MAX_P], temp;

	scanf("%d", &t);
	for (;t;t--) {
		scanf("%s", p);
		scanf("%d", &n);

		input_x(x, n);

		if (!AC(p, x, n))
			printf("error\n");
	}

	return 0;
}

void input_x(int x[], int n) {
	char temp;

	scanf("\n%c", &temp);

	if (n == 0) {
		scanf("%c", &temp);
		return;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		scanf("%c", &temp);
	}
}

int AC(char p[], int x[], int n)
{
	int rev = 0, front = 0, back = n - 1;

	for (int i = 0; i < strlen(p); i++) {
		if (p[i] == 'R')
			rev = (rev + 1) % 2;
		else {
			if (front > back)
				return 0;

			if (rev)
				back--;
			else
				front++;
		}
	}

	printf("[");
	if (front > back) {
		printf("]\n");
		return 1;
	}

	while (1) {
		if (rev) {
			printf("%d", x[back]);
			back--;
		}
		else {
			printf("%d", x[front]);
			front++;
		}

		if (front > back)
			break;
		printf(",");
	}
	printf("]\n");

	return 1;
}