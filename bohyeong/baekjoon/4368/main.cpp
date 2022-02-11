#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

int parent[100];

int get_parent(int parent[], int x) { //아 씨발 진짜 어이없어 
	if (parent[x] == x) {             //백준 틀린이유: return; 이지랄 해서 틀림 씨발것 
		return x; //음 반환값 똑바로 보자 그리고 , c++넘어가자 
	}
	return parent[x] = get_parent(parent, parent[x]);
}

int find_parent(int parent[], int a, int b) { //같은 부모를 가지는 지 확인하는 함수
	a = get_parent(parent, a);
	b = get_parent(parent, b);
	if (a == b) return 1;
	else return 0;
}

void unionparent(int parent[], int a, int b) {
	a = get_parent(parent, a);
	b = get_parent(parent, b);
	if (a < b) parent[b] = a; //두 부모노드 중 작은 친구를 부모로 설정!
	else parent[a] = b;
}

bool compare(const tuple<int,int,double>& a, const tuple<int, int, double>& b) {
	return (get<2>(a)) < (get<2>(b));
}

int main() {
	vector<tuple<int, int, double>> info;
	vector<pair<double, double>> p;
	int count = 0;
	int num;
	double sum = 0;
	cin >> num;

	double x, y;
	for (int i = 0; i < num; i++) {
		cin >> x >> y;
		p.push_back({ x,y });
		parent[i] = i;
	}
	
	for (int i = 0; i < num; i++) { // 간선 거리 구하고 array에 정보 넣기
		for (int j = i + 1; j < num; j++) {
			double a = fabs(p[j].first - p[i].first);
			double b = fabs(p[j].second - p[i].second);
			double c = sqrt((a * a) + (b * b));
			info.push_back(make_tuple(i, j, c));
		}
	}

		sort(info.begin(), info.end(), compare);

		for (int i = 0; i < info.size(); i++) {
			if (!find_parent(parent, get<0>(info[i]), get<1>(info[i]))) {
				unionparent(parent, get<0>(info[i]), get<1>(info[i]));
				count++;
				sum += get<2>(info[i]);

				if (count == num - 1) {
					break;
				}
			}
		}
		cout << sum << endl;

		return 0;
	
}