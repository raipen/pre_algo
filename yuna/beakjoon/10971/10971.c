//----- [10971] 외판원 순회 2 -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_N 10

int w[MAX_N][MAX_N];
int n, min = 0;

int ch_visit(int visit[]);
void find_min_w(int city, int visit[], int cost);

int main() {
	int visit[MAX_N] = { 0 };

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &w[i][j]);

	find_min_w(0, visit, 0);

	printf("%d", min);

	return 0;
}

void find_min_w(int city, int visit[], int cost) {
	visit[city] = 1;

	if (ch_visit(visit)) {
		visit[city] = 0;

		if (!w[city][0])
			return;

		cost += w[city][0];
		min = (min == 0) || (cost < min) ? cost : min;
		return;
	}

	for (int i = 0; i < n; i++)
		if (w[city][i] && !visit[i]) {
			find_min_w(i, visit, cost + w[city][i]);
		}

	visit[city] = 0;
}

int ch_visit(int visit[]) {
	for (int i = 0; i < n; i++) {
		if (!visit[i])
			return 0;
	}
	return 1;
}