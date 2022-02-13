#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define max_distance 3000000

int compareGoal(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int** init_matrix(int size) {
	int** matrix = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++) {
		matrix[i] = (int*)calloc(size, sizeof(int));
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = max_distance;
		}
	}
	return matrix;
}

int minimum(int* arr, int size, int* v) {
	int min = max_distance, index = 0;
	for (int i = 1; i < size; i++) {
		if (min > arr[i] && !v[i]) {
			min = arr[i];
			index = i;
		}
	}
	return index;
}

int* dijkstra(int** matrix, int start, int size, int g, int h) {
	int* distance = (int*)malloc(size * sizeof(int));	//해당 인덱스 경로까지 가는 최단 거리를 저장
	int* result = (int*)calloc(size, sizeof(int));	//해당 인덱스 경로까지 가는 최단 거리가 gh를 지나는지 저장
	int* visited = (int*)calloc(size, sizeof(int)); //방문한 인덱스 체크

	for (int i = 0; i < size; i++) {
		distance[i] = matrix[start][i];
		if ((start == g && i == h) || start == h && i == g)
			result[i] = 1;
	}
	visited[start] = 1;
	for (int i = 1; i < size - 1; i++) {
		int cur = minimum(distance, size, visited);
		if (cur == 0) return result;
		visited[cur] = 1;
		for (int j = 1; j < size; j++) {
			if (distance[cur] + matrix[cur][j] <= distance[j]) {
				if ((cur == g && j == h) || (cur == h && j == g) || (result[j] == 1 && distance[j] == distance[cur] + matrix[cur][j]))
					result[j] = 1;
				else
					result[j] = result[cur];
				distance[j] = distance[cur] + matrix[cur][j];
			}
		}
	}

	return result;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, t;//교차로,도로,목적지 후보
		scanf("%d %d %d", &n, &m, &t);
		int** matrix = init_matrix(n + 1);
		int* goal = (int*)calloc(t, sizeof(int));

		int s, g, h;//출발지, 지난간 곳
		scanf("%d %d %d", &s, &g, &h);

		for (int i = 0; i < m; i++) {
			int a, b, d;
			scanf("%d %d %d", &a, &b, &d);
			matrix[a][b] = matrix[b][a] = d;
		}	//도로 입력 받기
		for (int i = 0; i < t; i++) {
			scanf("%d", &goal[i]);
		}	//목적지 후보 입력받기
		qsort(goal, t, sizeof(int), compareGoal); //목적지 후보 오름차순 정렬

		int* result = dijkstra(matrix, s, n + 1, g, h);	// x까지 가는 최단 경로가 g,h를 지나는지 여부를 result[x]에 담음
		for (int i = 0; i < t; i++) {
			if (result[goal[i]])	//해당 목적지까지 가는 최단 경로가 gh도로를 지나면
				printf("%d ", goal[i]);	//해당 목적지를 출력
		}
		printf("\n");
	}
	return 0;
}