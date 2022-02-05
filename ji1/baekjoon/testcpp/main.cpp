#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long int
#define MAX_N 11
#define pp pair<int,int>

using namespace std;

int N;
ll dp[MAX_N];
vector<pair<int, pp>> graph[MAX_N];

ll GCD(ll a, ll b);
void dfs(int x, int);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	ll lcm = 1;

	for (int i = 0; i < N - 1; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		graph[a].push_back({ b, {c,d} }); // node a에서 b로 연결되는 비율이 c : d 이다.
		graph[b].push_back({ a, {d,c} }); // node b에서 a로 연결되는 비율이 d : c 이다.

		lcm *= (c * d / GCD(c, d)); // 모든 레시피 속 비율의 최소공배수를 구한다.  .
	}

	dp[0] = lcm; //임의로 0에 집어넣는다.
		dfs(0, -1); // 방금 최소공배수(LCM)를 dp[0]에 넣었으므로 0부터 시작하고 두번째 매개변수(-1)은 parent를 의미한다. 아직은 parent 가 없으므로 -1이다. 

	ll global = dp[0];

	for (int i = 1; i < N; i++) {
		if (dp[i] == 0) continue;
		global = GCD(global, dp[i]); // 전체 최대공약수 구하기 
	}


	for (int i = 0; i < N; i++)
		cout << dp[i] / global << " ";

	return 0;
}

/* 최대공약수 구하는 함수이다 */
ll GCD(ll a, ll b) {
	while (b != 0) {
		ll t = a % b;
		a = b;
		b = t;
	}

	return a;
}


void dfs(int x, int parent) {
	for (auto n : graph[x]) { // X의 Child를 탐색한다. 
		if (n.first == parent) { // n.first 가 parent와 같으면 함수를 진행하지 않는다. 왜냐하면 이미 탐색했기 때문이다. 
			continue;
		} // parent 와 지금 도는 이 child의 레시피 비율이 있을텐데, 그 비율에 맞춰서 dp[n.first]를 추가한다. 
		dp[n.first] = (dp[x] * (ll)n.second.second) / (ll)n.second.first;
		// 넣어주고나서 다시 그 자식 노드 중 하나로 들어간다.
		dfs(n.first, x); //현재 노드의 child를 탐색하러 들어간다.
	}
}