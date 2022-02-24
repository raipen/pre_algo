//----- [14888] 연산자 끼워넣기 -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_N 11
#define MAX_result 1000000001
#define MIN_result -1000000001

int a[MAX_N];
int n;
int max = MIN_result;
int min = MAX_result;

void calculate(int cnt, int oper[], int r);

int main() {
	int oper[4], cnt = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 4; i++)
		scanf("%d", &oper[i]);

	calculate(1, oper, a[0]);

	printf("%d\n%d", max, min);

	return 0;
}

void calculate(int cnt, int oper[], int r) {
	if (cnt == n) {
		max = r > max ? r : max;
		min = r < min ? r : min;
		return;
	}

	if (oper[0] != 0) {
		oper[0]--;
		calculate(cnt + 1, oper, r + a[cnt]);
		oper[0]++;
	}
	if (oper[1] != 0) {
		oper[1]--;
		calculate(cnt + 1, oper, r - a[cnt]);
		oper[1]++;
	}
	if (oper[2] != 0) {
		oper[2]--;
		calculate(cnt + 1, oper, r * a[cnt]);
		oper[2]++;
	}
	if (oper[3] != 0) {
		oper[3]--;
		calculate(cnt + 1, oper, r / a[cnt]);
		oper[3]++;
	}
}

