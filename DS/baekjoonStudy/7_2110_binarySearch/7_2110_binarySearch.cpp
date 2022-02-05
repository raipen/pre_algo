/*4�� ���� ���� �غôµ�, Ǯ�� ����.
binary search�����ε�, ������ ��ƴ�� �ٿ������� �ϴ�����
��ƴ�� ���� ������ ���� ������ �ɾ�� �ϴ��� ���� ���� �� ��.
������ ó���� ���� ���̸� ���� ������, ��ƴ�� �ٿ����� �������� ������ ã�ƾ� ��.
binary search������ ������ ��ƴ�� �ٿ� ������ ��, �޶����� ���� �� �����غ��ƾ� ��.*/

#include <iostream>
#include <algorithm>
using namespace std;

int num_count(int* x, int avg, int);

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N = 0;
	int C = 0;
	int avg = 0;
	int* x;
	
	cin >> N >> C;

	x = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	sort(x, x + N);

	int start = 0;
	int end = x[N - 1] - x[0];
	int res = 0;
	int count = 0;
	int len = N;


	while (start <= end) {
		avg = (start + end) / 2;
		count = num_count(x, avg, len);

		if (count >= C) {
			if (avg >= res) res = avg;
			start = avg + 1;
		}
		else {
			end = avg- 1;
		}
	}

	cout << res << '\n';


	return 0;
}

int num_count(int* x, int avg, int len) {
	int base = x[0];
	int count = 1;

	for (int i = 1; i < len; i++) {
		if (x[i] - base >= avg) {
			count++;
			base = x[i];
		}
	}

	return count;
}
