#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[500000];
vector<pair<int, int>> v1;

int find_parent(int);
bool is_union_user(int, int);
void merge_parent(int, int);
void init_parent(int);

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	int m;
	int x, y;
	int ans;
	int i, j;

	cin >> n >> m;
	init_parent(n);
	for (i = 0; i < m; i++) {
		cin >> x >> y;
		if (!is_union_user(x, y)) {
			merge_parent(x, y);
		}
		else {
			ans = i+1;
			break;
		}
	}

	for (j = i+1; j < m; j++) cin >> x >> y;

	if (i == m) cout << 0;
	else cout << ans;

	return 0;
}

void init_parent(int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
}

int find_parent(int x) {
	if (x == parent[x]) return x;
	parent[x] = find_parent(parent[x]);

	return parent[x];
}

bool is_union_user(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);

	if (x == y) return true;
	else return false;
}
void merge_parent(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);

	if (y > x) parent[y] = x;
	else parent[x] = y;
}