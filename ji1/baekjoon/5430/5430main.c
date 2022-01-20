#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
    int isReverse;
}range;
typedef struct {
    char command[100001];
    int size;
    int* arr;
    range r;
}contents;

contents* setContents() {
    contents* temp = (contents*)malloc(sizeof(contents));
    scanf("%s %d", temp->command, &temp->size);
    if (temp->size == 0) {
        scanf("%*c%*c%*c");//¿£ÅÍ ¿©´Â °ýÈ£ ´Ý´Â °ýÈ£ Áö¿ì±â
        return temp;
    }
    temp->arr = (int*)malloc(sizeof(int) * temp->size);
    scanf("%*c%*c");//¿£ÅÍ¶û ¿©´Â °ýÈ£ Áö¿ì±â
    for (int i = 0;i < temp->size;i++) {
        scanf("%d%*c", &temp->arr[i]);
    }
    return temp;
}

int setRange(contents* temp) {
    temp->r.start = 0;
    temp->r.end = temp->size - 1;
    temp->r.isReverse = 0;
    for (int i = 0;temp->command[i];i++) {
        if (temp->command[i] == 'R')
            temp->r.isReverse = !temp->r.isReverse;
        else if (temp->r.isReverse)
            temp->r.end--;
        else
            temp->r.start++;
    }
    return temp->r.end + 1 >= temp->r.start;
}

void printArr(contents* temp) {
    printf("[");
    for (int i = temp->r.isReverse ? temp->r.end : temp->r.start;temp->r.isReverse ? i >= temp->r.start : i <= temp->r.end; i = temp->r.isReverse ? i - 1 : i + 1) {
        if (i == (temp->r.isReverse ? temp->r.start : temp->r.end))
            printf("%d", temp->arr[i]);
        else
            printf("%d,", temp->arr[i]);
    }
    printf("]\n");
}

int main() {
    int c;
    scanf("%d", &c);

    contents* temp;
    while (c--) {
        temp = setContents();
        if (setRange(temp))
            printArr(temp);
        else
            printf("error\n");
    }
    return 0;
}