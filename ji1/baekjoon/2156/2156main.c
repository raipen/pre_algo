#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int max3(int a, int b, int c) {
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int result(int* arr, int i, int* r) {
	return i == 0 ? arr[0] : i == 1 ? arr[0] + arr[1] : i == 2 ? max3(r[1], r[0] + arr[2], arr[1] + arr[2]) : max3(r[i - 1], r[i - 2] + arr[i], r[i - 3] + arr[i - 1] + arr[i]);
}

int main() {
	int s;
	scanf("%d", &s);
	int* a = (int*)malloc(s * sizeof(int));
	int* r = (int*)malloc(s * sizeof(int));
	for (int i = 0; i < s && scanf("%d", &a[i]); i++)
		r[i] = result(a, i, r);

	printf("%d", r[s - 1]);
	return 0;
}