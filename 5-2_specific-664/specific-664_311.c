#include <stdio.h>

double fib(int x) {
    if (x == 0)
        return 0;
    else if (x == 1)
        return 1;

    double prev = 0;
    double curr = 1;

    for (int i = 2; i <= x; i++) {
        double next = prev + curr;
        prev = curr;
        curr = next;
    }

    return curr;
}

int main() {
    int x;
    double y;
    printf("x= ");
    scanf("%d", &x);
    y = fib(x);
    printf("%.0f\n", y);
    return 0;
}
