#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 987654321 // �ִ밪:10��*100+1
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
				ary[i][j].weight = 0;//i==f�϶� 0���� �ʱ�ȭ�� ����: INF�� ������ 1->3->1�� ���� �ִ� ��찡 ������� ���� ���ǿ� ����x
		}
	for (int k = 1; k <= edge_num; k++)
	{
		int start, end;
		scanf("%d %d", &start, &end);
		scanf("%d", &tmp);
		if (tmp < ary[start][end].weight)//1->3���� ���� �ִ� ���� ���������� �־��� ���� �� ���� ���� �־���
		{
			ary[start][end].weight = tmp;
			ary[start][end].via[0] = start;
			ary[start][end].via[1] = end;//via�迭�� ���� ���� � ��θ� �̿��� ������ ������ �ʱ�ȭ �ƴ��� ó��
			ary[start][end].cnt = 2;//������ vertex�� ����( ó������ �׻� 0 or 2)
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
	for (int i = 1; i <= ver_num; i++)//���İ��� ���
	{
		for (int j = 1; j <= ver_num; j++)//���
		{
			for (int k = 1; k <= ver_num; k++)//����
			{
				if ((j!=k) &&ary[j][i].weight + ary[i][k].weight < ary[j][k].weight)//��߰� ������ ���� �ʰ�,���İ� ����� ���ΰ� �� ª���� �ٲٱ�
				{
					ary[j][k].weight = ary[j][i].weight + ary[i][k].weight;
					ary[j][k].cnt = ary[j][i].cnt + ary[i][k].cnt - 1;//n���� vertex +m���� vertex=�ϳ��� vertex�� ��ġ�� ������ (n+m-1)vertex  ex)(1->2->4)+(4->3)=1->2->3
					for (int idx = 0; idx < ary[j][i].cnt; idx++)//(1->3->4)���� ����
					{
						ary[j][k].via[idx] = ary[j][i].via[idx];
					}
					for (int idx = ary[j][i].cnt,x=1; x <  ary[i][k].cnt;x++, idx++)//(4->3)���� 4�� ���� ->3�� ����
					{
						ary[j][k].via[idx] = ary[i][k].via[x];
					}
				}
			}
		}
	}
}