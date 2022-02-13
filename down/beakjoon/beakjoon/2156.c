#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int wine[10001];//포도주 잔의 개수 n<=10000
int dp[10001];
//인덱스 까지 최대 마실수 있는 포도주의 양
//예를 들어 1잔 까지는 wine[1]이 최대; 즉 dp[1]=wine[1]
//2잔은 wine[1]+wine[2]  즉 dp[2]=wine[1]+wine[2]
// 
//3잔은 경우의 수가 3가지로 나뉨 
//case 1: [1]+[3]	case 2:[2]+[3]	case 3:[1]+[2] 이 케이스중 가장 큰값을 dp[3]에 박음
//case 3을 볼때 조금 의아한 생각이 들수도 있음 왜 3개의 포도주를 골랐을때 최대값인데 [1]+[2]를 넣는지 이해가 안될 수 있지만
// 잘 생각해보면 3개의 잔이 있을때 가장 많이 마실수 있는 값을 박을 것이기 때문에 [1]+[2]가 포함 되어야 함 
// 
//4잔은 잘 생각해 보면 어차피 첫번째 잔은 선택을 하든 안하든 조건에 위배되는 경우가 없음
//따라서 첫번째 잔은 무조건 마시는것이 합당 이때 4개의 잔이 주어졌을때 3번째 잔을 고를때 처럼 3가지 케이스중 하나를 골라야함
//즉 dp[1]+(wine[2]+wine[4])or dp[1]+(wine[3]+wine[4])or dp[1]+(wine[2]+wine[3])
// 
//점화식으로 계산하면 dp[n]=(dp[n-3]+wine[n-1]+wine[n-2]or dp[n-2]+wine[n-1]or dp[n-1])이 됨
// 
//비슷한 문제로는 계단 오르기가 있음
int choice(int first, int second, int third);
//포도주 (1,3) or (2,3) or (1,2)
int main()
{
	int cup_num;
	scanf("%d", &cup_num);//몇 잔인지 입력

	for (int i = 0; i < cup_num; i++)//와인의 양 입력
	{
		scanf("%d", &wine[i]);
	}

	dp[0] = wine[0];

	dp[1] = dp[0] + wine[1];
	
	dp[2] = choice(wine[0] + wine[2], wine[1] + wine[2], wine[0] + wine[1]);

	//dp[0~2]까지는 직접 구해야 점화식의 인덱스를 맞춰줄 수 있음

	for (int i = 3; i < cup_num; i++)
	{
		dp[i] = choice(dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i], dp[i - 1]);
	}
	//i는 3부터 잔의 개수 까지 최대 와인량을 구해주는 모습 그리고 전에 dp에 담아 두었던 값을 활용함으로써 시간 복잡도를 줄임
	//예를 들어 dp[7]의 값을 구하려면 dp[4]의 값을 알아야 하는데 그값을 계산을 하지 않고 배열에 담아 둠으로써 직접 꺼내 씀
	printf("%d", dp[cup_num - 1]);

	return 0;
}
int choice(int case1, int case2, int case3)
{
	int max=-1;
	if (case1 > max)
	{
		max = case1;
	}
	if (case2 > max)
	{
		max = case2;
	}
	if (case3 > max)
	{
		max = case3;
	}
	return max;
}