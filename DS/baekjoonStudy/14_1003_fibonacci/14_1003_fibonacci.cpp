#include <iostream>

using namespace std;

int d[41] = { 0 };
int d0[41] = { 0 };
int d1[41] = { 0 };

int fibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}

	if (d[n] != 0) {
		return d[n];
	}

	d[n] = fibonacci(n - 1) + fibonacci(n - 2);

	if (n != 0 && n != 1) {
		d0[n] = d0[n - 1] + d0[n - 2];
		d1[n] = d1[n - 1] + d1[n - 2];
	}

	return d[n];
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	int n;
	cin >> T;

	d0[0] = 1;
	d1[0] = 0;
	d0[1] = 0;
	d1[1] = 1;

	for (int i = 0; i < T; i++) {
		cin >> n;
		fibonacci(n);
		cout << d0[n] << ' ' << d1[n] << '\n';
	}

	return 0;
}