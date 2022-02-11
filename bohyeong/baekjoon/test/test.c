#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int cnt = 0;
int ver_num;
int edge_num;
int parent[500100];
int flag = 0;
void init();
void union_ver(int start, int end);
int is_same_parent(int start, int end);
int find_parent(int sibiling);
int main()
{
    int start, end;
    scanf("%d %d", &ver_num, &edge_num);
    init();
    for (int i = 0; i < edge_num; i++)
    {
        scanf("%d %d", &start, &end);

        union_ver(start, end);
        ++cnt;
       
        if (flag)
        {
            printf("%d\n", cnt);
            return 0;
        }
 
    }
    printf("0\n");
    return 0;
}
void init()
{
    for (int i = 0; i < ver_num; i++)
    {
        parent[i] = i;
    }
}
void union_ver(int start, int end)
{
    if (is_same_parent(start, end)) {
        flag = 1;
    }

    start = find_parent(start);
    end = find_parent(end);
    if (start < end)
    {
        parent[end] = start;
    }
    else
    {
        parent[start] = end;
    }
}

int is_same_parent(int start, int end)
{
    int parent1, parent2;
    parent1 = find_parent(start);
    parent2 = find_parent(end);
    if (parent1 == parent2)
        return 1;
    return 0;
}
int find_parent(int sibiling)
{
    if (parent[sibiling] == sibiling)
    {
        return sibiling;
    }
    else return parent[sibiling] = find_parent(parent[sibiling]);

}