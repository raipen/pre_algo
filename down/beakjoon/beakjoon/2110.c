
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#define compare (x,y) x>y?1:x==y?0:-1
int home[1000000];
int router;
int size;
int answer;
int compare(const void* a, const void* b);
void solu(int min, int max);
int main()
{
	int save1, save2;
	scanf("%d %d",&size,&router);

	for (int i = 0; i < size; i++)
	{
		scanf("%d", &home[i]);
	}
	qsort(home, size, sizeof(int), compare);
	solu(1, 1000000030);
	printf("%d", answer);
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
	int cnt = 1;
	int length = (max+min) / 2;	
	int pivot =0;
	for (int i = 1; i < size; i++)
	{
		if (home[i] - home[pivot] >= length)
		{
			cnt++;
			pivot=i;
		}
	}
	if (cnt < router)
	{
		solu(min, length-1);
	}
	else
	{
		if (answer < length)
			answer = length;
		solu(length+1 , max);
	}
}
