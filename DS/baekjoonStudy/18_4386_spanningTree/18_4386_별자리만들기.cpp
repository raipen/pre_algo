#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct star {
	double x;
	double y;
}star;
typedef struct g{
	double w;
	int ver1;
	int ver2;
}g;

bool cmp(g a, g b) {
	return a.w < b.w;
}
vector<g>v2;
vector<star>v1;

double sum = 0;
void kruskals_algo(int);

int find(int); // 부모 찾기
bool is_union1(int, int); // 같은 집합인가?
void merge1(int, int); // 합치기

int parent[101];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	double x, y;
	double buf1;

	cin >> n;

	cout << fixed;
	cout.precision(2);

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v1.push_back({ x, y });

		for (int j = 0; j < i; j++) {
			buf1 = sqrt(pow((v1[i].x - v1[j].x), 2) + pow((v1[i].y - v1[j].y), 2));
			v2.push_back({ buf1, i, j });
		}
	}

	if (n != 1) {
		sort(v2.begin(), v2.end(), cmp);
	}

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	kruskals_algo(n);

	cout << sum;

	return 0;
}

void kruskals_algo(int n) {
	for (int i = 0; i < v2.size(); i++) {
		if (!is_union1(v2[i].ver1, v2[i].ver2)) {
			sum += v2[i].w;
			merge1(v2[i].ver1, v2[i].ver2);
		}
	}
}

int find(int x) {
	if (x == parent[x]) return x;

	parent[x] = find(parent[x]);
	return parent[x];

//	return find(parent[x]);
}
bool is_union1(int x, int y) {
	int a = find(x);
	int b = find(y);

	if (a == b) return true;
	else return false;

	//x = find(x);
	//y = find(y);

	//if (x == y) return true;
	//else return false;
}
void merge1(int x, int y) {
	int a = find(x);
	int b = find(y);

	if (a < b) parent[b] = a;
	else parent[a] = b;

	//x = find(x);
	//y = find(y);

	//if (x < y) parent[y] = x;
	//else parent[x] = y;
}
