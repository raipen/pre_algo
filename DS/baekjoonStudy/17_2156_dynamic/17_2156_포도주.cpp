//d[i]->i까지 포도주가 있을 때 마실 수 있는 최대 양
//6 10 13   9  8 1
//6 16 23  28 33
//1  2  3  4 5 6
//1. 선택을 안 한 경우.i - 2, i - 1->d[i - 1]
//2. 선택을 한 경우
//(1) i - 2, i(1번)->d[i - 2] + arr[i]
//(2) i - 1, i(연속2번)->d[i - 3] + arr[i - 1] + arr[i]

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n = 0;
	int buf1;

	cin >> n;
	vector <int> d(n+2, 0);
	vector <int> wine(n+2, 0);

	for (int i = 0; i < n; i++) {
		cin >> buf1;
		wine[i] = buf1;
	}

	d[0] = wine[0];
	d[1] = wine[0] + wine[1];
	d[2] = max({ d[1], d[0] + wine[2], wine[1] + wine[2] });
	for (int i = 3; i < n; i++) {
		d[i] = max({ d[i - 1], d[i - 2] + wine[i], d[i - 3] + wine[i - 1] + wine[i]});
	}

	cout << *max_element(d.begin(), d.end());

	return 0;
}