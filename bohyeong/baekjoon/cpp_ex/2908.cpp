#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int reverse(int num) {
	string s = to_string(num); //s ��� ����(��) �� int->char* �� �ٲ� ���ڿ� �־��ֱ�
	reverse(s.begin(), s.end());
	return atoi(s.c_str());
}

int main() {
	int a, b;
	cin >> a >> b; //cin ����ȭ��ǥ
	a = reverse(a);
	b = reverse(b);
	int ans = max(a, b);
	cout << ans << endl;


}