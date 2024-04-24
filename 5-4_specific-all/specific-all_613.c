#include <stdio.h>

// x86 thunk function
int thunk_x86(void (*fn)(void), int arg1, int arg2, int arg3) {
    int ret;
    __asm__(
        "pushl %3\n"
        "pushl %2\n"
        "pushl %1\n"
        "call *%0\n"
        "add $12, %%esp\n"
        : "=a" (ret)
        : "r" (arg1), "r" (arg2), "r" (arg3), "a" (fn)
    );
    return ret;
}

// x64 thunk function
long thunk_x64(void (*fn)(void), long arg1, long arg2, long arg3) {
    long ret;
    __asm__(
        "mov %1, %%rdi\n"
        "mov %2, %%rsi\n"
        "mov %3, %%rdx\n"
        "call *%0\n"
        : "=a" (ret)
        : "r" (arg1), "r" (arg2), "r" (arg3), "a" (fn)
    );
    return ret;
}

// Example target function
void example_function(int a, int b, int c) {
    printf("Arguments: %d, %d, %d\n", a, b, c);
}

int main() {
    // Thunk the example function
    thunk_x86((void (*)())example_function, 1, 2, 3);
    thunk_x64((void (*)())example_function, 4, 5, 6);

    return 0;
}
