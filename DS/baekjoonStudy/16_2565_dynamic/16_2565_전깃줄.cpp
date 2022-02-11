//dynamic programming문제, 전형적인 LIS문제로 배열의 부분 수열 중 
//오름차순으로 가장 긴 부분 수열을 구하는 문제이다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v1; // 전깃줄 연결 정보


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n = 0;
	int buf1, buf2;
	cin >> n; // 젓깃줄 갯수 입력
	vector<int> v2(n, 1); // 크기가 n인 v2의 원소들을 1로 초기화


	for (int i = 0; i < n; i++) { // 전봇대 연결 위치 번호 한 쌍으로 입력 받기
		cin >> buf1 >> buf2;
		v1.push_back({ buf1, buf2 });
	} 

	sort(v1.begin(), v1.end()); // A전봇대 기준으로 오름차순 정렬

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