c
#include <stdio.h>
float fib(float x) {
    if (x <= 2)
        return 1;
    else
        return fib(x - 2) + fib(x - 1);
}
int main() {
    float x, y;
    printf("x= ");
    scanf("%7.2f", &x);
    y = fib(x);
    printf("%7.2f\n", y);
    return 0;
}