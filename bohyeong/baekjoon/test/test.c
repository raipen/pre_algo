#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//사이즈 우째?
#define MAX_VERTICES 100001
int visited[MAX_VERTICES];
int vertex;

typedef struct graphnode {

    int vertex;
    int weight;
    struct graphnode* link;
}graphnode;

typedef struct graphtype {

    int n;
    graphnode* adjlist[MAX_VERTICES];
}graphtype;

void init(graphtype* g)
{
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++)
    {
        g->adjlist[v] = NULL;
    }
}

void insert(graphtype* g, int v)
//그래프 g에 정점 v삽입
{
    if (((g->n) + 1) > MAX_VERTICES)
    {
        fprintf(stderr, "그래프 : 정점의 개수 초과");
        return;
    }
    g->n++;
    //정점을 하나 증가시킴
}

void insertEdge(graphtype* g, int u, int v, int w)
{
    graphnode* node;
    if (u >= (g->n) + 1 || v >= (g->n) + 1)
        //정점 uv의 번호가 그래프의 정점 개수보다 크면
    {
        fprintf(stderr, "그래프 : 정점 번호 오류");
        return;
    }
    node = (graphnode*)malloc(sizeof(graphnode));
    node->vertex = v;
    node->weight = w;
    node->link = g->adjlist[u];
    g->adjlist[u] = node;
    //정점 u의 인접 리스트에 node 삽입
}

//dfs
typedef struct queuetype
{
    int element[MAX_VERTICES];
    int front, rear;
    int size;

}queuetype;

void initqueue(queuetype* q)
{
    int i;
    q->size = 0;
    q->front = -1;
    q->rear = -1;
    for (i = 0; i < MAX_VERTICES; i++)
    {
        q->element[i] = 0;
    }
}

void enqueue(queuetype* q, int item)
{
    q->element[++(q->rear)] = item;
    q->size++;
}

int dequeue(queuetype* q)
{
    int item;
    item = q->element[++(q->front)];
    q->size--;
    return item;
}

void dfs(graphtype* g, int v)
{
    graphnode* w;
    visited[v] = 1;
    //printf("%d",v);
    for (w = g->adjlist[v]; w; w = w->link)
    {
        if (!visited[w->vertex])
        {
            dfs(g, w->vertex);
        }
    }
}

void print_list(graphtype* g) {
    graphnode* curr;
    for (int i = 1; i <= vertex; i++) {
        curr = g->adjlist[i];
        printf("정점 %d:", i);
        while (curr != NULL) {
            printf("간선- %d 가중치- %d ->", curr->vertex, curr->weight);
            curr = curr->link;
        }
        printf("\n");
    }
}




int main()
{
    graphtype* g;
    g = (graphtype*)malloc(sizeof(graphtype));
    init(g);
    //초기화 했는데 가중치 어케 표현하지 했어

    vertex = 0;
    scanf("%d", &vertex);
    for (int k = 0; k < vertex; k++)
    {
        insert(g, k);
    }//간선 수 만큼 칸 만들었어


    for (int i = 0; i < vertex; i++)
    {
        int node1 = 0;
        int node2 = 0;
        int weight = 0;
        scanf("%d", &node1);
        while (1)
        {
            scanf("%d", &node2);
            if (node2 == -1)
            {
                break;
            }
            scanf("%d", &weight);
            insertEdge(g, node1, node2, weight);

        }
    }

    print_list(g);
    //이렇게 그래프 만들고 나서 dfs? bfs?써서 길이가 제일 긴친구 찾고 그 친구로 이동
    //그다음에 계속 돌려서 그 뒤로 이어지는거 없을때 까지
    // 
    //int 하나 잡고 dfs돌린 값이 더 크면 교체
    //최종 반환하면 되지 않을까?

    return 0;
}