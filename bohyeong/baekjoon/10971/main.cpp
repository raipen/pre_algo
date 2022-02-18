//���� 10971(���ǿ� ��ȸ2)- N�� ������ �۱淡 �׳� dfs�� �� �������� ����������? �ؼ� �ϱ��ߴµ� ���� �ڵ尡 ��Ʈ��ŷ�̶� ���� ����,,
//�׷��� �ڵ尡 �� ������� ���� �� ����. 
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

int dirY[] = { -1, 0, 1, 0 };
int dirX[] = { 0, 1, 0, -1 };
int n; int sum = 0; int ct = 0; int start = 0; int minn = 10000001;
vector<vector<int>> arr(15,vector<int>(15,0)); // 2�����迭 (15,0)
vector<int> visited(15, 0); //�湮 Ȯ�� ����
vector<int> v1;

void dfs(int index) {
		
	if (ct == n-1) { // ������ ���ٸ�
		if (arr[index][start] !=0) { //���������� ó�������������� ���ƿ� �� �ִٸ� 
			for (int i = 0; i < v1.size(); i++) { // �� ��ε��� sum ���ش�.
				sum += v1[i];
			}
			sum += arr[index][start]; 
			if (DEBUG) {
				cout << index << "-" << start << ": " << sum <<endl;
			}
			if (minn > sum) { //sum�߿��� ���� �������� ã�� ���ǹ�
				minn = sum;
			}
			sum = 0;
		}
		return;
	}

	visited[index] = 1;
		for (int i = 0; i < n; i++) {
			if (!visited[i] && index != i && arr[index][i] != 0) {//index->i�� ���� �ݺ���
				//�ڱ��ڽ�x, 0�̸� �ȵǰ�, �湮������ �ȵ�.
				ct++;
				v1.push_back(arr[index][i]); 
				if (DEBUG) {
					cout << index << "-" << i << ", ";
				}
				dfs(i);	
				visited[i] = 0;//���� �� �ʱ�ȭ
				v1.pop_back(); // ������
				ct--; // count
			}
		}
		return;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[j] = 0;
		}
		ct = 0;
		start = i;
		if (DEBUG) {
			cout << "//////////////" << endl;
		}
		dfs(i);
	}
	
	cout << minn << endl;
	return 0;
}