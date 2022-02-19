#include <iostream>
#include <algorithm> 
#include <vector>
#include <tuple>
#include <cmath> //sqrt,fabs 때매 썻다

using namespace std;

int parent[100]; 

int get_parent(int parent[], int x) { //아 진짜 어이없어 
	if (parent[x] == x) {             //백준 틀린이유: return; 이렇게 해서 넘어가자 
		return x; //음 반환값 똑바로 보자 그리고 , c++넘어가자 -> 그래서 넘어가는 중이다..
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

//매개 변수 형이 특이한데 저렇게 해야하는 듯
bool compare(const tuple<int,int,double>& a, const tuple<int, int, double>& b) {//tuple의 세번째 원소를 통해 정렬하고 싶기 때문에 compare 함수 설정
	return (get<2>(a)) < (get<2>(b)); //귀찮으면 그냥 double, int, int로 tuple 만들고 compare 안쓰면 된다 sort는 자동으로 first기준으로 정렬하기때문
}

int main() {
	vector<tuple<int, int, double>> info; //출발노드,도착노드,간선거리를 담는 vector(변수가 3개이상이니까 tuple 사용)
	vector<pair<double, double>> p; //x,y 좌표를 담을 벡터 
	int count = 0;
	int num;
	double sum = 0;
	cin >> num;

	double x, y;
	for (int i = 0; i < num; i++) {
		cin >> x >> y;
		p.push_back({ x,y }); //x,y 좌표 p에 넣음 ({x,y}) -> 이렇게 적어야함
		parent[i] = i;
	}
	
	for (int i = 0; i < num; i++) { // 간선 거리 구하고 array에 정보 넣기
		for (int j = i + 1; j < num; j++) {
			double a = fabs(p[j].first - p[i].first); //fabs,sqrt => cmath 헤더파일
			double b = fabs(p[j].second - p[i].second);
			double c = sqrt((a * a) + (b * b));
			info.push_back(make_tuple(i, j, c)); // tuple은 push_back 할 때 make_tuple 이렇게 넘겨줘야함
		}
	}

		sort(info.begin(), info.end(), compare); // first 를 기준으로 하지않기 때문에 compare 추가

		for (int i = 0; i < info.size(); i++) { //info.size() -> info의 요소 개수
			if (!find_parent(parent, get<0>(info[i]), get<1>(info[i]))) {//get<first or second or third ..>(가져올 벡터info)
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