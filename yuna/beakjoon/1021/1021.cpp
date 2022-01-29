//----- [1021] 큐,덱/회전하는 큐 -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_N 50

int main() {
	int n, m, oper = 0;
	int cur = 0, right_oper, left_oper;
	int a, ch[MAX_N] = { 0 };

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		a--;

		right_oper = left_oper = 0;
		for (int j = cur; j != a; j = (j + 1 + n) % n) {
			if (!ch[j])
				right_oper++;
		}
		for (int j = cur; j != a; j = (j - 1 + n) % n) {
			if (!ch[j])
				left_oper++;
		}

		if (right_oper < left_oper)
			oper += right_oper;
		else
			oper += left_oper;

		ch[a] = 1;

		if (i == n - 1)
			break;
		cur = a;
		do {
			cur = (cur + 1 + n) % n;
		} while (ch[cur]);
	}

	printf("%d", oper);

	return 0;
}