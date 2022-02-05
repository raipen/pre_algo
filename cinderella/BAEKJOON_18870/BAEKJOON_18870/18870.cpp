#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ArrSize, InputNum;
vector<int> InputArr, SqzArr;

int main(void)
{
	cin >> ArrSize;

	for (int i = 0; i < ArrSize; i++)
	{
		cin >> InputNum;
		InputArr.push_back(InputNum);
		SqzArr.push_back(InputNum);
	}

	//sort, erase, unique 다시 공부하기
	sort(SqzArr.begin(), SqzArr.end());
	SqzArr.erase(unique(SqzArr.begin(), SqzArr.end()), SqzArr.end());

	//for (auto i : InputArr) <- 범위 기반 반복문
	for (unsigned int i = 0; i < InputArr.size(); i++)
	{
		cout << (lower_bound(SqzArr.begin(), SqzArr.end(), InputArr[i]) - SqzArr.begin()) << ' ';
	}
}