#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N[1000000];
int st1[1000000];
int top1 = -1;
int st2[1000000];
int top2 = -1;

void push1(int v) {
    st1[++top1] = v;
}

int pop1() {
    return st1[top1--];
}

void push2(int v) {
    st2[++top2] = v;
}

int pop2() {
    return st2[top2--];
}



void right(int n) {
    for (int i = 0; i < n; i++) {
        //N[i] = rand();
        //printf("%d ", N[i]);
        scanf("%d", &N[i]);
    }
    push1(-1);
    push2(N[n - 1]);
    for (int i = n - 2;i > -1;i--) {
        if (N[i] < N[i + 1]) {
            push1(N[i + 1]);
            push2(N[i]);
        }
        else if (N[i] == N[i + 1]) {
            push1(st1[top1]);
        }
        else {
            while (top2 != -1 && st2[top2] <= N[i]) pop2();
            if (top2 == -1) push1(-1);
            else push1(st2[top2]);
            push2(N[i]);
        }
    }


    for (int i = 0; i < n; i++) {
        printf("%d ", pop1());
    }
}

int main() {
    int n;
    scanf("%d", &n);
    right(n);
    return 0;
}