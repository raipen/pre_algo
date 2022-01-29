//----- [1874] 스택/스택 수열 -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_N 100000
#define PUSH 1
#define POP 0

typedef struct {
	int data;
} element;

element stack[MAX_N];
int top;

int oper[MAX_N * 2], oper_cnt = 0;

void stack_push(element);
element stack_pop();
int stack_empty();

int is_possible(int);
void print_oper();

int main() {
	int n;

	scanf("%d", &n);

	if (is_possible(n))
		print_oper();
	else
		printf("NO");

	return 0;
}


int is_possible(int n) {
	element input, e;
	int pos = 1, max = 0;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &input.data);
		if (!pos)
			continue;

		while (input.data > max) {
			e.data = ++max;
			stack_push(e);
			oper[oper_cnt++] = PUSH;
		}

		while (1) {
			if (stack_empty()) {
				pos = 0;
				break;
			}

			e = stack_pop();
			oper[oper_cnt++] = POP;

			if (e.data == input.data)
				break;
		}
	}

	if (pos)
		return 1;
	return 0;
}

void print_oper() {
	for (int i = 0; i < oper_cnt; i++)
		if (oper[i] == PUSH)
			printf("+\n");
		else
			printf("-\n");
}

void stack_push(element e) {
	stack[++top] = e;
}

element stack_pop() {
	return stack[top--];
}

int stack_empty() {
	if (top == -1)
		return 1;

	return 0;
}