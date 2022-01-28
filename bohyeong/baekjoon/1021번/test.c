//�� �����ϱ� 
#include <stdio.h>

typedef int element;

typedef struct {
	element* data;
	int front,rear;
}deque;

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
	return s->data[(s->front+1)% n]; //front+1 ���ְ� size�� ���������
}

void add_rear(deque* s, int n, element data) {
	if (is_full(s)) {
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

	element temp = get_front(s,n);
	s->front = (s->front + 1) % n;
	return temp;
}

element delete_rear(deque* s, int n) {
	if (is_empty(s)) {
		return -1;
	}
	element temp = get_rear(s, n);
	s->rear = (s->rear - 1 + n) % n; //rear�� -1�� ���� �����ϱ����� rear -1 + n�� �������
	return temp;
}

void add_front(deque* s, int n, element data) { //front���� ������ �� �������� ���Ⱑ����
	if (is_full(s)) {
		return;
	}
	s->data[s->front] = data; //���� front�� data�� �־��ְ�
	s->front = (s->front - 1+n) % n; //�������� �̵�
	return;
}