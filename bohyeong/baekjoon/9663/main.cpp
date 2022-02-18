#include <iostream>
#include <vector>

using namespace std;

int* visited; //visited[i] = j; = i�� j���� ��ǥ�� 1�����迭�� ǥ���ؼ� ����. 2�����迭�� �ϸ� �ʹ� �������� �ð��ʰ����Ű���
int n;
int num = 0; //�� ����� ���� count �ϴ� ����

/*11/ 12 13 14
21 22 23/ 24/
31 32/ 33 34
41 42 43 44*/

int check_queen(int row) {//���� ��ġ�� ���� �Ű������� ����
	for (int i = 1; i < row; i++) {
		if (visited[i] == visited[row] || row - i == abs(visited[row] - visited[i])) { //���η� ���� ���� �ִ��� Ȯ�� �� �밢�� Ȯ��
			return 0; //�밢���� ���� �����ϼ��� ������ �������� �Ѵ�
		}
	}

	return 1;
}

void backtracking(int ct_queen) {
	if (ct_queen == n+1) {//�� ó���� 1���� �ֱ� ������ n�� �ƴ� n+1 �� �ؾ� queen �� ������ �� ����ȴ�. n���� �ҽÿ��� n=4 �϶� queen �� 3���ۿ� �ȵȴ�.
		num++;
		return;
	}

	else {
		for (int i = 1; i <= n; i++) {
			visited[ct_queen] = i; // �ϴ� [ct_queen, i] ��ǥ�� �� ��ġ�غ���
			if (check_queen(ct_queen)) {//�� ��ǥ�� ���� ��ġ�� �� �ִٸ� ���� ������ �Ѿ�� �ٽ� ���� ��ġ�Ѵ�.
				backtracking(ct_queen + 1);
			}
		}

	}

}

int main() {
	cin >> n;
	visited = new int[n+1];
	
	for (int i = 0; i <= n; i++) {
		visited[i] = 0;
	}

	backtracking(1);
	cout << num << endl;

	/*for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				cout << fined[i][j];
			}
			cout << endl;
		}*/

	delete[] visited;
	return 0;

}

