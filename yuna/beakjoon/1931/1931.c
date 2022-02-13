//----- [1931] 회의실 배정 -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_N 100000

typedef struct {
	int s;
	int e;
} MR;

MR time[MAX_N + 1];

int compare(const void* a, const void* b);

int main() {
	int n, count = 0;
	int end = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &time[i].s, &time[i].e);
	qsort(time, n, sizeof(MR), compare);

	for (int i = 0; i < n; i++) {
		if (end <= time[i].s) {
			end = time[i].e;
			count++;
		}
	}

	printf("%d", count);

	return 0;
}

int compare(const void* a, const void* b) {
	return ((MR*)a)->e < ((MR*)b)->e ? -1 : ((MR*)a)->e >((MR*)b)->e ? 1 : ((MR*)a)->s < ((MR*)b)->s ? -1 : 1;
}