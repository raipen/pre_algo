//백준 10971(외판원 순회2)- N의 범위가 작길래 그냥 dfs로 다 돌려보면 되지않을까? 해서 하긴했는데 뭔가 코드가 백트래킹이랑 섞인 듯한,,
//그래서 코드가 좀 깔끔하지 않은 것 같다. 
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
#define DEBUG 0 //제출 시 0
#define endl    '\n'
#define INF 987654321
#define SHARING 100001

using namespace std;

int dirY[] = { -1, 0, 1, 0 };
int dirX[] = { 0, 1, 0, -1 };
int n; int sum = 0; int ct = 0; int start = 0; int minn = 10000001;
vector<vector<int>> arr(15,vector<int>(15,0)); // 2차원배열 (15,0)
vector<int> visited(15, 0); //방문 확인 벡터
vector<int> v1;

void dfs(int index) {
		
	if (ct == n-1) { // 끝까지 갔다면
		if (arr[index][start] !=0) { //끝지점에서 처음시작지점으로 돌아올 수 있다면 
			for (int i = 0; i < v1.size(); i++) { // 온 경로들을 sum 해준다.
				sum += v1[i];
			}
			sum += arr[index][start]; 
			if (DEBUG) {
				cout << index << "-" << start << ": " << sum <<endl;
			}
			if (minn > sum) { //sum중에서 가장 작은값을 찾는 조건문
				minn = sum;
			}
			sum = 0;
		}
		return;
	}

	visited[index] = 1;
		for (int i = 0; i < n; i++) {
			if (!visited[i] && index != i && arr[index][i] != 0) {//index->i로 가는 반복문
				//자기자신x, 0이면 안되고, 방문했으면 안됨.
				ct++;
				v1.push_back(arr[index][i]); 
				if (DEBUG) {
					cout << index << "-" << i << ", ";
				}
				dfs(i);	
				visited[i] = 0;//갔던 길 초기화
				v1.pop_back(); // 수열도
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