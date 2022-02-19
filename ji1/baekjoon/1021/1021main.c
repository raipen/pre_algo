#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int s, cur = 1;
int* arr;

int ch(int n, int t) {
    arr[t] = -1;
    for (int i = 0;i <= n / 2;) {
        int k = cur++ % s;
        if (t == k) return i;
        if (arr[k] == -1) continue;
        i++;
    }
    for (int i = (n - 1) / 2;i > 0;) {
        int k = cur++ % s;
        if (t == k) return i;
        if (arr[k] == -1) continue;
        i--;
    }

}

int main() {
    int c;
    scanf("%d %d", &s, &c);
    arr = (int*)malloc((s) * sizeof(int));
    int r = 0, t;
    for (int i = 0; i < c;i++) {
        scanf("%d", &t);
        r += ch(s - i, t % s);
    }
    printf("%d", r);
    return 0;
}