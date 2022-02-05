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
		graph[a].push_back({ b, {c,d} }); // node a���� b�� ����Ǵ� ������ c : d �̴�.
		graph[b].push_back({ a, {d,c} }); // node b���� a�� ����Ǵ� ������ d : c �̴�.

		lcm *= (c * d / GCD(c, d)); // ��� ������ �� ������ �ּҰ������ ���Ѵ�.  .
	}

	dp[0] = lcm; //���Ƿ� 0�� ����ִ´�.
		dfs(0, -1); // ��� �ּҰ����(LCM)�� dp[0]�� �־����Ƿ� 0���� �����ϰ� �ι�° �Ű�����(-1)�� parent�� �ǹ��Ѵ�. ������ parent �� �����Ƿ� -1�̴�. 

	ll global = dp[0];

	for (int i = 1; i < N; i++) {
		if (dp[i] == 0) continue;
		global = GCD(global, dp[i]); // ��ü �ִ����� ���ϱ� 
	}


	for (int i = 0; i < N; i++)
		cout << dp[i] / global << " ";

	return 0;
}

/* �ִ����� ���ϴ� �Լ��̴� */
ll GCD(ll a, ll b) {
	while (b != 0) {
		ll t = a % b;
		a = b;
		b = t;
	}

	return a;
}


void dfs(int x, int parent) {
	for (auto n : graph[x]) { // X�� Child�� Ž���Ѵ�. 
		if (n.first == parent) { // n.first �� parent�� ������ �Լ��� �������� �ʴ´�. �ֳ��ϸ� �̹� Ž���߱� �����̴�. 
			continue;
		} // parent �� ���� ���� �� child�� ������ ������ �����ٵ�, �� ������ ���缭 dp[n.first]�� �߰��Ѵ�. 
		dp[n.first] = (dp[x] * (ll)n.second.second) / (ll)n.second.first;
		// �־��ְ��� �ٽ� �� �ڽ� ��� �� �ϳ��� ����.
		dfs(n.first, x); //���� ����� child�� Ž���Ϸ� ����.
	}
}