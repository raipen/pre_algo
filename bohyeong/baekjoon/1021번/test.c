//덱 구현하기 
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
	if ((s->rear + 1) % n == s->front) { //rear와 front가 한칸차이일때
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

element get_front(deque* s, int n) { //front 에는 빈 배열이 들어가있으니까
	if (is_empty(s)) {
		return -1;
	}
	return s->data[(s->front+1)% n]; //front+1 해주고 size로 나눠줘야지
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
	s->rear = (s->rear - 1 + n) % n; //rear가 -1이 됨을 방지하기위해 rear -1 + n을 해줘야함
	return temp;
}

void add_front(deque* s, int n, element data) { //front또한 더해줄 때 왼쪽으로 방향가야함
	if (is_full(s)) {
		return;
	}
	s->data[s->front] = data; //먼저 front에 data를 넣어주고
	s->front = (s->front - 1+n) % n; //왼쪽으로 이동
	return;
}