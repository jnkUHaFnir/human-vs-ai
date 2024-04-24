c
#include <math.h>
#include <stdio.h>
float fib(float x) {
    if (x > 200)
        return INFINITY;
    if (x <= 2)
        return 1;
    return fib(x - 2) + fib(x - 1);
}
int main() {
    float x, y;
    printf("x= ");
    if (scanf("%f", &x) == 1) {
        y = fib(x);
        printf("%7.2f\n", y);
    } else {
        printf("invalid input\n");
    }
    return 0;
}