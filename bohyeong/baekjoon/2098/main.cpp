//백준 2098번 (외판원 순회)(혼자 못품) - 비트마스킹의 개념을 정확하게 알아야 하고 그것을 dp 와 연관시켜서 푸는 문제였다. 전반적으로 각 개념에 대한 구현방법이
//                                     많이 미숙 비트마스킹을 통해 visited를 대신한다는 것이 신기했던 문제

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <list>
#include <set>
#include <stack>
#include <deque>
#include <tuple>
#include <sstream>
#include <cmath>
#define DEBUG 0 //제출 시 0
#define endl    '\n'
#define INF 987654321
#define SHARING 100001

using namespace std;
vector<vector<int>> arr(16, vector<int>(16, 0));
int n; int num; int ans_bit; 
vector<vector<int>> dp(16, vector<int>(1<<16, 0));
int start = 0;

int dfs(int curr_node, int curr_bit) { //현재 탐색하는 노드와 그걸 반영한 비트를 매개변수로 받는다
	if (curr_bit == ans_bit) {//만약 현재 비트가 끝까지 탐색했고
		if (arr[curr_node][start] == 0) { 
			return INF;
		}
		else return arr[curr_node][start]; // 끝지점에서 처음으로 돌아갈 수있다면 그 값을 반영하고 아니면 INF 반영
	}
	
	if (dp[curr_node][curr_bit] != 0) {//현재노드와 비트에 대한 dp가 존재한다면(이미 최소화 되었다는 뜻)
		return dp[curr_node][curr_bit]; //그냥 return 해주기
	}

	int distance = INF;
	for (int i = 0; i < n; i++) {
		if (arr[curr_node][i] != 0 && !(curr_bit & (1 << i))) {//curr_node -> i로 가는 길이 있고 방문하지 않았다면
			distance = min(distance, arr[curr_node][i] + dfs(i, curr_bit | 1 << i)); // 원래 거리와 , curr->i + i부터 최소화돌린 dfs를 합한 것과 비교
		}
	}
	dp[curr_node][curr_bit] = distance; 
	return distance;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	ans_bit = (1 << n) - 1;
	cout << dfs(0, 1) << endl;
	return 0;
}