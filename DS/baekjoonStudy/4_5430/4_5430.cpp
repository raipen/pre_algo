#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

void revArr();
void delArr();
deque<int> intStr;

bool fwd = true;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T = 0;
	int num = 0;
	char e = '\0';
	//char control[100002]";
	//char str[200004];
	string control;
	string str;
	
	cin >> T;

	for (int i = 0; i < T; i++) {
		intStr.clear();
		fwd = true;
		e = '\0';
		cin >> control;
		cin >> num;
		cin >> str;

		for (int j = 0; str[j]!='\0'; j++) {
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
		for (int j = 0; control[j] != '\0' && e != 'e'; j++) {
			switch (control[j]) {
			case 'R':
				revArr();
				break;
			case 'D':
				if (num == 0) {
					cout << "error\n";
					e = 'e';
					break;
				}
				delArr();
				num--;
				break;
			}
		}
		if (num == 0 && e == 'e') continue;
		cout << '[';
		if (num > 0) {
			if (fwd == true) {
				for (int i = 0; i < num; i++) {
					cout << intStr[i];
					if (i != num - 1)	cout << ',';
				}
			}
			else {
				for (int i = num - 1; i >= 0; i--) {
					cout << intStr[i];
					if (i != 0)	cout << ',';
				}
			}
		}
		cout << "]\n";
	}

	return 0;
}

void revArr() {
	if (fwd == true) fwd = false;
	else fwd = true;
}
void delArr() {
	if (fwd == true) intStr.pop_front();
	else intStr.pop_back();
}
