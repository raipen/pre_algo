//----- [2565] ภüฑ๊มู -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_L 101

typedef struct {
	int a;
	int b;
} LINE;

int compare_a(const void* a, const void* b); // qsort
int find_max_line(int n, LINE l[]);

int main() {
	int n, max;
	LINE l[MAX_L];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &l[i].a, &l[i].b);
	qsort(l, n, sizeof(LINE), compare_a);

	max = find_max_line(n, l);
	printf("%d", n - max);

	return 0;
}

int find_max_line(int n, LINE l[]) {
	int max[MAX_L], count = 0, j, maxcount = 1;

	max[count++] = l[0].b;
	for (int i = 1; i < n; i++) {
		for (j = 0; j < count; j++)
			if (max[j] > l[i].b) {
				max[j] = l[i].b;
				break;
			}

		if (j == count)
			max[count++] = l[i].b;

		if (maxcount < count) {
			maxcount = count;
		}
	}

	return maxcount;
}

int compare_a(const void* a, const void* b) {
	return ((LINE*)a)->a < ((LINE*)b)->a ? -1 : ((LINE*)a)->a >((LINE*)b)->a ? 1 : 0;
}