#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int start;
	int end;
}time;

int compare(const void* a, const void* b) {
	return ((time*)a)->end == ((time*)b)->end ? ((time*)a)->start - ((time*)b)->start : ((time*)a)->end - ((time*)b)->end;
}

int possibleMeeting(time* arr, int size) {
	int index = 0, end = 0;	//index: ���� ����� ȸ�� ����, end: ���� ȸ�ǰ� ���� �ð�
	for (int i = 0; i < size; i++) {
		if (arr[i].start >= end) {	//���� ȸ�ǰ� ���� �Ŀ� �����ϴ� ȸ�� �� ���� ���� ������ ȸ�Ǹ� ã�Ƽ�
			index++;					//�� ȸ�Ǹ� ����
			end = arr[i].end;		//�� ȸ�ǰ� ������ �ð��� ����
		}
	}
	return index;	//����� ȸ�� ���� ��ȯ
}

int main() {
	int size;
	scanf("%d", &size);	//size �Է¹ޱ�
	time* arr = (time*)malloc(size * sizeof(time));
	for (int i = 0; i < size; i++)
		scanf("%d %d", &arr[i].start, &arr[i].end);	//arr[]{start,end} �Է¹ޱ�

	qsort(arr, size, sizeof(time), compare);	//end ���� �������� ����, end�� ���ٸ� start �������� �������� ����
	printf("%d", possibleMeeting(arr, size));	//���ĵ� ȸ�� �ð��� �������� ������ ȸ�� ������ ã�� ���

	return 0;
}