#include <stdio.h>

float fib(float x) {
    float a = 0, b = 1, temp;
    if (x == 0)
        return a;
    if (x == 1)
        return b;
    for (int i = 2; i <= x; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    float x, y;
    printf("x= ");
    scanf("%f", &x);
    y = fib(x);
    printf("%7.2f", y);
    return 0;
}
