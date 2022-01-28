#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int c(int N, int* X, int l) {
	int s=1;
	int pre = X[0];
	for (int cur = 1;cur<N;cur++) {
		if (X[cur]-pre>=l) {
			s++;
			pre = X[cur];
		}
	}
	return s;
}

int r(int N, int C, int*  X) {
	int l=1, r=X[N-1]- X[0];
	while (1) {
		int m = (l+r) / 2;
		if (c(N,X, m) >= C)
			l = m + 1;
		else
			r = m - 1;
		if (l > r)
			break;
	}
	return r;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int arr[], int here, int size) {
	int left = here * 2 + 1;
	int right = here * 2 + 2;
	int max = here;
	if (left < size && arr[left]>arr[max])
		max = left;
	if (right < size && arr[right]>arr[max])
		max = right;

	if (max != here) {
		swap(&arr[here], &arr[max]);
		heapify(arr, max, size);
	}
}

void buildHeap(int arr[], int size) {
	int i, j;
	for (i = size / 2 - 1; i >= 0; i--) {
		heapify(arr, i, size);
	}
}

void heapSort(int arr[], int size) {
	int treeSize;
	buildHeap(arr, size);
	for (treeSize = size - 1; treeSize >= 0; treeSize--) {
		swap(&arr[0], &arr[treeSize]);
		heapify(arr, 0, treeSize);
	}
}
//»¸º“∆Æ √‚√≥: https://reakwon.tistory.com/43

int main() {
	int N, C, min = 0,max = 0, X[200000],t;
	scanf("%d %d", &N, &C);
	for (int i = 0;i < N;i++) {
		scanf("%d", &X[i]);
	}
	heapSort(X, N);
	printf("%d", r(N,C,X));
	return 0;
}