//----- [9370] 미확인 도착지 -----//
// 
// 시작지점부터 모든 지점까지의 최단경로를 다익스트라로 구함 (find_shortest())
// -> 이 과정에서 gh 도로를 지나갔는지 확인 (ch에 저장)
// 후보지들을 정렬해 ch값을 확인

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

NODE* road[MAX_N + 1]; // 인접리스트

int dis[MAX_N + 1]; // 최단거리 저장
int visit[MAX_N + 1]; // 방문 확인

int ch[MAX_N + 1]; // gh 사이 지나갔는지 확인

void insert(int v, int u, int d);
void setting(int n); // road, dis, ch 초기화
void find_shortest(int n, int v, int g, int h);

int compare(const void* a, const void* b); // qsort

int main() {
	int T, n, m, t, s, g, h, a, b, d;
	int arrival[MAX_N + 1]; // 목적지 후보 저장

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
				if ((v == g && i == h) || (v == h && i == g)) // gh 도로 체크
					ch[i] = 1;
				else
					ch[i] = ch[v];
			}
			else if (dis[i] == dis[v] + distance) { // 최단경로 중복
				dis[i] = dis[v] + distance;
				if ((v == g && i == h) || (v == h && i == g)) // gh 도로 체크
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