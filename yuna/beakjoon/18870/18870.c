//----- [18870] ����/��ǥ ���� -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_N 1000000

typedef struct {
	int index;
	int data;
	int com;
} X;
X x[MAX_N];

int compare_data(const void* a, const void* b);
int compare_index(const void* a, const void* b);

int main() {
	int n;

	//�Է�
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		x[i].index = i;
		scanf("%d", &x[i].data);
	}

	//����
	qsort(x, n, sizeof(X), compare_data);

	//����
	x[0].com = 0;
	for (int i = 1; i < n; i++)
		if (x[i].data == x[i - 1].data)
			x[i].com = x[i - 1].com;
		else
			x[i].com = x[i - 1].com + 1;

	//���� ����
	qsort(x, n, sizeof(X), compare_index);

	//���
	for (int i = 0; i < n; i++)
		printf("%d ", x[i].com);

	return 0;
}

int compare_data(const void* a, const void* b) {
	return ((X*)a)->data < ((X*)b)->data ? -1 : ((X*)a)->data >((X*)b)->data ? 1 : 0;
}
int compare_index(const void* a, const void* b) {
	return ((X*)a)->index < ((X*)b)->index ? -1 : ((X*)a)->index >((X*)b)->index ? 1 : 0;
}
