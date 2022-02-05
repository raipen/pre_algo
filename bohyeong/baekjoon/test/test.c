#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//������ ��°?
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
//�׷��� g�� ���� v����
{
    if (((g->n) + 1) > MAX_VERTICES)
    {
        fprintf(stderr, "�׷��� : ������ ���� �ʰ�");
        return;
    }
    g->n++;
    //������ �ϳ� ������Ŵ
}

void insertEdge(graphtype* g, int u, int v, int w)
{
    graphnode* node;
    if (u >= (g->n) + 1 || v >= (g->n) + 1)
        //���� uv�� ��ȣ�� �׷����� ���� �������� ũ��
    {
        fprintf(stderr, "�׷��� : ���� ��ȣ ����");
        return;
    }
    node = (graphnode*)malloc(sizeof(graphnode));
    node->vertex = v;
    node->weight = w;
    node->link = g->adjlist[u];
    g->adjlist[u] = node;
    //���� u�� ���� ����Ʈ�� node ����
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
        printf("���� %d:", i);
        while (curr != NULL) {
            printf("����- %d ����ġ- %d ->", curr->vertex, curr->weight);
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
    //�ʱ�ȭ �ߴµ� ����ġ ���� ǥ������ �߾�

    vertex = 0;
    scanf("%d", &vertex);
    for (int k = 0; k < vertex; k++)
    {
        insert(g, k);
    }//���� �� ��ŭ ĭ �������


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
    //�̷��� �׷��� ����� ���� dfs? bfs?�Ἥ ���̰� ���� ��ģ�� ã�� �� ģ���� �̵�
    //�״����� ��� ������ �� �ڷ� �̾����°� ������ ����
    // 
    //int �ϳ� ��� dfs���� ���� �� ũ�� ��ü
    //���� ��ȯ�ϸ� ���� ������?

    return 0;
}