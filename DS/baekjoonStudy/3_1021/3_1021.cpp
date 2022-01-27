#include <iostream>
#include <tuple>

using namespace std;

int* q;
int front = 1;
int rear = 0;
int count1 = 0;
int count2 = 0;

std::tuple<int, int>  qRightM(int, int, int);
std::tuple<int, int> qLeftM(int, int, int);
int deleteq(int N, int data, int M);

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int M;
	int num, sum = 0;

	cin >> N >> M;

	q = new int[N];

	q[0] = 1;
	for (int i = 1; i < N; i++) {
		q[i] = 1;
	}
	front = 0;
	rear = N - 1;

	for (int i = 0; i < M; i++) {
		cin >> num;
		sum += deleteq(N, num - 1, M);
		count1 = 0;
		count2 = 0;
	}

	cout << sum;

	return 0;
}

int deleteq(int N, int data, int M) {
	int lastCount = 0;
	int i = 0;
	int front1 = front, rear1 = rear;
	int front2 = front, rear2 = rear;
	int a = 0;

	while (1) {
		if (front1 == data) {
			a = front1;
			q[front1] = 0;

			if (front1 == rear1 && N == M) return 0;
			if (front1 == N - 1) front1 = 0;
			else front1++;

			while (1) {
				if (q[front1] != 1) {
					if (front1 == N - 1) front1 = 0;
					else front1++;
				}
				else break;

			}
			while (1) {
				if (q[rear1] == 1)	break;

				if (front1 == rear1 || q[rear1] != 1) {
					if (rear1 == 0) rear1 = N - 1;
					else rear1--;
				}
			}

			break;
		}
		tie(front1, rear1) = qRightM(N, front1, rear1);
	}
	q[a] = 1;

	while (1) {

		if (front2 == data) {
			q[front2] = 0;
			if (front2 == rear2 && N == M) return 0;
			if (front2 == N - 1) front2 = 0;
			else front2++;

			while (1) {
				if (q[front2] != 1) {
					if (front2 == N - 1) front2 = 0;
					else front2++;
				}
				else break;
			}
			while (1) {
				if (q[rear1] == 1) break;

				if (front2 == rear2 || q[rear2] != 1) {
					if (rear2 == 0) rear2 = N - 1;
					else rear2--;
				}
			}

			break;
		}
		tie(front2, rear2) = qLeftM(N, front2, rear2);
	}

	if (count1 >= count2) {
		front = front2;
		rear = rear2;
		lastCount = count2;
	}
	else {
		front = front1;
		rear = rear1;
		lastCount = count1;
	}

	return lastCount;
}

std::tuple<int, int> qRightM(int N, int front, int rear) {

	if (front == 0) front = N - 1;
	else front--;

	while (1) {
		if (q[front] != 1) {
			if (front == 0) front = N - 1;
			else front--;
		}
		else break;
	}

	if (rear == 0) rear = N - 1;
	else rear--;

	while (1) {
		if (q[rear] != 1) {
			if (rear == 0) rear = N - 1;
			else rear--;
		}
		else break;
	}
	count1++;

	return { front, rear };
}
std::tuple<int, int> qLeftM(int N, int front, int rear) {
	if (front == N - 1) front = 0;
	else front++;

	while (1) {
		if (q[front] != 1) {
			if (front == N - 1) front = 0;
			else front++;
		}
		else break;
	}

	if (rear == N - 1) rear = 0;
	else rear++;

	while (1) {
		if (q[rear] != 1) {
			if (rear == N - 1) rear = 0;
			else rear++;
		}
		else break;
	}
	count2++;

	return { front, rear };
}