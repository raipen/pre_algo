#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long long MinNumber, MaxNumber;

	int Is_SQ_Arr[1000001] = { 0, };

	scanf_s("%lld %lld", &MinNumber, &MaxNumber);
	//scanf("%lld %lld", &MinNumber, &MaxNumber);

	
	if (1 <= MinNumber && MinNumber <= 1000000000000 && MinNumber <= MaxNumber && MaxNumber <= MinNumber + 1000000)
	{
		long long PartDivider, Not_SQ_Count = 0;
		for (long long i = 2; (i * i) <= MaxNumber; i++)
		{
			PartDivider = MinNumber / (i * i);
			if (!(MinNumber % (i * i))) PartDivider -= 1;

			for (long long j = i * i * (PartDivider + 1); j <= MaxNumber; j += i * i)
				Is_SQ_Arr[j - MinNumber] = 1;
		}
		for (int i = 0; i <= (MaxNumber - MinNumber); i++)
		{
			if (!Is_SQ_Arr[i]) Not_SQ_Count++;
		}
		printf("%lld", Not_SQ_Count);
	}

	return 0;
}