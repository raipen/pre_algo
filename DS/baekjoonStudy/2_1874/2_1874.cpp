#include <iostream>
using namespace std;

int top = -1;
int* stack;
int n;

void push(int data);
int pop();
void Aprint(char *, int);

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int* arr;
	char* printArr;
	int count = 0;
	int i = 0;
	int j = 1;

	cin >> n;
	stack = new int[n];
	arr = new int[n];
	printArr = new char[n * 2];

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	i = 0;
	push(j++);
	printArr[i++] = '+';
	while (1) {
		if (stack[top] == arr[count]) {
			if (top == -1) break;
			count++;
			pop();
			printArr[i++] = '-';
		}
		else {
			if (j == n+1) {
				cout << "NO";
				exit(-1);
			}
			push(j++);
			printArr[i++] = '+';
		}
	}
	Aprint(printArr, n*2);
	return 0;
}

void push(int data) {
	if (top >= n - 1) exit(-1);
	stack[++top] = data;
}

int pop() {
	if (top < 0) exit(-1);
	return stack[top--];
}

void Aprint(char *printArr, int n) {
	for (int i = 0; i < n; i++) {
		cout << printArr[i] << "\n";
	}
}