#include <stdio.h>
#include <stdlib.h>

#define SWAP(a,b,tmp) {(tmp) = (a); (a) = (b); (b) = (tmp);}
#define GCDA(a,b,tmp) {(tmp) = (a) % (b); (a) = (b); (b) = (tmp);}

int FindGCD(int x, int y)
{
	int tmp;
	if (x < y) SWAP(x, y, tmp);
	while (y != 0) GCDA(x, y, tmp);
	return x;
}
int FindLCM(int x, int y)
{
	int z = (x * y) / FindGCD(x, y);
	return z;
}

int InputArr[9][10] = { 0, };
int N;

void print()
{
	//test
	//printf("===============================================\n");
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%3d ", InputArr[i][j]);
		}
		puts("");
	}
}
int main(void)
{
	int a, b, p, q;
	//int InputArr[9][10] = { 0, };
	int lcm[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, tmp;
	int out[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };


	scanf_s("%d", &N);
	//scanf("%d", &N);

	for (int i = 0; i < N - 1; i++)
	{
		scanf_s("%d %d %d %d", &a, &b, &p, &q);
		//scanf("%d %d %d %d", &a, &b, &p, &q);

		int gcd = FindGCD(p, q);
		p /= gcd;
		q /= gcd;
		//printf("==GCD : %d==\n", gcd);

		InputArr[i][a] = p;
		InputArr[i][b] = q;
	}
	

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (InputArr[j][i]) lcm[i] = FindLCM(lcm[i], InputArr[j][i]);
		}
		printf("LCM : %3d\n", lcm[i]);
		
		for (int j = 0; j < N - 1; j++)
		{
			if (InputArr[j][i])
			{
				for (int k = 0; k < N; k++)
				{
					if (i != k && InputArr[j][k])
					{
						InputArr[j][k] *= (lcm[i] / InputArr[j][i]);
						//if (i > k) i = k;
					}
				}
			}
		}
		print();
		puts("/////////////////////////////////////////////\n");
	}

	

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (InputArr[j][i]) out[i] *= InputArr[j][i];
		}
	}
	for (int i = 0; i < N; i++)
	{
		printf("%3d ", out[i]);
	}

	return 0;
}