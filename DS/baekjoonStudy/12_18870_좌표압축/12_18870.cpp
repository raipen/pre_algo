#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	vector<int> v2(v);
	sort(v2.begin(), v2.end());
	auto a = unique(v2.begin(), v2.end());
	v2.erase(a, v2.end());

	for (int i = 0; i < N; i++) {
		auto index = lower_bound(v2.begin(), v2.end(), v[i]);
		cout << index - v2.begin() << ' ';
	}
	return 0;
}