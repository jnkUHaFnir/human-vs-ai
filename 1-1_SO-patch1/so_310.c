c
#include <math.h>
#include <stdio.h>
float fib(float x) {
    if (x > 200)
        return INF;
    if (x <= 2)
        return 1;
    return fib(x - 2) + fib(x - 1);
}
int main() {
    float x, y;
    printf("x= ");
    scanf("%f", &x);
    y = fib(x);
    printf("%7.2f\n", y);
    return 0;
}