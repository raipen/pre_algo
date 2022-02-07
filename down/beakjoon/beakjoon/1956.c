#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 999999999//������ �ʱⰪ 10000*400���� Ŀ����
int ver_num;//������ ����
int edge_num;//������ ����
int town[401][401];//������ �Ÿ��� ������ ��� �迭 town
void floyd();//vertex�� �ּҰŸ� ���ϱ�
void init_town();//town�� ������� �ʱ�ȭ
int find_short();//����Ŭ�� �̷�� ������ ������ ���ϱ�
int main()
{
	int start, end,length,min;
	scanf("%d %d", &ver_num, &edge_num);
	init_town();
	for (int i = 0; i < edge_num; i++)//������ ���Ῡ�ο� ������ ���� �Է�
	{
		scanf("%d %d %d", &start, &end, &length);
		town[start][end] = length;
	}

	floyd();//town�� ��κ� �ִܰŸ��� ���� �ʱ�ȭ
	min=find_short();//����Ŭ�� �̷�� �� �� ���� ������ ���ϱ�
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
	for (int k = 1; k <= ver_num; k++)//���İ��� ���
	{
		for (int i = 1; i <= ver_num; i++)//��� ���
		{
			for (int j = 1; j <= ver_num; j++)//���� ���
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
			min = town[i][i];//���� town[i][i]�� INF�� �ƴ϶�� ����Ŭ�� �̷���ٴ� ���̹Ƿ� min���ٰ� �޾��ֱ�
		}
	}
	if (min == INF)
		return -1;
	return min;
}