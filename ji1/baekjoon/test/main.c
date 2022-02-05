#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    int blue;
    int white;
} paper;

int matrix[128][128];

paper check(int col, int row, int size);

int main(void)
{
    int size;
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf(" %d", &matrix[i][j]);

    paper N = check(0, 0, size);
    printf("%d\n%d", N.white, N.blue);

    return 0;
}

paper check(int col, int row, int size)
{
    paper cnt = { 0,0 };

    if (size == 1) {     // 재귀 종료문
            // blue = 1, white = 0
            cnt.blue = matrix[col][row];
            cnt.white = !matrix[col][row];
    }
    else
    {
        int newSize = size / 2;
        paper check1 = check(col, row, newSize);   // check1을 2분면으로 1, 3, 4분면의 색을 확인
        paper check2 = check(col + newSize, row, newSize);
        paper check3 = check(col, row + newSize, newSize);
        paper check4 = check(col + newSize, row + newSize, newSize);
        cnt.blue = check1.blue + check2.blue + check3.blue + check4.blue;
        cnt.white = check1.white + check2.white + check3.white + check4.white;
        if (!cnt.white) cnt.blue = 1;
        if (!cnt.blue) cnt.white = 1;
    }

    return cnt;
}