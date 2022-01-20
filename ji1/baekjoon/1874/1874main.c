#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int stack[1000000], top = -1, val = 1, size, cnt;
char str[1000000];

void push(int val) {
    stack[++top] = val;
    str[cnt++] = '+';
}

void pop() {
    stack[top--] = 0;
    str[cnt++] = '-';
}

int st() {
    for (int i = 0; i < size; i++) {
        int n;
        scanf("%d", &n);

        if (stack[top] == n) pop();
        else if (stack[top] < n) {
            while (stack[top] != n) {
                push(val++);
            }
            pop();
        }
        else return 0;
    }
    return 1;
}

int main() {
    scanf("%d", &size);
    if (st()) for (int i = 0; i < cnt; i++) printf("%c\n", str[i]);
    else printf("NO");

    return 0;
}