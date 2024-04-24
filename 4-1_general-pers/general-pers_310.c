#include <stdio.h>

float fib(float x) {
    if (x <= 1)
        return x;

    float a = 0, b = 1, temp;
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
    printf("%.2f\n", y);
    return 0;
}
