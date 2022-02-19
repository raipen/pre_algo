#include <iostream>
#include <vector>
#include <algorithm> //sort,max,min �˰�������
using namespace std;
//�� ������ ���� �����븦 �ϴ� ������������ �����Ѵ�. �׸��� �ٽ� ���� �ȴٸ� LIS ������ ���� �˾����� �� �ִ�. �� ���� ������ ��ȣ�� ������ �� ������ ������ ��ȣ��
//���� �����ؾ� �ϱ� ������ LIS ��� ���� ���� 
int main() {
	int dp[101]; 
	vector<pair<int, int>> node; // �Ѵ� int ���̴ϱ�
	int n;
	int a, b;
	cin >> n; // ������ ������ n�� scanf
	for (int i = 0; i < n; i++) {
		cin >> a >> b; // a�� b�� ������ ��ȣ�� cin ���� �ް�
		node.push_back({ a, b }); // node ��� ���Ϳ��ٰ� push ���ֱ�
	}

	sort(node.begin(), node.end());// first�� �������� �������� ����

	for (int i = 0; i < n; i++) {//i �� ����
		dp[i] = 1;//dp �ʱ�ȭ
		for (int j = 0; j < i; j++) {
			if (node[i].second > node[j].second) { // �� ū ���� ã���� 
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

	cout << n - maxnode << endl;// endl ���� ���� ���� ���� ������ '\n' ���� �ϴ°� ����	

	return 0;
}