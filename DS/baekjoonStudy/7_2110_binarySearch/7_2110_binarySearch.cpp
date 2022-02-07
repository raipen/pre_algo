/*4일 동안 생각 해봤는데, 풀지 못함.
binary search문제인데, 무엇을 반틈씩 줄여나가야 하는지와
반틈을 줄인 다음에 무슨 조건을 걸어야 하는지 감을 잡지 못 함.
공유기 처음과 끝의 길이를 구한 다음에, 반틈씩 줄여가며 공유기의 갯수를 찾아야 함.
binary search문제는 무엇을 반틈씩 줄여 나갔을 때, 달라지는 값을 잘 생각해보아야 함.*/

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
