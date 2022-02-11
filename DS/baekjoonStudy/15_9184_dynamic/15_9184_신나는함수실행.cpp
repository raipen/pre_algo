#include <iostream>

using namespace std;

int main(void) {
	int data[21][21][21] = { 0 };
	int a, b, c;

	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			for (int k = 0; k <= 20; k++) {
				data[i][j][k] = 1;
			}
		}

	}
	for (int a = 1; a <= 20; a++) {
		for (int b = 1; b <= 20; b++) {
			for (int c = 1; c <= 20; c++) {
				if (a < b && b < c) data[a][b][c] = data[a][b][c - 1] + data[a][b - 1][c - 1] - data[a][b - 1][c];
				else data[a][b][c] = data[a - 1][b][c] + data[a - 1][b - 1][c] + data[a - 1][b][c - 1] - data[a - 1][b - 1][c - 1];
			}
		}
	}

	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;

		if (a <= 0 || b <= 0 || c <= 0) {
			cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << '\n';
			continue;
		}
		if (a > 20 || b > 20 || c > 20) {
			cout << "w(" << a << ", " << b << ", " << c << ") = " << data[20][20][20] << '\n';
			continue;
		}

		cout << "w(" << a << ", " << b << ", " << c << ") = " << data[a][b][c] << '\n';
	}


	return 0;
}