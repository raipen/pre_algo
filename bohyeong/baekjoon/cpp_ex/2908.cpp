#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int reverse(int num) {
	string s = to_string(num); //s 라는 문자(열) 에 int->char* 로 바꾼 문자열 넣어주기
	reverse(s.begin(), s.end());
	return atoi(s.c_str());
}

int main() {
	int a, b;
	cin >> a >> b; //cin 정방화살표
	a = reverse(a);
	b = reverse(b);
	int ans = max(a, b);
	cout << ans << endl;


}