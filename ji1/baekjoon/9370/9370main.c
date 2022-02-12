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
	int* distance = (int*)malloc(size * sizeof(int));	//�ش� �ε��� ��α��� ���� �ִ� �Ÿ��� ����
	int* result = (int*)calloc(size, sizeof(int));	//�ش� �ε��� ��α��� ���� �ִ� �Ÿ��� gh�� �������� ����
	int* visited = (int*)calloc(size, sizeof(int)); //�湮�� �ε��� üũ

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
		int n, m, t;//������,����,������ �ĺ�
		scanf("%d %d %d", &n, &m, &t);
		int** matrix = init_matrix(n + 1);
		int* goal = (int*)calloc(t, sizeof(int));

		int s, g, h;//�����, ������ ��
		scanf("%d %d %d", &s, &g, &h);

		for (int i = 0; i < m; i++) {
			int a, b, d;
			scanf("%d %d %d", &a, &b, &d);
			matrix[a][b] = matrix[b][a] = d;
		}	//���� �Է� �ޱ�
		for (int i = 0; i < t; i++) {
			scanf("%d", &goal[i]);
		}	//������ �ĺ� �Է¹ޱ�
		qsort(goal, t, sizeof(int), compareGoal); //������ �ĺ� �������� ����

		int* result = dijkstra(matrix, s, n + 1, g, h);	// x���� ���� �ִ� ��ΰ� g,h�� �������� ���θ� result[x]�� ����
		for (int i = 0; i < t; i++) {
			if (result[goal[i]])	//�ش� ���������� ���� �ִ� ��ΰ� gh���θ� ������
				printf("%d ", goal[i]);	//�ش� �������� ���
		}
		printf("\n");
	}
	return 0;
}