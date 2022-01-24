#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#define compare (x,y) x>y?1:x==y?0:-1
int home[200001];
int router;
int size;
int answer;
int compare(const void* a, const void* b);
void solu(int min, int max);
void re_solu(int min, int max);
int main()
{
	int save1, save2;
	scanf("%d %d",&size,&router);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &home[i]);
	}
	qsort(home, size, sizeof(int), compare);
	solu(0, size);
	save1 = answer;
	answer = 0;
	re_solu(0,size-1);
	save2 = answer;
	if (save1 > save2)
		printf("%d", save1);
	else
		printf("%d", save2);
	return 0;
}
int compare(const void* a, const void* b)   
{
    int num1 = *(int*)a;   
    int num2 = *(int*)b;  

    if (num1 > num2) 
        return 1;   

    if (num1 < num2) 
        return -1;   

    return 0;      
}
void solu(int min,int max)
{
	if (min > max)
		return;
	int cnt = 2;
	int mid = (min + max) / 2;
	int length = home[mid] - home[0];
	int pivot = mid;
	for (int i = mid+1; i < size; i++)
	{
		if (home[i] - home[pivot] >= length)
		{
			cnt++;
			pivot++;
		}
	}
	if (cnt < router)
	{
		max = mid;
		solu(min, max - 1);
	}
	else
	{
		if (answer < length)
			answer = length;
		min = mid;
		solu(min + 1, max);
	}
}
void re_solu(int min, int max)
{
	if (min > max)
		return;
	int cnt = 2;
	int mid = (min + max) / 2;
	int length = home[size-1] - home[mid];
	int pivot = mid;
	for (int i = mid -1; i >= 0; i--)
	{
		if (home[pivot] - home[i] >= length)
		{
			cnt++;
			pivot--;
		}
	}
	if (cnt < router)
	{
		min = mid;
		re_solu(min+1, max);
	}
	else
	{
		if (answer < length)
			answer = length;
		max = mid;
		re_solu(min, max-1);
	}

}
