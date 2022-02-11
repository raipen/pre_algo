#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>>v1;

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int max_plan(int);

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	int x, y;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v1.push_back({ x, y });
	}

	sort(v1.begin(), v1.end(), cmp);

	int count = max_plan(n);
	cout << count;
	return 0;
}

int max_plan(int n) {
	int count = 1;
	int j = 0;
	for (int i = 1; i < n; i++) {
		if(v1[i].first >= v1[j].second){
			count++;
			j = i;
		}
	}
	return count;
}