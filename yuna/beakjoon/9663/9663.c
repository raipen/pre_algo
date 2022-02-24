//----- [9663] N-Queen -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_N 15

int n;

int find_n_queen(int cnt, int row[]);
int check(int r, int m, int row[]);

int main() {
	int row[MAX_N + 1] = { 0 };

	scanf("%d", &n);

	printf("%d", find_n_queen(1, row));

	return 0;
}

int find_n_queen(int cnt, int row[]) {
	int sum = 0;

	if (cnt > n)
		return 1;

	for (int i = 1; i <= n; i++) {
		if (check(i, cnt, row)) {
			row[cnt] = i;
			sum += find_n_queen(cnt + 1, row);
		}
	}

	return sum;
}

int check(int r, int m, int row[]) {
	for (int i = 1; i < m; i++) {
		if ((row[i] == r) || (m - r == i - row[i]) || (m + r == i + row[i]))
			return 0;
	}

	return 1;
}