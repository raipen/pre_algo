#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>

using namespace std;

void revArr();
deque<int> delArr(deque<int> intStr);
int dupR(char* str);

bool fwd = true;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T = 0;
	int num = 0;
	int d = 0;
	int j = 0;
	int k = 0;
	char e = '\0';
	int insi = 0;
	int strl, strc = 0;
	char control[100000] = "\0";
	char str[400001] = "\0";
	deque<int> intStr;

	cin >> T;

	for (int i = 0; i < T; i++) {
		intStr.clear();
		fwd = true;
		e = '\0';
		cin >> control;
		cin >> num;
		cin >> str;
		strl = strlen(str);
		strc = strlen(control);
		for (int j = 0; j < strl; j++) {
			if (str[j] > 47 && str[j] < 58) {
				if (str[j + 1] > 47 && str[j + 1] < 58) {
					if (str[j + 2] > 47 && str[j + 2] < 58) {
						intStr.push_back((str[j] - 48) * 100 + (str[j + 1] - 48) * 10 + str[j + 2] - 48);
						j = j + 2;
						continue;
					}
					intStr.push_back((str[j] - 48) * 10 + str[j + 1] - 48);
					j++;
					continue;
				}
				intStr.push_back(str[j] - 48);
			}
		}
		for (j = 0; j < strc; j++) {
			switch (control[j]) {
			case 'R':
				d = dupR(&control[j]);
				j = j + d;
				if (d % 2 == 0) revArr();
				break;
			case 'D':
				if (intStr.size() == 0) {
					cout << "error\n";
					e = 'e';
					j = strc - 1;
					break;
				}
				intStr = delArr(intStr);
				break;
			}
		}
		if (intStr.size() == 0 && e == 'e') continue;
		insi = intStr.size();
		cout << '[';
		if (fwd == true) {
			for (int i = 0; i < insi; i++) {
				cout << intStr[i];
				if (i != insi - 1)	cout << ',';
			}
		}
		else {
			for (int i = insi - 1; i >= 0; i--) {
				cout << intStr[i];
				if (i != 0)	cout << ',';
			}
		}
		cout << "]\n";
	}
}

void revArr() {
	if (fwd == true) fwd = false;
	else fwd = true;
}
deque<int> delArr(deque<int> intStr) {
	if (fwd == true) intStr.pop_front();
	else intStr.pop_back();

	return intStr;
}

int dupR(char* str) {
	int i;
	int num = strlen(str);
	for (i = 0; i < num; i++) {
		if (str[i] != str[i + 1]) break;
	}

	return i;
}

