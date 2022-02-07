#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/// <summary>
/// qsort를 위한 비교 함수
/// void qsort(void *_Base, size_t _NumOfElements, size_t _SizeOfElements, int (*_PtFuncCompare)(void const *, void const *));
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns>양수:a를 뒤로, 음수: b를 뒤로, 0: 아무것도 하지 않음</returns>
int compare(const void* a, const void* b){
	return *(int*)a - *(int*)b;    // 오름차순
}

/// <summary>
/// 중복 없이 정렬된 배열을 기준으로 참조용 배열 만들기
/// </summary>
/// <param name="sorted">정렬된 배열</param>
/// <param name="size">sorted 정수 개수</param>
/// <param name="plus"> 양수 값의 압축 좌표를 저장할 배열</param>
/// <param name="minus"> 음수 값의 압축 좌표를 저장할 배열</param>

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
/// 중복 없이 정렬된 배열을 리턴하는 함수
/// </summary>
/// <param name="sorted">정렬된 배열</param>
/// <param name="size">sorted 정수 개수</param>
/// <param name="index"> 리턴할 배열의 size</param>
/// <returns>중복 없이 정렬된 배열</returns>
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
/// 이진 탐색
/// </summary>
/// <param name="a">배열</param>
/// <param name="f">찾는 값</param>
/// <param name="l">배열 시작 인덱스</param>
/// <param name="r">배열 종료 인덱스</param>
/// <returns>찾는 값이 배열에서 존재하는 경우, 해당 값의 인덱스/존재하지 않는 경우 -1</returns>
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
	//input[]에 입력값들을 입력 순서대로 저장
	//sorted[]에 입력값들을 오름차순으로 저장

	int* ds = deleteSame(sorted, size ,&size2);	
	//ds[]에 중복 제거된 입력값들을 오름차순으로 저장
	//size2에 ds배열의 사이즈 저장

	for (int i = 0;i < size;i++) {
		printf("%d ", find(ds,input[i],0,size2)); 
		//이진탐색으로 해당 입력값이 오름차순 정렬 시 몇번째 값인지 찾아서 출력
		//총 시간 복잡도는 size2 * 1 + size * log_2(size2); 즉 O(size*log_2(size2));
			//ds 만들기 size *1;
			//출력할때 이진 탐색을 하므로 size * log_2(size2);
	}
	/*for (int i = 0;i < size;i++) {
		printf("%d ",input[i]>=0?plus[input[i]]:minus[-1*input[i]]);
		//해당 값이 오름차순 정렬 시 몇번째 값인지 저장해둔 배열에서 가져와서 출력
		//총 시간 복잡도는 size2 * 1 + size * 2; 즉 O(size2+size);
			//ds 만들기 size *1;
			//ds를 바탕으로 plus와 minus 배열에 넣을때 size2*1;
			//출력할때 size*1;
	}*/
	return 0;
}