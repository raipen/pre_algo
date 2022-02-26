#include <iostream>
#include <vector>
using namespace std;


int main() {
	int n;
	cin >> n;
	cout << (1 << n) - 1 << endl;
	return 0;
}