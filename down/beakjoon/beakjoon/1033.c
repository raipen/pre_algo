//백준1033번 이진탐색문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int source[MAX_SIZE];
int relate[MAX_SIZE][MAX_SIZE];
int check[MAX_SIZE];
void is_relate(int start,int mult);
int size;
void solu(int source_1,int source_2,int ratio_1,int ratio_2);
void print();
void init();
int getGCD(int numArr[]);
void divide();
int main()
{
	int num, ratio_1, ratio_2,source_1,source_2;
	scanf("%d", &size);
	num = size-1;
	while (num--)
	{
		scanf("%d %d %d %d",&source_1,&source_2,&ratio_1, &ratio_2);
		solu(source_1,source_2,ratio_1,ratio_2);
	}
	divide();
	print();
	return 0;
}
void solu(int source_1, int source_2, int ratio_1, int ratio_2)
{
	int tmp,tmp2;
	tmp = source[source_1];
	tmp2 = source[source_2];
	if (!source[source_1] && !source[source_2])
	{
		source[source_1] = ratio_1;
		source[source_2] = ratio_2;
	}
	else if (source[source_1] && source[source_2])
	{
		source[source_1] *= tmp2 * ratio_1;
		source[source_2] *= tmp * ratio_2;
		is_relate(source_1, tmp2*ratio_1);
		init();
		is_relate(source_2, tmp* ratio_2);
		init();
	}
	else
	{
		if (source[source_1])
		{
			
			source[source_1] = tmp * ratio_1;
			source[source_2] = tmp* ratio_2;
			is_relate(source_1, ratio_1);
			init();
		}
		else
		{
			source[source_1] = tmp2 * ratio_1;
			source[source_2] = tmp2 * ratio_2;
			is_relate(source_2, ratio_2);
			init();
		}
	}
	relate[source_1][source_2] = 1;
	relate[source_2][source_1] = 1;
}
void print()
{
	for (int i = 0; i < size; i++)
		printf("%d ", source[i]);
}
void is_relate(int start,int mult)
{
	check[start] = 1;

	for (int i = 0; i < size; i++)
	{
		if (relate[start][i] && !check[i])
		{
			source[i] *= mult;
			is_relate(i, mult);
		}
	}
}
void init()
{
	for (int i = 0; i < size; i++)
		check[i] = 0;
}
int getGCD(int numArr[]) 
{
	int i,j,gcd=1;
	int min = 9999999;
	int cnt;
	for (i = 0; i < size; i++) 
	{
		if (numArr[i] < min) 
		{
			min = numArr[i]; 
		}
	}
	for (i = 2; i <= min; i++) 
	{
		cnt = 0;
		for (j = 0; j < size; j++) 
		{
			if (numArr[j] % i == 0) // 현재의 숫자로 나눴을 때 나머지가 0이면 
			{
				cnt++; // cnt값을 증가해서 약수의 개수를 증가 
			}
		}
		if (cnt == size) // 약수의 개수가 SIZE와 같다면 공약수 
		{
			gcd = i; // 공약수 이므로 저장 
		}
	}

	return gcd; // 그렇게 마지막에 저장된 공약수를 반환 즉 최대공약수 

}
void divide()
{
	int divided = getGCD(source);
	for (int i = 0; i < size; i++)
	{
		source[i] /= divided;
	}
}