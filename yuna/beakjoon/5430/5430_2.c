//----- [5430] Å¥,µ¦/AC -----//
// µ¦ »ç¿ë

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_N 100000
#define MAX_D 100001
#define MAX_P 100002

typedef struct {
	int data;
} element;

element deque[MAX_D];
int front, rear;

void push_front(element e);
void push_back(element e);
element pop_front();
element pop_back();
int is_empty();
void init_deque();

void input_x(int x[], int n);
int AC(char p[]);

int main() {
	element e;
	int t, n, x[MAX_N];
	char p[MAX_P], temp;

	scanf("%d", &t);
	for (;t;t--) {
		scanf("%s", p);
		scanf("%d", &n);
		input_x(x, n);

		init_deque();
		for (int i = 0; i < n; i++) {
			e.data = x[i];
			push_back(e);
		}
		if (!AC(p))
			printf("error\n");
	}

	return 0;
}

void input_x(int x[], int n) {
	char temp;

	scanf("\n%c", &temp);

	if (n == 0) {
		scanf("%c", &temp);
		return;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		scanf("%c", &temp);
	}
}

int AC(char p[])
{
	int rev = 0;
	element e;

	for (int i = 0; i < strlen(p); i++) {
		if (p[i] == 'R')
			rev = (rev + 1) % 2;
		else {
			if (is_empty())
				return 0;

			if (rev)
				pop_back();
			else
				pop_front();
		}
	}

	printf("[");
	if (is_empty()) {
		printf("]\n");
		return 1;
	}

	while (1) {
		if (rev)
			e = pop_back();
		else
			e = pop_front();

		printf("%d", e.data);
		if (is_empty())
			break;
		printf(",");
	}
	printf("]\n");

	return 1;
}

void push_front(element e) {
	deque[front] = e;
	front = (front - 1 + MAX_D) % MAX_D;
}

void push_back(element e) {
	rear = (rear + 1 + MAX_D) % MAX_D;
	deque[rear] = e;
}

element pop_front() {
	front = (front + 1 + MAX_D) % MAX_D;
	return deque[front];
}

element pop_back() {
	element e = deque[rear];
	rear = (rear - 1 + MAX_D) % MAX_D;
	return e;
}

int is_empty() {
	if (front == rear)
		return 1;
	return 0;
}

void init_deque() {
	front = 0;
	rear = 0;
}