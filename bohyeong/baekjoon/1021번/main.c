#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct {
	element* data;
	int front, rear;
}deque;

int count;

void init_queue(deque* s, int n) {
	s->data = (element*)malloc(sizeof(element) * n);
	s->front = s->rear = 0;
}

int is_empty(deque* s) {
	return (s->front == s->rear);
}

int is_full(deque* s, int n) {
	if ((s->rear + 1) % n == s->front) { //rear�� front�� ��ĭ�����϶�
		return 1;
	}
	return 0;
}

element get_rear(deque* s) {
	if (is_empty(s)) {
		return -1;
	}
	element temp = s->data[s->rear];
	return temp;
}

element get_front(deque* s, int n) { //front ���� �� �迭�� �������ϱ�
	if (is_empty(s)) {
		return -1;
	}
	return s->data[(s->front + 1) % n]; //front+1 ���ְ� size�� ���������
}

void add_rear(deque* s, int n, element data) {
	if (is_full(s, n)) {
		return;
	}
	s->rear = (s->rear + 1) % n;
	s->data[s->rear] = data;
	return;
}

element delete_front(deque* s, int n) {
	if (is_empty(s)) {
		return -1;
	}

	element temp = get_front(s, n);
	s->data[s->front] = 0;
	s->front = (s->front + 1) % n;
	return temp;
}

element delete_rear(deque* s, int n) {
	if (is_empty(s)) {
		return -1;
	}
	element temp = get_rear(s, n);
	s->data[s->rear] = 0;
	s->rear = (s->rear - 1 + n) % n; //rear�� -1�� ���� �����ϱ����� rear -1 + n�� �������
	return temp;
}

void add_front(deque* s, int n, element data) { //front���� ������ �� �������� ���Ⱑ����
	if (is_full(s, n)) {
		return;
	}
	s->data[s->front] = data; //���� front�� data�� �־��ְ�
	s->front = (s->front - 1 + n) % n; //�������� �̵�
	return;
}

void left(deque* s, int n) {
	element num = delete_front(s, n);
	add_rear(s, n, num);
	count++;
}

void right(deque* s, int n) {
	element num = delete_rear(s, n);
	add_front(s, n, num);
	count++;
}

void find_way(deque* s, int num, int n) {
	int curr = (s->front+1)%n;
	int w;
	int idx;

	
	if (s->data[curr] == num) {
		delete_front(s, n);
	//	printf("����- front: %d , rear: %d\n", s->front, s->rear);
		return;
	}

	while (s->data[curr] != num) {
		curr = (curr + 1) % n;
	}
	idx = curr;
	int R = 0, L = 0;
	while ((idx+n) % n != s->front) {
		idx--;
		L++;
	}

	idx = curr;
	while (idx % n != s->rear) {
		idx++;
		R++;
	}
	//printf("curr: %d [%d %d]\n", curr, L, R);
	//printf("curr: %d, left: %d, right: %d\n", curr, abs(s->front - curr), R);
	if (L <= R+1) {
		for (int i = 0; i < L-1; i++) {//��� �� L-1�̳� -> �Ÿ��� 2�̸� �ѹ��� �������� �������
			left(s, n);
			//printf("left����- front: %d , rear: %d\n", s->front, s->rear);
		}
		delete_front(s, n);
	//	printf("1������- front: %d , rear: %d\n", s->front, s->rear);

		return;
	}

	else {
		for (int i = 0; i < R+1; i++) { //��� �� R+1�̳� �Ÿ��� 5�� �ش� index���� ������ ���߿� add_front�ؼ� front������ �ٷ� �ش���Ұ� ��ġ������
			right(s, n);
		//	printf("right����- front: %d , rear: %d\n", s->front, s->rear);
		}
		delete_front(s, n);
	//	printf("1������- front: %d , rear: %d\n", s->front, s->rear);
		return;
	}
}

//void deque_print(deque* q, int n) {
//
//	int i = (q->front + 1) % n;
//
//	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
//
//	if (is_empty(q)) {
//
//		printf("����ť\n");
//
//		return;
//
//	}
//	while (i != q->rear) {
//
//		printf("%d | ", q->data[i]);
//
//		i = (i + 1) % n;
//
//	}
//	printf("%d\n", q->data[i]);
//
//}



int main() {
	int n, tc;
	int size, num;
	scanf("%d %d", &n, &tc);
	size = n + 1;
	deque s;
	init_queue(&s, size);
	for (int i = 1; i < size; i++) {
		add_rear(&s, size, i);
	}
	//printf("���ڱ���- front: %d , rear: %d\n", s.front, s.rear);

	count = 0;

	while (tc--) {
		scanf("%d", &num);
		find_way(&s, num, size);
		//deque_print(&s, size);
	}
	printf("%d\n", count);
}