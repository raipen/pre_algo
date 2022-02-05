#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int chicken[1048577];
int tmp[1048577];
int n, k;
int cnt = 0;

void QuickSort(int* arr, int left, int right);

int main()
{
    int i, j;

    scanf("%d", &n); //치킨집의 개수
    cnt = n;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &chicken[i]);
    }

    scanf("%d", &k); //현재 정렬을 진행중인 회원들의 수

    for (i = 0; i < k; i++)
    {
        QuickSort(&chicken[i * n / k], 0, n / k - 1);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", chicken[i]);
    }

    return 0;
}

void QuickSort(int* arr, int left, int right) {
    int L = left, R = right;
    int temp;
    int pivot = arr[(left + right) / 2]; //피봇 위치(중앙)의 값을 받음.
    //아래의 while문을 통하여 pivot 기준으로 좌, 우 크고 작은 값 나열. = Partition
    while (L <= R) {

        //pivot이 중간 값이고, 비교 대상 arr[L], arr[R]은 pivot과 비교하니 중간 지점을 넘어가면 종료로 볼 수 있음.
        while (arr[L] < pivot) //left부터 증가하며 pivot 이상의 값을 찾음.
            L++;
        while (arr[R] > pivot) //right부터 감소하며 pivot 이하 값을 찾음.
            R--;
        //L, R 모두 최대 pivot 위치까지 이동.

        if (L <= R) { //현재 L이 R이하면. (이유 : L>R 부분은 이미 정리가 된 상태임).
            if (L != R) { //같지 않은 경우만.
                temp = arr[L];
                arr[L] = arr[R];
                arr[R] = temp;
            } //L과 R이 같다면 교환(SWAP)은 필요 없고 한 칸씩 진행만 해주면 됨.
            L++; R--; //그리고 L,R 한 칸 더 진행
        }
    }
    //조건 확인하여 재귀함수로.
    if (left < R)
        QuickSort(arr, left, R);
    if (L < right)
        QuickSort(arr, L, right);
}