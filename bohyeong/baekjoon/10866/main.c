#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

typedef int element;
typedef struct {
	element* data;
	int front, rear;
	int count;
}deque;

int is_empty(deque* s) {
	return (s->front == s->rear);
}

int is_full(deque* s) {
	if ((s->rear + 1) % MAX == s->front) {
		return 1;
	}
	return 0;
}

void init_queue(deque* s) {
	s->data = (element*)malloc(sizeof(element) * MAX);
	s->front = s->rear = 0;
}

element get_front(deque* s) {
	if (is_empty(s)) {
		return -1;
	}
	return s->data[(s->front + 1) % MAX];
}

element get_rear(deque* s) {
	if (is_empty(s)) {
		return -1;
	}
	return s->data[(s->rear)];
}

void add_front(deque* s, int data) {
	if (is_full(s)) {
		return;
	}
	s->data[s->front] = data;
	s->front = (s->front - 1 + MAX) % MAX;
	s->count++;
	return;
}

void add_rear(deque* s, int data) {
	if (is_full(s)) {
		return;
	}
	s->data[(s->rear + 1) % MAX] = data;
	s->rear = (s->rear + 1) % MAX;
	s->count++;
	return;
}

element pop_front(deque* s) {
	if (is_empty(s)) {
		return -1;
	}
	element temp = get_front(s);
	s->front = (s->front + 1) % MAX;
	s->count--;
	return temp;
}

element pop_rear(deque* s) {
	if (is_empty(s)) {
		return -1;
	}
	element temp = get_rear(s);
	s->rear = (s->rear - 1+MAX) % MAX;
	s->count--;
	return temp;
}

void init_comm(char *s) {
	int i = 0;
	while (s[i] != '\0') {
		s[i] = '\0';
		i++;
	}
}

int main() {
	int size = 0;
	int num;
	char comm[100];
	
	init_comm(comm);
	scanf("%d ", &size);
	element temp;
	deque queue;
	queue.count = 0;
	init_queue(&queue);
	
	while(size--){
		init_comm(comm);
		scanf("%s", comm);

		if (!strcmp("push_front", comm)) {
			scanf(" %d", &num);
			add_front(&queue, num);
		}
		else if (!strcmp("push_back", comm)) {
			scanf(" %d", &num);	
			add_rear(&queue, num);
		}
		else if (!strcmp("pop_front", comm)) {
			temp = pop_front(&queue);
			printf("%d\n", temp);
		}
		else if (!strcmp("pop_back", comm)) {
			temp = pop_rear(&queue);
			printf("%d\n", temp);
		}
		else if (!strcmp("size", comm)) {
			printf("%d\n", queue.count);
		}
		else if (!strcmp("empty", comm)) {
			num = is_empty(&queue);
			printf("%d\n", num);
		}
		else if (!strcmp("front", comm)) {
			temp = get_front(&queue);
			printf("%d\n", temp);
		}
		else {
			temp = get_rear(&queue);
			printf("%d\n", temp);
		}
	}


	return 0;
}