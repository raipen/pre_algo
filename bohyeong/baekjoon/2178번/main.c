#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[101][101] = { 0};
int visited[101][101];
int curr = 0;

typedef struct {
	int m[20000];
	int front, rear;
	int l[20000];
}q;

void init_q(q* s) {
	s->front = s->rear = -1;

}

int is_empty(q* s) {
	if (s->front == s->rear) {
		return 1;
	}
	return 0;
}

void enqueue(q* s, int val) {
	if (s->rear == 20000 - 1) return;
	else {
		s->rear = s->rear + 1;
		s->m[(s->rear)] = val;
	}
	//printf("rear: %d", s->rear);
	return;
}

int dequeue(q* s) {
	if (is_empty(s)) return;
	else {
		s->front = s->front + 1;
		return s->m[(s->front)];
	}
	curr++;
}

int main() {
	q x;
	q y;
	q z;
	init_q(&x); init_q(&y);
	init_q(&z);
	int N, M;
	int flag = 0; int count = 0;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	enqueue(&x, 1); enqueue(&y, 1);
	visited[1][1] = 1;
	enqueue(&z, ++count);
	int n, m;
	
		while (!is_empty(&x)) {
			flag = 0;
			n = dequeue(&x); m = dequeue(&y);
			count = dequeue(&z);
			if (n == N && m == M) break;
			if (arr[n - 1][m] && !visited[n - 1][m]) { //위
				enqueue(&x, n - 1);
				enqueue(&y, m);
				enqueue(&z, count+1);
				visited[n - 1][m] = 1;
				flag = 1;
			}
			if (arr[n][m + 1] && !visited[n][m + 1]) {//오른쪽
				enqueue(&x, n);
				enqueue(&y, m + 1);
				enqueue(&z, count + 1);
				visited[n][m + 1] = 1;
				flag = 1;
			}
			if (arr[n + 1][m] && !visited[n + 1][m]) {//아래
				enqueue(&x, n + 1);
				enqueue(&y, m);
				enqueue(&z, count + 1);
				visited[n + 1][m] = 1;
				flag = 1;
			}
			if (arr[n][m - 1] && !visited[n][m - 1]) {//왼쪽
				enqueue(&x, n);
				enqueue(&y, m - 1);
				enqueue(&z, count + 1);
				visited[n][m - 1] = 1;
				flag = 1;
			}
			if (flag) count++;
		}

	
	printf("%d\n", count);
}