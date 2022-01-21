#include <iostream>
#include <cstring>
using namespace std;

bool groupWords(char* a);
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num = 0;
	int count = 0;
	char words[100] = "\0";

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> words;
		if (groupWords(words) == true) count++;
	}
	cout << count;
}

bool groupWords(char* a) {
	
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == a[i + 1]) continue;
		for (int j = 0; j <= i; j++) {
			if (a[i + 1] == a[j]) return false;
		}
	}
	return true;
}