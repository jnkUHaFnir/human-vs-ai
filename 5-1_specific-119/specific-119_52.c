#include <stdio.h>

void mocked_dummy(void) {
    printf("__%s__()\n", __func__);
}

void dummy(void) {
    printf("__%s__()\n", __func__);
}

int factorial(int num) {
    int fact = 1;
    printf("__%s__()\n", __func__);
    while (num > 1) {
        fact *= num;
        num--;
    }
    return fact;
}

int main(int argc, char *argv[]) {
    int (*fp)(int) = &dummy;  // Initialize function pointer with dummy function
    printf("fp = %p\n", (void *) fp);

    printf("factorial of 5 is = %d\n", fp(5));  // Call via function pointer
    printf("factorial of 5 is = %d\n", factorial(5));

    // Update function pointer to point to mocked_dummy
    fp = &mocked_dummy;

    printf("After mocking:\n");
    printf("factorial of 5 is = %d\n", fp(5));  // Call mocked function via function pointer

    return 0;
}
