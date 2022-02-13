#include <iostream>
#include <vector>
#include <algorithm> //sort,max,min 알고리즘있음
using namespace std;
//이 문제는 왼쪽 전봇대를 일단 오름차순으로 정렬한다. 그리고 다시 보게 된다면 LIS 문제인 것을 알아차릴 수 있다. 즉 왼쪽 전봇대 번호가 증가할 때 오른쪽 전봇대 번호도
//같이 증가해야 하기 때문에 LIS 라고 생각 가능 
int main() {
	int dp[101]; 
	vector<pair<int, int>> node; // 둘다 int 형이니까
	int n;
	int a, b;
	cin >> n; // 전깃줄 개수를 n에 scanf
	for (int i = 0; i < n; i++) {
		cin >> a >> b; // a와 b의 전봇대 번호를 cin 으로 받고
		node.push_back({ a, b }); // node 라는 벡터에다가 push 해주기
	}

	sort(node.begin(), node.end());// first를 기준으로 오름차순 정렬

	for (int i = 0; i < n; i++) {//i 가 기준
		dp[i] = 1;//dp 초기화
		for (int j = 0; j < i; j++) {
			if (node[i].second > node[j].second) { // 더 큰 값을 찾으면 
				dp[i] = max(dp[i], dp[j] + 1); 
			}
		}
	}


	/*for (int i = 0; i < n; i++) {
		cout << dp[i] << endl;
	}*/

	int maxnode = 0;
	for (int i = 0; i < n; i++) {
		maxnode = max(maxnode, dp[i]);
	}

	cout << n - maxnode << endl;// endl 은근 버퍼 많이 쓰기 때문에 '\n' 으로 하는게 좋음	

	return 0;
}