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

    scanf("%d", &n); //ġŲ���� ����
    cnt = n;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &chicken[i]);
    }

    scanf("%d", &k); //���� ������ �������� ȸ������ ��

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
    int pivot = arr[(left + right) / 2]; //�Ǻ� ��ġ(�߾�)�� ���� ����.
    //�Ʒ��� while���� ���Ͽ� pivot �������� ��, �� ũ�� ���� �� ����. = Partition
    while (L <= R) {

        //pivot�� �߰� ���̰�, �� ��� arr[L], arr[R]�� pivot�� ���ϴ� �߰� ������ �Ѿ�� ����� �� �� ����.
        while (arr[L] < pivot) //left���� �����ϸ� pivot �̻��� ���� ã��.
            L++;
        while (arr[R] > pivot) //right���� �����ϸ� pivot ���� ���� ã��.
            R--;
        //L, R ��� �ִ� pivot ��ġ���� �̵�.

        if (L <= R) { //���� L�� R���ϸ�. (���� : L>R �κ��� �̹� ������ �� ������).
            if (L != R) { //���� ���� ��츸.
                temp = arr[L];
                arr[L] = arr[R];
                arr[R] = temp;
            } //L�� R�� ���ٸ� ��ȯ(SWAP)�� �ʿ� ���� �� ĭ�� ���ุ ���ָ� ��.
            L++; R--; //�׸��� L,R �� ĭ �� ����
        }
    }
    //���� Ȯ���Ͽ� ����Լ���.
    if (left < R)
        QuickSort(arr, left, R);
    if (L < right)
        QuickSort(arr, L, right);
}