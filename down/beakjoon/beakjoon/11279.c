//maxÈü
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int maxheap[1000001];
int size;
int heap_size = 0;
void input(int item);
int delete();
int main()
{
	int item;
	for (int i = 1; i < 1000000; i++)
	{
		maxheap[i] = 0;
	}
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &item);
		if (!item)
		{
			printf("%d\n", delete());
		}
		else
		{
			input(item);
		}
	}
	return 0;
}
void input(int item)
{

	int tmp, parent, child;
	child = ++heap_size;
	parent = child / 2;
	maxheap[child] = item;
	while (parent)
	{
		if (maxheap[child] > maxheap[parent])
		{
			tmp = maxheap[child];
			maxheap[child] = maxheap[parent];
			maxheap[parent] = tmp;
			child = parent;
			parent = child / 2;
		}
		else
			break;
	}
}
int delete()
{
	int tmp, lchild, rchild, parent;
	int max = maxheap[1];
	if (heap_size == 0)
		return 0;
	maxheap[1] = maxheap[heap_size];
	maxheap[heap_size] =0;
	heap_size--;
	parent = 1;
	lchild = parent * 2;
	rchild = lchild + 1;
	while (1)
	{
		if (parent > heap_size)
			break;
		if (maxheap[lchild] > maxheap[rchild] && maxheap[lchild] > maxheap[parent])
		{
			tmp = maxheap[parent];
			maxheap[parent] = maxheap[lchild];
			maxheap[lchild] = tmp;
			parent = lchild;
			lchild = parent * 2;
			rchild = parent * 2 + 1;
		}
		else if (maxheap[rchild] >= maxheap[lchild] && maxheap[rchild] > maxheap[parent])
		{
			tmp = maxheap[parent];
			maxheap[parent] = maxheap[rchild];
			maxheap[rchild] = tmp;
			parent = rchild;
			lchild = parent * 2;
			rchild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
	return max;
}
