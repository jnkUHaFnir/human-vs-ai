#include <stdio.h>

int fib(int x) {
    if (x <= 1)
        return x;
    
    int prev = 0;
    int current = 1;
    int next;
    
    for (int i = 2; i <= x; i++) {
        next = prev + current;
        prev = current;
        current = next;
    }
    
    return current;
}

int main() {
    int x, y;
    printf("x = ");
    scanf("%d", &x);
    
    y = fib(x);
    
    printf("Fibonacci(%d) = %d\n", x, y);
    
    return 0;
}
