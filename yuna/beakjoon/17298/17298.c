//----- [17298] 스택/오큰수 -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_N 1000000

typedef struct {
	int a;
	int index;
} DATA;
typedef struct {
	DATA data;
} element;

element stack[MAX_N];
int top = -1;

void stack_push(element);
element stack_pop();
int stack_empty();

int nge[MAX_N];

int main() {
	int n;
	element input, e;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &input.data.a);
		input.data.index = i;

		while (!stack_empty()) {
			if (input.data.a > stack[top].data.a) {
				e = stack_pop();
				nge[e.data.index] = input.data.a;
			}
			else
				break;
		}
		stack_push(input);
	}

	while (!stack_empty()) {
		e = stack_pop();
		nge[e.data.index] = -1;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", nge[i]);

	return 0;
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