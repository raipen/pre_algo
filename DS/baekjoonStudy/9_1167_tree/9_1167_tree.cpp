/*�����ϰ� 3�ϵ��� ȥ�� �Ϸ����� �����ߴµ�, �� Ǯ���� �ӻ�����.
V�� �ִ� 10���̶� ��� ��带 ������ N^2���� �ð��ʰ� ����.
!!� ��忡�� �ִ� �Ÿ��� ��带 ã�� �� ��忡�� �ִ�Ÿ��� ��带 ã���� �ȴ�!!
������ ����� �ʾҴµ� ������ ���ذ� �� �Ȱ�.
.*/

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_NUM 100001
using namespace std;

int visited[MAX_NUM]; 
vector<pair<int, int>> arr[MAX_NUM]; // �׷���

void dfs(int node, int r);
void visited_init(int);  // �湮 �ʱ�ȭ

int res = 0; // ����
int longNode = 0; // ���� �ָ��ִ� ���

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int V;
	int a, b, dist;
	
	cin >> V;

	for (int i = 1; i <= V; i++) {//�Է� �ޱ�
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1)break;
			cin >> dist;
			arr[a].push_back({b, dist});
		}
	}

	visited_init(V);
	dfs(1, 0);
	res = 0;
	visited_init(V);
	dfs(longNode, 0);
	
	cout << res;

	return 0;
}

void dfs(int node, int r) {
	if (visited[node] == true) return; // ��������
	int nextV;
	int nextR;

	if (res < r) { // ���� �� ��� ������Ʈ
		res = r;
		longNode = node;
	}
	visited[node] = true; // node �湮ǥ��

	for (int i = 0; i < arr[node].size(); i++) // dfs
	{
		nextV = arr[node][i].first;
		nextR = arr[node][i].second + r;
		dfs(nextV, nextR);
	}
}

void visited_init(int V) {
	for (int i = 1; i <= V; i++) {
		visited[i] = false;
	}
}
