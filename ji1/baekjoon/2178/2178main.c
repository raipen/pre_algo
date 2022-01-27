#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int r;
    int c;
}coordinate;
typedef struct {
    coordinate c;
    int q;
}element;

typedef struct {
    element** data;
    int size;
}Adj_matrix;

typedef struct q {
    element value;
    struct q* link;
}q_node;
typedef struct {
    struct q* front;
    struct q* rear;
}queue;

//링크드 큐 구현 시작
queue* newQ() {
    queue* que = (queue*)malloc(sizeof(queue));
    que->front = NULL;
    que->rear = NULL;
    return que;
}

void freeQ(queue* this) {
    while (this->front != NULL) {
        q_node* temp = this->front;
        this->front = this->front->link;
        free(temp);
    }
    free(this);
}

int isEmpty(queue* this) {
    return this->front == NULL ? 1 : 0;
}

void addq(queue* this, element value) {
    q_node* temp = (q_node*)malloc(sizeof(q_node));
    temp->value = value;
    temp->link = NULL;
    if (this->front)
        this->rear->link = temp;
    else
        this->front = temp;
    this->rear = temp;
}

element deleteq(queue* this) {
    q_node* temp = this->front;
    element item = temp->value;
    this->front = temp->link;
    free(temp);
    return item;
}
//링크드 큐 구현 끝

int  a[102][102] = { 0 };

int r(int n, int m) {
    coordinate dir[4] = { {-1,0},{0,1},{1,0},{0,-1} };
    int p[102][102] = { 0 };
    queue* q = newQ();
    element c = { { 1,1 },1 };
    p[c.c.r][c.c.c] = 1;
    addq(q, c);
    while (1) {
        c = deleteq(q);
        //printf("%d %d %d\n", c.c.r, c.c.c,c.q);
        if (c.c.r == n && c.c.c == m) return c.q;
        for (int i = 0;i < 4;i++) {
            //printf("%d %d %d\n", c.c.r + dir[i].r, c.c.c + dir[i].c, a[c.c.r + dir[i].r][c.c.c + dir[i].c]);
            if (a[c.c.r + dir[i].r][c.c.c + dir[i].c]&& !p[c.c.r + dir[i].r][c.c.c + dir[i].c]) {
                p[c.c.r + dir[i].r][c.c.c + dir[i].c] = 1;
                element temp = { { c.c.r + dir[i].r,c.c.c + dir[i].c } ,c.q+1};
                addq(q, temp);
            }
        }
    }
}


int main() {
    int n, m;
    char t;
    scanf("%d %d", &n, &m);
    getchar();//\n버리기
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            scanf("%c", &t);
            a[i][j] = t == '0' ? 0 : 1;
        }
        getchar();//\n버리기
    }
    printf("%d", r(n, m));

	return 0;
}