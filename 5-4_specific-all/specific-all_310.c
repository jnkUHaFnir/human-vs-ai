#include <stdio.h>

unsigned long long fib(unsigned long long x) {
    if (x == 0)
        return 0;
    else if (x == 1)
        return 1;

    unsigned long long a = 0, b = 1, c;
    for (unsigned long long i = 2; i <= x; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    unsigned long long x, y;
    printf("x= ");
    if (scanf("%llu", &x) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    y = fib(x);
    printf("%llu\n", y);

    return 0;
}
