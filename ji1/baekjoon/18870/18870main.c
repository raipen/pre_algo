#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/// <summary>
/// qsort�� ���� �� �Լ�
/// void qsort(void *_Base, size_t _NumOfElements, size_t _SizeOfElements, int (*_PtFuncCompare)(void const *, void const *));
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns>���:a�� �ڷ�, ����: b�� �ڷ�, 0: �ƹ��͵� ���� ����</returns>
int compare(const void* a, const void* b){
	return *(int*)a - *(int*)b;    // ��������
}

/// <summary>
/// �ߺ� ���� ���ĵ� �迭�� �������� ������ �迭 �����
/// </summary>
/// <param name="sorted">���ĵ� �迭</param>
/// <param name="size">sorted ���� ����</param>
/// <param name="plus"> ��� ���� ���� ��ǥ�� ������ �迭</param>
/// <param name="minus"> ���� ���� ���� ��ǥ�� ������ �迭</param>

/*void deleteSame(int* sorted, int size,int* plus, int* minus) {
	int* notSame = (int*)malloc(size * sizeof(int));
	int index = 0;
	notSame[index++] = sorted[0];
	for (int i = 1;i < size;i++) {
		if (sorted[i] == notSame[index-1]) continue;
		notSame[index++] = sorted[i];
	}
	while (index--) {
		if (notSame[index] >= 0) plus[notSame[index]] = index;
		else minus[-1 * notSame[index]] = index;
	}
}*/

/// <summary>
/// �ߺ� ���� ���ĵ� �迭�� �����ϴ� �Լ�
/// </summary>
/// <param name="sorted">���ĵ� �迭</param>
/// <param name="size">sorted ���� ����</param>
/// <param name="index"> ������ �迭�� size</param>
/// <returns>�ߺ� ���� ���ĵ� �迭</returns>
int* deleteSame(int* sorted, int size,int* index) {
	int* notSame = (int*)malloc(size * sizeof(int));
	(*index) = 0;
	for (int i = 0;i < size;i++) {
		if ((*index) &&sorted[i] == notSame[(*index) - 1]) continue;
		notSame[(*index)++] = sorted[i];
	}
	return notSame;
}

/// <summary>
/// ���� Ž��
/// </summary>
/// <param name="a">�迭</param>
/// <param name="f">ã�� ��</param>
/// <param name="l">�迭 ���� �ε���</param>
/// <param name="r">�迭 ���� �ε���</param>
/// <returns>ã�� ���� �迭���� �����ϴ� ���, �ش� ���� �ε���/�������� �ʴ� ��� -1</returns>
int find(int a[], int f, int l, int r) {
	return (l > r) ? -1 : (a[(l + r) / 2] > f ? find(a, f, 0, (l + r) / 2 - 1) : (a[(l + r) / 2] == f ? (l + r) / 2 : find(a, f, (l + r) / 2 + 1, r)));
}


int main() {
	int size,size2;
	scanf("%d", &size);
	int* input = (int*)malloc(size * sizeof(int));
	int* sorted = (int*)malloc(size * sizeof(int));
	/*int plus[1000000000];
	int minus[1000000000];*/
	for(int i=0;i<size;i++) {
		scanf("%d", &input[i]);
		sorted[i] = input[i];
	}
	qsort(sorted, size, sizeof(int), compare);
	//input[]�� �Է°����� �Է� ������� ����
	//sorted[]�� �Է°����� ������������ ����

	int* ds = deleteSame(sorted, size ,&size2);	
	//ds[]�� �ߺ� ���ŵ� �Է°����� ������������ ����
	//size2�� ds�迭�� ������ ����

	for (int i = 0;i < size;i++) {
		printf("%d ", find(ds,input[i],0,size2)); 
		//����Ž������ �ش� �Է°��� �������� ���� �� ���° ������ ã�Ƽ� ���
		//�� �ð� ���⵵�� size2 * 1 + size * log_2(size2); �� O(size*log_2(size2));
			//ds ����� size *1;
			//����Ҷ� ���� Ž���� �ϹǷ� size * log_2(size2);
	}
	/*for (int i = 0;i < size;i++) {
		printf("%d ",input[i]>=0?plus[input[i]]:minus[-1*input[i]]);
		//�ش� ���� �������� ���� �� ���° ������ �����ص� �迭���� �����ͼ� ���
		//�� �ð� ���⵵�� size2 * 1 + size * 2; �� O(size2+size);
			//ds ����� size *1;
			//ds�� �������� plus�� minus �迭�� ������ size2*1;
			//����Ҷ� size*1;
	}*/
	return 0;
}