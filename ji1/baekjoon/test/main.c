#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
typedef struct {
    element* data;
    int capacity;
    int top;
}stack;

void init_stack(stack* s) {
    s->top = -1;
    s->capacity = 1;
    s->data = (element*)malloc(sizeof(element) * (s->capacity));
}

int is_empty(stack* s) {
    if (s->top == -1) {
        return 1;
    }
    return 0;
}

int is_full(stack* s) {
    if (s->top == (s->capacity - 1)) {
        return 1;
    }
    return 0;
}

void push(stack* s, element temp) {
    if (is_full(s)) {
        s->capacity *= 2;
        s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
    }

    s->data[++(s->top)] = temp;
}

element pop(stack* s) {

    if (is_empty(s)) {
        return 1;
    }

    return s->data[(s->top)--];
}


int main() { //구조체 포인터의 멤버에 접근할때는 -> 아니면 . 쓴다.

    char str[100];
    stack nivea;

    while (1) {
        int flag = 1;

        init_stack(&nivea);

        gets(str);
        if (!strcmp(str, ".")) break;
        //printf("입력된 문자열 : %s \n", str);
        int i = 0;
        element temp;
        do {
            if (str[i] == '(' || str[i] == '[') {
                push(&nivea, str[i]);
            }

            else if (str[i] == ')' || str[i] == ']') {
                temp = pop(&nivea);
                if (temp != '(' && str[i] == ')' || temp != '[' && str[i] == ']' || temp == 1) {
                    printf("no\n");
                    flag = 0;
                    break;
                }
            }

            i++;
        } while (str[i] != '.');

        if (flag) {
            printf("yes\n");
        }

    }

    return 0;
}