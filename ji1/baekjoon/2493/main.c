#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int height;
    int index;
}tower;

typedef struct {
    tower* arr;
    int top;
}stack;

stack* newStack(int size) {
    stack* temp = (stack*)malloc(sizeof(stack));
    temp->arr = (tower*)malloc(sizeof(tower) * size);
    temp->top = 0;
    return temp;
}

void push(stack* a, tower b) {
    a->arr[++a->top] = b;
}

tower peek(stack* a) {
    return a->arr[a->top];
}

tower pop(stack* a) {
    return a->arr[a->top--];
}

int isEmpty(stack* a) {
    return a->top == -1;
}

int* printArr(int* arr, int size) {
    for (int i = 0;i < size;i++) {
        printf("%d ", arr[i]);
    }
}

int* setArr(int n) {
    int* temp = (int*)malloc(sizeof(int) * n);
    for (int i = 0;i < n;i++) {
        scanf("%d", &temp[i]);
    }
    return temp;
}

int* calcArr(int* arr, int n) {
    int* result = (int*)calloc(n, sizeof(int));
    stack* s = newStack(n);
    for (int i = 0;i < n;i++) {
        while (!isEmpty(s) && peek(s).height < arr[i])
            pop(s);
        if (!isEmpty(s))
            result[i] = peek(s).index+1;
        tower temp = { arr[i],i };
        push(s,temp);
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = setArr(n);
    int* result = calcArr(arr, n);
    printArr(result,n);
    return 0;
}