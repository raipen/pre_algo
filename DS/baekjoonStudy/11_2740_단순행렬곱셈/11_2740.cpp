#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, N2, M, M2;
	int** arr;
	int** arr2;
	cin >> N >> M;

	arr = new int* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[M];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> N2 >> M2;

	arr2 = new int* [N2];
	for (int i = 0; i < N2; i++) {
		arr2[i] = new int[M2];
	}

	for (int i = 0; i < N2; i++) {
		for (int j = 0; j < M2; j++) {
			cin >> arr2[i][j];
		}
	}

	//N*M2 За·Д
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M2; j++) {
			int mul = 0;
			for (int k = 0; k < N2; k++) {
				mul += arr[i][k] * arr2[k][j];
			}
			cout << mul << ' ';
		}
		cout <<'\n';
	}
}