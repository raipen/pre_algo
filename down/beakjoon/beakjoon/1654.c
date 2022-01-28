#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int K_line[10000];
void solu(long long int left,long long int right);

long long int require,num,answer;
int main()
{
	int max=0,i=0,tmp;
	
	scanf("%lld %lld", &num, &require);
	tmp = num;
	while (tmp--)
	{
		scanf("%d", &K_line[i]);
		if (K_line[i] > max)
		{
			max = K_line[i];
		}
		i++;
	}
	solu(1, max);
	printf("%lld",answer);
	return 0;
}
void solu(long long int left,long long int right)
{
	if (left > right)
		return ;
	int sum=0;
	long long int mid = (left + right) / 2;
	for (int i = 0; i < num; i++)
	{
		sum += K_line[i]/mid;
	}
	if (sum < require)
	{
		solu(left, mid - 1);
	}
	else
	{
		if (answer < mid)
			answer = mid;
		solu(mid+1, right);
	}

}