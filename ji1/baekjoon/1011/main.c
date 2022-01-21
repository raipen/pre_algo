#include <stdio.h>
#include <math.h>

long long result(long long n) {
    long long k = (int)sqrt(n - 1) * 2;
    return n > k * (k + 2) / 4 ? k + 1 : k;
}

int main() {
    long long a, b;
    int c;
    scanf("%d", &c);
    while (c-- && scanf("%lld %lld", &a, &b))
        printf("%lld\n", result(b - a));
    return 0;
}