#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long c(int k, long long* a, long long  l) {
	int s = 0;
	for (int i = 0;i < k;i++)
		s += a[i] / l;
	return s;
}

long long r(int k, long long  n, long long* a, long long s) {
	long long  cur1 = 1,cur2 = s / n;
	while (1) {
		long long m = (cur1 + cur2) / 2;
		if (c(k, a, m) >= n)
			cur1 = m+1;
		else
			cur2 = m-1;
		if (cur1>cur2)
			break;
	}
	return cur2;
}

int main() {
	int k;
	long long n, a[10000],s = 0;
	scanf("%d %lld", &k, &n);

	for (int i = 0;i < k;i++) {
		scanf("%lld", &a[i]);
		s+= a[i];
	}
	printf("%lld", r(k,n,a,s));
	return 0;
}