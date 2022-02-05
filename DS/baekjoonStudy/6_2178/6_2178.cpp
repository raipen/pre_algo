#include <iostream>
#include <string>

using namespace std;

typedef struct node{
	int data;
	struct node* prev;
}node;

typedef struct node* nodePointer;

int** arr;
int* queue;
int** visited;
int front = -1;
int rear = -1;
nodePointer* cur;

void bfs(int, int, nodePointer*);
void qadd(int);
int qdelete();

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	char** tmp;
	int count = 0;
	nodePointer a;
	nodePointer ptr = NULL;

	cin >> N >> M;

	cur = new nodePointer[N*M+1];
	arr = new int* [N + 2];
	visited = new int* [N + 2];
	queue = new int[100];
	tmp = new char* [N];

	for (int i = 0; i < N; i++) tmp[i] = new char[M]();
	for (int i = 0; i < N + 2; i++) {
		arr[i] = new int[M + 2]();
		visited[i] = new int[M + 2]();
	}
	for (int i = 0; i < N; i++) cin >> tmp[i];

	for (int i = 0; i < N + 2; i++) {
		arr[i][0] = 0;
		arr[i][M + 1] = 0;
		visited[i][0] = 0;
		visited[i][M+1] = 0;

	}

	for (int i = 0; i < M + 2; i++) {
		arr[0][i] = 0;
		arr[N + 1][i] = 0;
		visited[0][i] = 0;
		visited[N+1][i] = 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i + 1][j + 1] = tmp[i][j] - 48;
			visited[i+1][j+1] = 0;
		}
	}

	qadd(1);
	visited[1][1] = 1;
	a = new node;
	a->data = 1;
	a->prev = NULL;
	cur[1] = a;

	bfs(N, M, &a);
	ptr = cur[N * M];

	while (ptr != NULL) {
		ptr = ptr->prev;
		count++;
	}

	cout << count;

	return 0;
}

void bfs(int N, int M, nodePointer *a) {
	int i = 1, j = 1;
	int num1 = 0;

	while (1) {
		if (visited[N][M] == 1) break;

		num1 = qdelete();

		if (num1 == -1) break;

		i = (num1 - 1) / M + 1;
		j = (num1 -1 ) % M + 1;

		if (arr[i+1][j] == 1 && visited[i + 1][j] == 0) {
			qadd(num1 + M);
			visited[i+1][j] = 1;
			*a = new node;
			(*a)->data = num1 + M;
			(*a)->prev = cur[num1];
			cur[num1 + M] = *a;
		}

		if (arr[i][j+1] == 1 && visited[i][j + 1] == 0) {
			qadd(num1+1);
			visited[i][j+1] = 1;
			*a = new node;
			(*a)->data = num1 + 1;
			(*a)->prev = cur[num1];
			cur[num1 + 1] = *a;
		}
		if (arr[i-1][j] == 1 && visited[i - 1][j] == 0) {
			qadd(num1-M);
			visited[i-1][j] = 1;
			*a = new node;
			(*a)->data = num1 - M;
			(*a)->prev = cur[num1];
			cur[num1 - M] = *a;
		}
		if (arr[i][j-1] == 1 && visited[i][j - 1] == 0) {
			qadd(num1-1);
			visited[i][j-1] = 1;
			*a = new node;
			(*a)->data = j;
			(*a)->prev = cur[num1];
			cur[num1 - 1] = *a;
		}
	}
}

void qadd(int n) {
	queue[++rear] = n;
}
int qdelete() {
	if (front == rear) return -1;

	return queue[++front];
}