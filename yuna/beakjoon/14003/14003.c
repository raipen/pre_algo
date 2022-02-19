//----- [14003] 가장 긴 증가하는 부분 수열 5 -----//
// - LIS (+이진탐색)

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_N 1000002
#define MIN -1000000001

int a[MAX_N];
int lis[MAX_N];
int d[MAX_N]; // d[i] = a[i]의 lis 인덱스 저장

void print_lis(int i, int max);
int find_max(int n);

int main() {
	int n, max;

	scanf("%d", &n);

	max = find_max(n);

	printf("%d\n", max);
	print_lis(n, max);

	return 0;
}

int find_max(int n) {
	int s, e, m, max;

	lis[0] = MIN;
	scanf("%d", &a[1]);
	max = d[1] = 1;
	lis[1] = a[1];

	for (int i = 2; i <= n; i++) {
		scanf("%d", &a[i]);

		s = 0, e = max;
		while (s <= e) {
			m = (s + e) / 2;

			if (a[i] == lis[m]) // 같은 수는 넣을 필요X
				break;
			else if (a[i] > lis[m]) {
				if (m == max) { // lis의 모든 원소보다 큰 경우
					lis[++max] = a[i];
					d[i] = max;
					break;
				}
				else if (a[i] < lis[m + 1]) { // lis[m] < a[i] < lis[m+1]
					lis[m + 1] = a[i];
					d[i] = m + 1;
					break;
				}
				else // a[i] > lis[m]
					s = m + 1;
			}
			else { // a[i] < lis[m]
				e = m - 1;
			}
		}
	}

	return max;
}

void print_lis(int n, int max) {
	if (max == 0)
		return;

	for (int i = n; i > 0; i--)
		if (d[i] == max) {
			print_lis(i - 1, max - 1);
			printf("%d ", a[i]);
			return;
		}
}