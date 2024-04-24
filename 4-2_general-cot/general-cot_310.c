#include <stdio.h>

float fib(float x) {
    if (x == 0)
        return 0;
    else if (x == 1)
        return 1;

    float prev = 0, current = 1, next;
    for (int i = 2; i <= x; ++i) {
        next = prev + current;
        prev = current;
        current = next;
    }
    return current;
}

int main() {
    float x, y;
    printf("x= ");
    scanf("%f", &x); // Use "%f" to read a float

    y = fib(x);
    printf("%0.2f\n", y); // Use "%0.2f" to print a float

    return 0;
}
