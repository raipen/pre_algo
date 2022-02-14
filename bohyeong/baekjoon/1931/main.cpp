//백준 1931번 - 회의실 배정
//처음 끝,처음,사이 시간 이렇게 3개를 받기 위해 tuple 쓰려고했는데 끝나는 시간을 오름차순으로 하면은 시작시간과 끝시간 사이시간을 고려안해도되지
//왜냐하면 같은 시작시간을 가진 5 6 , 5 7이 있더라도 정렬을 통해 앞에것이 무조건 더 빨리 끝난다는 것을 알 수 있기 때문!
//백준 처음 틀린이유: int i = 1 이라고 안하고 i = 0 이라고 해서..
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
	int n; int a, b;
	int curr = 0; int count = 1;
	vector<pair<int, int>> v1; //끝, 시작
	cin >> n;
	while (n--) {
		cin >> a >> b;
		v1.push_back({b,a});
	}

	sort(v1.begin(), v1.end());
	
	curr = v1[0].first; // 처음 끝 

	for (int i = 1; i < v1.size(); i++) { 
		if (curr <= v1[i].second) {
			curr = v1[i].first;
			count++;
		}
	}
	cout << count << '\n';

	return 0;
}