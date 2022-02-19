#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int origin_list[1000001];
int origin_idx[1000001];
int lis[1000001];
int lis_size;
int size;
int answer[1000001];
int binary_search(int first, int end, int target);

int main()
{
	int idx,start,tmp;
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &origin_list[i]);
	}
	lis[lis_size++] = origin_list[0];
	origin_idx[0] = 0;
	for (int j = 1; j < size; j++)
	{
		if (lis[lis_size - 1] < origin_list[j])
		{
			lis[lis_size++] = origin_list[j];
			origin_idx[j] = lis_size-1;
		}
		else
		{
			idx = binary_search(0, lis_size - 1, origin_list[j]);
			lis[idx] = origin_list[j];
			origin_idx[j] = idx;
		}
	}
	tmp = lis_size;
	printf("%d\n", lis_size);
	/*for (int k = size - 1; k >=0 ; k--)
	{
		if ((lis_size - 1) == origin_idx[k])
		{
			start = k;
			break;
		}
	}*/
	for (int i =size-1; i >= 0; i--)
	{
		if ((lis_size - 1) == origin_idx[i])
		{
			if (!answer[origin_idx[i]])
			{
				answer[origin_idx[i]] = origin_list[i];

				lis_size--;
			}
		}
		
	}
	for (int i = 0; i<tmp; i++)
	{
		//printf("%d ", answer[i]);
	}
	return 0;
}
int binary_search(int first, int end, int target)
{
	while (first < end)
	{
		int mid = (first + end) / 2;
		if (lis[mid] < target)
		{
			first = mid + 1;
		}
		else
		{
			end = mid ;
		}
	}
	return end;
}