//----- [2110] 이분탐색/공유기 설치 -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_N 200000

int n, c, x[MAX_N];

int compare(const void* a, const void* b);
int binary_search(int s, int e);
int cnt(int dis);

int main() {
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);

	qsort(x, n, sizeof(int), compare);

	printf("%d", binary_search(1, x[n - 1]));

	return 0;
}

int compare(const void* a, const void* b) {
	return *(int*)a < *(int*)b ? -1 : *(int*)a > *(int*)b ? 1 : 0;
}

int cnt(int dis) {
	int count = 1, cur = x[0];

	for (int i = 1; i < n; i++) {
		if (x[i] - cur >= dis)
		{
			count++;
			cur = x[i];
		}
	}

	return count;
}

int binary_search(int s, int e) {
	if (s > e)
		return e;

	int mid = (s + e) / 2;
	int count = cnt(mid);

	if (count < c)
		return binary_search(s, mid - 1);
	else
		return binary_search(mid + 1, e);
}