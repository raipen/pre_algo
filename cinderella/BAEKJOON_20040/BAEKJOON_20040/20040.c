#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int from;
    int to;
}intX;

int ver_num, edge_num;
int parent[5001000];
intX input[5001000];

int cnt = 0;

int find(int );

int main()
{
    scanf_s("%d %d", &ver_num, &edge_num);

    for (int i = 0; i < ver_num; i++)
        parent[i] = i;

    for (int i = 0; i < edge_num; i++)
        scanf_s("%d %d", &input[i].from, &input[i].to);

    for (int i = 0; i < edge_num; i++)
    {
        cnt++;

        int parent1 = find(input[i].from);
        int parent2 = find(input[i].to);

        if (parent1 == parent2)  break;
        else   parent[input[i].from] = parent2;
    }

    if (cnt == edge_num) printf("0");
    else printf("%d", cnt);

    return 0;
}

int find(int s)
{
    if (parent[s] == s)
    {
        return s;
    }
    else
    {
        return parent[s] = find(parent[s]);
    }
}