#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct {
    int row;
    int col;
}coordinate;

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

typedef struct {
    queue* a;
    queue* b;
}stack;

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

Adj_matrix newAM(int size) {
    Adj_matrix temp;
    temp.size = size;
    temp.data = (int**)malloc(sizeof(int*) * temp.size);
    for (int i = 0;i < temp.size;i++) {
        temp.data[i] = (int*)calloc(temp.size, sizeof(int));
    }
    return temp;
}

void printAM(Adj_matrix this) {
    for (int i = 0;i < this.size;i++) {
        for (int j = 0;j < this.size;j++) {
            printf("%d  ", this.data[i][j]);
        }
        printf("\n");
    }
}

int _gcd(int a, int b) {
    int gcd = 1;
    for (int i = 1; i <= a && i <= b; ++i) {
        if (a % i == 0 && b % i == 0)
            gcd = i;
    }
    return gcd;
}

void printArr(int* a, int size, int g) {
    for (int i = 0;i < size;i++) {
        printf("%d ", a[i] / g);
    }
    printf("\n");
}

int bfs(int a, int p, Adj_matrix matrix, int* node) {
    int* isPrinted = (int*)calloc(matrix.size, sizeof(int));
    queue* que = newQ();
    node[a] *= p;
    isPrinted[a] = 1;
    addq(que, a);
    int cur;
    while (!isEmpty(que)) {
        cur = deleteq(que);
        int i;
        for (i = 0;i < matrix.size;i++) {
            if (matrix.data[cur][i] && !isPrinted[i]) {
                node[i] *= p;
                isPrinted[i] = 1;
                addq(que, i);
            }
        }
    }
    freeQ(que);
    return 1;
}

int main() {
    int c;
    scanf("%d", &c);

    Adj_matrix m = newAM(c);
    int* node = (int*)malloc(c * sizeof(int));
    for (int i = 0;i < c;i++) {
        node[i] = 1;
    }
    int a, b, p, q;
    c--;
    while (c--) {
        scanf("%d %d %d %d", &a, &b, &p, &q);
<<<<<<< HEAD
        int gcd = _gcd(node[a], node[b]);   //a와 b의 최대공약수 구하기
        p *= node[b] / gcd; // a*b/gcd ==최소 공배수, 즉 node[a]에 node[b]/gcd를 곱하면 최소 공배수가 된다 -> (최고공배수) * (p와 q의 비율)
        q *= node[a] / gcd;
        bfs(a, p, m, node); //a와 관련된 모든것에 p만큼 곱하기
        bfs(b, q, m, node); //b와 관련된 모든것에 q만큼 곱하기
        m.data[a][b] = 1;   //a와 b를 서로 연결된 것으로 변경
        m.data[b][a] = 1;   //a와 b를 서로 연결된 것으로 변경
=======
        int gcd = _gcd(node[a], node[b]);
        p *= node[b] / gcd;
        q *= node[a] / gcd;
        bfs(a, p, m, node);
        bfs(b, q, m, node);
        m.data[a][b] = 1;
        m.data[b][a] = 1;
>>>>>>> 455c203c9f5f174e33d0bbae9310c7b33361ef74
    }

    int g = node[0];
    for (int i = 1;i < m.size;i++) {
        g = _gcd(g, node[i]);
    }
<<<<<<< HEAD
    //g는 전체 node[0]~node[n-1]까지의 최대공약수
    printArr(node, m.size, g);  //node에 있는 값을 g로 나눠서 출력
=======
    printArr(node, m.size, g);
>>>>>>> 455c203c9f5f174e33d0bbae9310c7b33361ef74

    return 0;
}