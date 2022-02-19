#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 987654321 // 최대값:10만*100+1
void floyd();
typedef struct city
{
	int weight;
	int cnt;
	int via[100];
}city;
city ary[101][101];
int ver_num;
int edge_num;

int main()
{
	int tmp;
	scanf("%d", &ver_num);
	scanf("%d", &edge_num);
	for (int i = 1; i <= ver_num; i++)
		for (int j = 1; j <= ver_num; j++)
		{
			ary[i][j].weight = INF;
			if (i == j)
				ary[i][j].weight = 0;//i==f일때 0으로 초기화한 이유: INF로 박으면 1->3->1로 갈수 있는 경우가 만들어짐 문제 조건에 부합x
		}
	for (int k = 1; k <= edge_num; k++)
	{
		int start, end;
		scanf("%d %d", &start, &end);
		scanf("%d", &tmp);
		if (tmp < ary[start][end].weight)//1->3으로 갈수 있는 길이 여러가지가 주어짐 따라서 더 작은 값을 넣어줌
		{
			ary[start][end].weight = tmp;
			ary[start][end].via[0] = start;
			ary[start][end].via[1] = end;//via배열을 통해 현재 어떤 경로를 이용해 간선의 정보가 초기화 됐는지 처리
			ary[start][end].cnt = 2;//지나온 vertex의 개수( 처음에는 항상 0 or 2)
		}
	}
	floyd();
	for (int i = 1; i <= ver_num; i++)
	{
		for (int j = 1; j <= ver_num; j++)
		{
			if (ary[i][j].weight == INF)
				printf("0 ");
			else
				printf("%d ", ary[i][j].weight);
		}
		printf("\n");
	}
	for (int i = 1; i <= ver_num; i++)
	{
		for (int j = 1; j <= ver_num; j++)
		{
			if (ary[i][j].weight == INF||(!ary[i][j].weight))
				printf("0 ");
			else
			{
				printf("%d ", ary[i][j].cnt);
				for (int k = 0; k < ary[i][j].cnt; k++)
				{
					printf("%d ", ary[i][j].via[k]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
void floyd()
{
	for (int i = 1; i <= ver_num; i++)//거쳐가는 노드
	{
		for (int j = 1; j <= ver_num; j++)//출발
		{
			for (int k = 1; k <= ver_num; k++)//도착
			{
				if ((j!=k) &&ary[j][i].weight + ary[i][k].weight < ary[j][k].weight)//출발과 도착이 같지 않고,거쳐간 경우의 도로가 더 짧으면 바꾸기
				{
					ary[j][k].weight = ary[j][i].weight + ary[i][k].weight;
					ary[j][k].cnt = ary[j][i].cnt + ary[i][k].cnt - 1;//n개의 vertex +m개의 vertex=하나의 vertex가 겹치기 떄문에 (n+m-1)vertex  ex)(1->2->4)+(4->3)=1->2->3
					for (int idx = 0; idx < ary[j][i].cnt; idx++)//(1->3->4)까지 저장
					{
						ary[j][k].via[idx] = ary[j][i].via[idx];
					}
					for (int idx = ary[j][i].cnt,x=1; x <  ary[i][k].cnt;x++, idx++)//(4->3)에서 4를 빼고 ->3만 저장
					{
						ary[j][k].via[idx] = ary[i][k].via[x];
					}
				}
			}
		}
	}
}