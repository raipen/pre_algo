//----- [1033] Ä¬Å×ÀÏ -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_N 10

int n;
int ch[MAX_N][MAX_N] = { 0 }, m[MAX_N], r_ch[MAX_N] = { 0 };

int find_gcd(int a, int b);
void set_rate(int x, int r);
void init_r_ch();

int main() {
	int a, b, p, q;
	int gcd, lcm;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		m[i] = 1;

	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d %d", &a, &b, &p, &q);

		gcd = find_gcd(m[b] * p, m[a] * q);
		p = m[b] * p / gcd;
		q = m[a] * q / gcd;

		init_r_ch();
		set_rate(a, p);
		set_rate(b, q);

		ch[a][b] = 1;
		ch[b][a] = 1;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", m[i]);
}

void set_rate(int x, int r) {
	r_ch[x] = 1;

	m[x] *= r;
	for (int i = 0; i < n; i++)
		if ((ch[x][i] == 1) && (r_ch[i] == 0)) {
			set_rate(i, r);
		}
}

int find_gcd(int a, int b) {
	if (b == 0)
		return a;
	return find_gcd(b, a % b);
}

void init_r_ch() {
	for (int i = 0; i < n; i++)
		r_ch[i] = 0;
}