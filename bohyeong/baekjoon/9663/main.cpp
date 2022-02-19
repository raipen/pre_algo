#include <iostream>
#include <vector>

using namespace std;

int* visited; //visited[i] = j; = i행 j열의 좌표를 1차원배열로 표현해서 구현. 2차원배열로 하면 너무 복잡해짐 시간초과날거같음
int n;
int num = 0; //총 경우의 수를 count 하는 변수

/*11/ 12 13 14
21 22 23/ 24/
31 32/ 33 34
41 42 43 44*/

int check_queen(int row) {//퀸이 배치된 행을 매개변수로 받음
	for (int i = 1; i < row; i++) {
		if (visited[i] == visited[row] || row - i == abs(visited[row] - visited[i])) { //세로로 같은 열에 있는지 확인 및 대각선 확인
			return 0; //대각선은 열이 음수일수도 있으니 절댓값으로 한다
		}
	}

	return 1;
}

void backtracking(int ct_queen) {
	if (ct_queen == n+1) {//맨 처음에 1행을 주기 떄문에 n이 아닌 n+1 로 해야 queen 의 개수가 다 고려된다. n으로 할시에는 n=4 일때 queen 은 3개밖에 안된다.
		num++;
		return;
	}

	else {
		for (int i = 1; i <= n; i++) {
			visited[ct_queen] = i; // 일단 [ct_queen, i] 좌표에 퀸 배치해보고
			if (check_queen(ct_queen)) {//그 좌표에 퀸을 배치할 수 있다면 다음 행으로 넘어가서 다시 퀸을 배치한다.
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

