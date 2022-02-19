//----- [9370] ��Ȯ�� ������ -----//
// 
// ������������ ��� ���������� �ִܰ�θ� ���ͽ�Ʈ��� ���� (find_shortest())
// -> �� �������� gh ���θ� ���������� Ȯ�� (ch�� ����)
// �ĺ������� ������ ch���� Ȯ��

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_N 2000

typedef struct NODE* nodePointer;
typedef struct NODE {
	int v;
	int d;
	nodePointer link;
} NODE;

NODE* road[MAX_N + 1]; // ��������Ʈ

int dis[MAX_N + 1]; // �ִܰŸ� ����
int visit[MAX_N + 1]; // �湮 Ȯ��

int ch[MAX_N + 1]; // gh ���� ���������� Ȯ��

void insert(int v, int u, int d);
void setting(int n); // road, dis, ch �ʱ�ȭ
void find_shortest(int n, int v, int g, int h);

int compare(const void* a, const void* b); // qsort

int main() {
	int T, n, m, t, s, g, h, a, b, d;
	int arrival[MAX_N + 1]; // ������ �ĺ� ����

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);

		setting(n);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &d);
			insert(a, b, d);
			insert(b, a, d);
		}
		for (int i = 0; i < t; i++)
			scanf("%d", &arrival[i]);
		qsort(arrival, t, sizeof(int), compare);

		visit[s] = 1;
		find_shortest(n, s, g, h);

		for (int i = 0; i < t; i++)
			if (ch[arrival[i]])
				printf("%d ", arrival[i]);
		printf("\n");
	}

	return 0;
}

void find_shortest(int n, int v, int g, int h) {
	int min = -1, i, distance;
	NODE* ptr;

	if (v == -1)
		return;

	ptr = road[v];
	while (ptr) {
		i = ptr->v;
		distance = ptr->d;
		if (!visit[i]) {
			if (!dis[i] || dis[i] > dis[v] + distance) {
				dis[i] = dis[v] + distance;
				if ((v == g && i == h) || (v == h && i == g)) // gh ���� üũ
					ch[i] = 1;
				else
					ch[i] = ch[v];
			}
			else if (dis[i] == dis[v] + distance) { // �ִܰ�� �ߺ�
				dis[i] = dis[v] + distance;
				if ((v == g && i == h) || (v == h && i == g)) // gh ���� üũ
					ch[i] = 1;
				else if (ch[v] || ch[i])
					ch[i] = 1;
			}
		}

		ptr = ptr->link;
	}

	for (i = 1; i < n + 1; i++) {
		if (!visit[i] && dis[i] && (min == -1 || dis[min] > dis[i]))
			min = i;
	}

	visit[min] = 1;
	find_shortest(n, min, g, h);
}

void setting(int n) {
	for (int i = 1; i < n + 1; i++) {
		dis[i] = ch[i] = visit[i] = 0;
		road[i] = NULL;
	}
}

void insert(int v, int u, int d) {
	NODE* temp;

	temp = (NODE*)malloc(sizeof(NODE));
	temp->v = u;
	temp->d = d;
	temp->link = NULL;

	if (road[v])
		temp->link = road[v];
	road[v] = temp;
}

int compare(const void* a, const void* b) {
	return *(int*)a < *(int*)b ? -1 : *(int*)a > *(int*)b ? 1 : 0;
}