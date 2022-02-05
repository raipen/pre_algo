//----- [2178] DFS¿Í BFS/¹Ì·ÎÅ½»ö -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_N 100

int n, m;
int map[MAX_N + 2][MAX_N + 2] = { 0 }, dis[MAX_N + 2][MAX_N + 2] = { 0 };
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void maze(int x, int y);
void setting();

int main() {

	setting();
	maze(1, 1);

	printf("%d", dis[n][m]);

	return 0;
}

void maze(int x, int y) {
	int next_x, next_y;
	if ((x == n) && (y == m))
		return;

	for (int i = 0; i < 4; i++) {
		next_x = x + dir[i][0];
		next_y = y + dir[i][1];

		if (map[next_x][next_y] == 0)
			continue;

		if ((dis[next_x][next_y] == 0) || (dis[x][y] + 1 < dis[next_x][next_y])) {
			dis[next_x][next_y] = dis[x][y] + 1;
			maze(next_x, next_y);
		}
	}
}

void setting()
{
	char input[MAX_N + 2];

	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", input);
		for (int j = 0; j < m; j++)
			map[i + 1][j + 1] = input[j] - '0';
	}

	dis[1][1] = 1;
}