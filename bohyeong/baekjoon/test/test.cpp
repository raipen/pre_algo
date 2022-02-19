#include <iostream>
#include <vector>
using namespace std;

vector<char>v; //������ ���ؾ� �� �־��� ����
vector<char> result; //�ϼ��� ������ ����ǰ� ���ŵǴ� ����
int m; //������ ���� ������ ��
bool visit[4]; // ���� 4���� �湮���� üũ 
void dfs() {
	if (result.size() == m) {
		for (char i : result) {
			cout << i << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			result.push_back(v[i]);
			dfs();
			result.pop_back();
			visit[i] = false;
		}
	}
}
int main() {
	m = 4;
	v.push_back('a');
	v.push_back('b');
	v.push_back('c');
	v.push_back('d');
	dfs();
	return 0;
}