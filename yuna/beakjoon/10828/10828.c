//----- [10828] 스택/스택 -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_N 100000

typedef struct {
	int data;
} element;

element stack[MAX_N];
int top = -1;

void stack_push(element);
element stack_pop();
int stack_empty();


int main() {
	int n;
	char input[10];
	element e;

	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &input);

		if (strcmp(input, "push") == 0) {
			scanf("%d\n", &e.data);
			stack_push(e);
		}
		else if (strcmp(input, "pop") == 0) {
			if (stack_empty())
				printf("-1\n");
			else
			{
				e = stack_pop();
				printf("%d\n", e.data);
			}
		}
		else if (strcmp(input, "size") == 0) {
			printf("%d\n", top + 1);
		}
		else if (strcmp(input, "empty") == 0) {
			printf("%d\n", stack_empty());
		}
		else if (strcmp(input, "top") == 0) {
			if (stack_empty())
				printf("-1\n");
			else
				printf("%d\n", stack[top].data);
		}
	}

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