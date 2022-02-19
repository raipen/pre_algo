//dynamic programming����, �������� LIS������ �迭�� �κ� ���� �� 
//������������ ���� �� �κ� ������ ���ϴ� �����̴�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v1; // ������ ���� ����


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n = 0;
	int buf1, buf2;
	cin >> n; // ������ ���� �Է�
	vector<int> v2(n, 1); // ũ�Ⱑ n�� v2�� ���ҵ��� 1�� �ʱ�ȭ


	for (int i = 0; i < n; i++) { // ������ ���� ��ġ ��ȣ �� ������ �Է� �ޱ�
		cin >> buf1 >> buf2;
		v1.push_back({ buf1, buf2 });
	} 

	sort(v1.begin(), v1.end()); // A������ �������� �������� ����

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v1[i].second > v1[j].second) {
				v2[i] = max(v2[i], v2[j] + 1);
			}
		}
	}

	cout << n - *max_element(v2.begin(), v2.end());

	return 0;
}