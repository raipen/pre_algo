#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int result(int* arr, long long size) {
	int cnt = 0;
	for (long long i = 0;i < size;i++) {
		if (arr[i] == 0)
			cnt++;
	}
	return cnt;
}

int main() {
	long long min, max;
	scanf("%lld %lld", &min, &max);
	long long size = max - min + 1;
	int* arr = (int*)calloc(size, sizeof(int));
	for (long long i = 2;i < 1000001;i++) {
		long long j = i * i;
		long long cur = j - min % j;
		if (cur == j) cur = 0;
		while (cur < size) {
			arr[cur] = 1;
			cur += j;
		}
	}
	printf("%d",result(arr,size));
	return 0;
}