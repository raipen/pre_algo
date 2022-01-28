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
	return s->data[(s->front + 1) % n]; //front+1 해주고 size로 나눠줘야지
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
	s->rear = (s->rear - 1 + n) % n; //rear가 -1이 됨을 방지하기위해 rear -1 + n을 해줘야함
	return temp;
}

void add_front(deque* s, int n, element data) { //front또한 더해줄 때 왼쪽으로 방향가야함
	if (is_full(s, n)) {
		return;
	}
	s->data[s->front] = data; //먼저 front에 data를 넣어주고
	s->front = (s->front - 1 + n) % n; //왼쪽으로 이동
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
	//	printf("시행- front: %d , rear: %d\n", s->front, s->rear);
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
		for (int i = 0; i < L-1; i++) {//얘는 왜 L-1이냐 -> 거리가 2이면 한번만 왼쪽으로 가면되지
			left(s, n);
			//printf("left시행- front: %d , rear: %d\n", s->front, s->rear);
		}
		delete_front(s, n);
	//	printf("1번시행- front: %d , rear: %d\n", s->front, s->rear);

		return;
	}

	else {
		for (int i = 0; i < R+1; i++) { //얘는 왜 R+1이냐 거리가 5면 해당 index까지 가야지 나중에 add_front해서 front다음에 바로 해당원소가 위치해있음
			right(s, n);
		//	printf("right시행- front: %d , rear: %d\n", s->front, s->rear);
		}
		delete_front(s, n);
	//	printf("1번시행- front: %d , rear: %d\n", s->front, s->rear);
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
//		printf("공백큐\n");
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
	//printf("숫자기입- front: %d , rear: %d\n", s.front, s.rear);

	count = 0;

	while (tc--) {
		scanf("%d", &num);
		find_way(&s, num, size);
		//deque_print(&s, size);
	}
	printf("%d\n", count);
}