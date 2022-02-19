#include <iostream>

using namespace std;

int d[41] = { 0 };

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	int n;
	cin >> T;

	d[0] = 0;
	d[1] = 1;

	for (int i = 2; i <= 40; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}

	for (int i = 0; i < T; i++) {
		cin >> n;

		if (n == 0) cout << 1 << ' ' << 0;
		else if(n == 1) cout << 0 << ' ' << 1;
		else cout << d[n - 1] << ' ' << d[n];

		cout << '\n';
	}

	return 0;
}