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
	int index = 0, end = 0;	//index: 현재 진행된 회의 개수, end: 이전 회의가 끝난 시간
	for (int i = 0; i < size; i++) {
		if (arr[i].start >= end) {	//이전 회의가 끝난 후에 시작하는 회의 중 가장 빨리 끝나는 회의를 찾아서
			index++;					//그 회의를 진행
			end = arr[i].end;		//그 회의가 끝나는 시간을 저장
		}
	}
	return index;	//진행된 회의 수를 반환
}

int main() {
	int size;
	scanf("%d", &size);	//size 입력받기
	time* arr = (time*)malloc(size * sizeof(time));
	for (int i = 0; i < size; i++)
		scanf("%d %d", &arr[i].start, &arr[i].end);	//arr[]{start,end} 입력받기

	qsort(arr, size, sizeof(time), compare);	//end 기준 오름차순 정렬, end가 같다면 start 기준으로 오름차순 정렬
	printf("%d", possibleMeeting(arr, size));	//정렬된 회의 시간을 기준으로 가능한 회의 개수를 찾아 출력

	return 0;
}