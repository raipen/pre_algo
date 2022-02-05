#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 999999999//도로의 초기값 10000*400보다 커야함
int ver_num;//마을의 개수
int edge_num;//도로의 개수
int town[401][401];//마을과 거리의 정보를 담는 배열 town
void floyd();//vertex별 최소거리 구하기
void init_town();//town의 모든정보 초기화
int find_short();//사이클을 이루는 마을중 작은값 구하기
int main()
{
	int start, end,length,min;
	scanf("%d %d", &ver_num, &edge_num);
	init_town();
	for (int i = 0; i < edge_num; i++)//마을의 연결여부와 도로의 길이 입력
	{
		scanf("%d %d %d", &start, &end, &length);
		town[start][end] = length;
	}

	floyd();//town을 경로별 최단거리로 정보 초기화
	min=find_short();//사이클을 이루는 것 중 가장 작은값 구하기
	printf("%d", min);
	return 0;
}
void init_town()
{
	for (int i = 0; i < 401; i++)
		for (int j = 0; j < 401; j++)
			town[i][j] = INF;
}
void floyd()
{
	for (int k = 1; k <= ver_num; k++)//거쳐가는 노드
	{
		for (int i = 1; i <= ver_num; i++)//출발 노드
		{
			for (int j = 1; j <= ver_num; j++)//도착 노드
			{
				if (town[i][k] + town[k][j] < town[i][j])
				{
					town[i][j] = town[i][k] + town[k][j];
				}
			}
		}
	}
}
int find_short()
{
	int min = INF;
	for (int i = 1; i <= ver_num; i++)
	{
		if (town[i][i] < min)
		{
			min = town[i][i];//만약 town[i][i]가 INF가 아니라면 사이클을 이루었다는 뜻이므로 min에다가 받아주기
		}
	}
	if (min == INF)
		return -1;
	return min;
}