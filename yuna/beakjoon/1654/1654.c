//----- [1654] 이분탐색/랜선 자르기 -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_K 10000

int k, n;
long long l[MAX_K], l_sum = 0;

int cnt(long long mid);
long long binary_search(long long s, long long e);

int main() {
	scanf("%d %d", &k, &n);

	for (int i = 0; i < k; i++) {
		scanf("%lld", &l[i]);
		l_sum += l[i];
	}

	printf("%lld", binary_search(1, l_sum));

	return 0;
}

int cnt(long long mid) {
	int count = 0;

	for (int i = 0; i < k; i++)
		count += l[i] / mid;

	return count;
}

long long binary_search(long long s, long long e) {
	if (s > e)
		return e;

	long long mid = (s + e) / 2;
	int count = cnt(mid);

	if (count < n)
		return binary_search(s, mid - 1);
	else
		return binary_search(mid + 1, e);
}