//���� 1931�� - ȸ�ǽ� ����
//ó�� ��,ó��,���� �ð� �̷��� 3���� �ޱ� ���� tuple �������ߴµ� ������ �ð��� ������������ �ϸ��� ���۽ð��� ���ð� ���̽ð��� ������ص�����
//�ֳ��ϸ� ���� ���۽ð��� ���� 5 6 , 5 7�� �ִ��� ������ ���� �տ����� ������ �� ���� �����ٴ� ���� �� �� �ֱ� ����!
//���� ó�� Ʋ������: int i = 1 �̶�� ���ϰ� i = 0 �̶�� �ؼ�..
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
	int n; int a, b;
	int curr = 0; int count = 1;
	vector<pair<int, int>> v1; //��, ����
	cin >> n;
	while (n--) {
		cin >> a >> b;
		v1.push_back({b,a});
	}

	sort(v1.begin(), v1.end());
	
	curr = v1[0].first; // ó�� �� 

	for (int i = 1; i < v1.size(); i++) { 
		if (curr <= v1[i].second) {
			curr = v1[i].first;
			count++;
		}
	}
	cout << count << '\n';

	return 0;
}