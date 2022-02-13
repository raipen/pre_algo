#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct class
{
	int start;
	int end;
}class;

class room[200001];

int minheap[200001];
int size;
int heap_size = 0;
void input(class item);
int delete();
int compare(const void* a, const void* b);
int main()
{
	int size;
	for (int i = 0; i < 200001; i++)
	{
		minheap[i] = 2147483647;
	}
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d %d", &room[i].start, &room[i].end);
	}
	qsort(room, size, sizeof(class), compare);

	input(room[0]);

	for (int i = 1; i < size; i++)
	{

		if (room[i].start < minheap[1])
		{
			input(room[i]);
		}
		else
		{
			delete();
			input(room[i]);
		}
	}
	printf("%d", heap_size);
	return 0;
}
int compare(const void* a, const void* b) 
{
	return ((class*)a)->start == ((class*)b)->start ? ((class*)a)->end - ((class*)b)->end : ((class*)a)->start - ((class*)b)->start;
}

void input(class item)
{
	int tmp, parent, child;
	child = ++heap_size;
	parent = child / 2;
	minheap[child] = item.end;
	while (parent)
	{
		if (minheap[child] < minheap[parent])
		{
			tmp = minheap[child];
			minheap[child] = minheap[parent];
			minheap[parent] = tmp;
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
	int min = minheap[1];
	if (heap_size == 0)
		return 0;
	minheap[1] = minheap[heap_size];
	minheap[heap_size] = 2147483647;
	heap_size--;
	parent = 1;
	lchild = parent * 2;
	rchild = lchild + 1;
	while (1)
	{
		if (parent > heap_size)
			break;
		if (minheap[lchild] < minheap[rchild] && minheap[lchild] < minheap[parent])
		{
			tmp = minheap[parent];
			minheap[parent] = minheap[lchild];
			minheap[lchild] = tmp;
			parent = lchild;
			lchild = parent * 2;
			rchild = parent * 2 + 1;
		}
		else if (minheap[rchild] <= minheap[lchild] && minheap[rchild] < minheap[parent])
		{
			tmp = minheap[parent];
			minheap[parent] = minheap[rchild];
			minheap[rchild] = tmp;
			parent = rchild;
			lchild = parent * 2;
			rchild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
	return min;
}