//���� 2098�� (���ǿ� ��ȸ)(ȥ�� ��ǰ) - ��Ʈ����ŷ�� ������ ��Ȯ�ϰ� �˾ƾ� �ϰ� �װ��� dp �� �������Ѽ� Ǫ�� ��������. ���������� �� ���信 ���� ���������
//                                     ���� �̼� ��Ʈ����ŷ�� ���� visited�� ����Ѵٴ� ���� �ű��ߴ� ����

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
#define DEBUG 0 //���� �� 0
#define endl    '\n'
#define INF 987654321
#define SHARING 100001

using namespace std;
vector<vector<int>> arr(16, vector<int>(16, 0));
int n; int num; int ans_bit; 
vector<vector<int>> dp(16, vector<int>(1<<16, 0));
int start = 0;

int dfs(int curr_node, int curr_bit) { //���� Ž���ϴ� ���� �װ� �ݿ��� ��Ʈ�� �Ű������� �޴´�
	if (curr_bit == ans_bit) {//���� ���� ��Ʈ�� ������ Ž���߰�
		if (arr[curr_node][start] == 0) { 
			return INF;
		}
		else return arr[curr_node][start]; // ���������� ó������ ���ư� ���ִٸ� �� ���� �ݿ��ϰ� �ƴϸ� INF �ݿ�
	}
	
	if (dp[curr_node][curr_bit] != 0) {//������� ��Ʈ�� ���� dp�� �����Ѵٸ�(�̹� �ּ�ȭ �Ǿ��ٴ� ��)
		return dp[curr_node][curr_bit]; //�׳� return ���ֱ�
	}

	int distance = INF;
	for (int i = 0; i < n; i++) {
		if (arr[curr_node][i] != 0 && !(curr_bit & (1 << i))) {//curr_node -> i�� ���� ���� �ְ� �湮���� �ʾҴٸ�
			distance = min(distance, arr[curr_node][i] + dfs(i, curr_bit | 1 << i)); // ���� �Ÿ��� , curr->i + i���� �ּ�ȭ���� dfs�� ���� �Ͱ� ��
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