//----- [2740] ��������/��� ���� -----//
// �������� X, 3�� for������ ǰ

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX_N 101

int main() {
	int a[MAX_N][MAX_N] = { 0 }, b[MAX_N][MAX_N] = { 0 }, c[MAX_N][MAX_N] = { 0 };
	int n, m, k;

	//�Է�
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n;i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	scanf("%d %d", &m, &k);
	for (int i = 0; i < m;i++)
		for (int j = 0; j < k; j++)
			scanf("%d", &b[i][j]);

	//���
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			for (int l = 0; l <= m; l++)
				c[i][j] += a[i][l] * b[l][j];

	//���  *�������
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k;j++)
			if (j == k - 1)
				printf("%d\n", c[i][j]);
			else
				printf("%d ", c[i][j]);

	return 0;
}