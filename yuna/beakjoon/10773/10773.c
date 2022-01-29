//----- [10773] 스택/제로 -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


#define MAX_K 100000

typedef struct {
	int num;
}element;

element stack[MAX_K];
int top = -1;

void stack_push(element);
element stack_pop();
int stack_empty();


int main() {
	int k, sum = 0;
	element e;

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &e.num);

		if (e.num == 0)
			stack_pop();
		else
			stack_push(e);
	}

	while (!stack_empty()) {
		e = stack_pop();
		sum += e.num;
	}

	printf("%d", sum);

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