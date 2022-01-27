//----- [4949] Ω∫≈√/±’«¸¿‚»˘ ººªÛ -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_L 100

typedef struct {
	char data;
} element;

element stack[MAX_L];
int top;

void stack_push(element);
element stack_pop();
int stack_empty();

int is_balance(char[]);

int main() {
	char input[MAX_L + 2];

	while (1) {
		fgets(input, MAX_L + 2, stdin);
		if (input[0] == '.')
			break;

		top = -1;
		if (is_balance(input))
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}

int is_balance(char input[]) {
	element e;

	for (int i = 0; i < strlen(input); i++) {
		switch (input[i]) {
		case '(':
		case '[':
			e.data = input[i];
			stack_push(e);
			break;

		case ')':
			if (stack_empty())
				return 0;

			e = stack_pop();
			if (e.data != '(')
				return 0;
			break;

		case ']':
			if (stack_empty())
				return 0;

			e = stack_pop();
			if (e.data != '[')
				return 0;
		}
	}

	if (stack_empty())
		return 1;

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