#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int K, N;
	long long int* lan;
	long long int divide = 0;
	long long int sum = 0;
	long long int nmax = 0;
	long long int left = 0, right = 0, mid = 0;
	long long int i;
	long long max = 0;
	cin >> K >> N;
	lan = new long long int[K];
	
	nmax = 0;
	for (int i = 0; i < K; i++) {
		cin >> lan[i];
		if (lan[nmax] < lan[i]) nmax = i;
	}

	divide = ceil((long double)N / K);
	right = lan[nmax] / divide;
	left = 1;
	mid = (left + right) / 2;
	
	while (left <= right) {
		sum = 0;

		for (i = 0; i < K; i++) {
			sum += lan[i] / mid;
		}

		if (sum >= N) {
			left = mid + 1;
			max = mid;
			//sum = 0;
			//for (i = 0; i < K; i++) {
			//	sum += lan[i] / left;
			//}
			//if (N > sum) {
			//	break;
			//}
		}
		else {
			right = mid - 1;
		}

		mid = (left + right) / 2;
	}

	//cout << mid;
	cout << max;

	return 0;
}