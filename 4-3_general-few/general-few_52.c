#include <stdio.h>
#include <stdlib.h>

void mocked_dummy(void)
{
    printf("__%s__()\n", __func__);
}

void dummy(void)
{
    printf("__%s__()\n", __func__);
}

int factorial(int num) 
{
    int fact = 1;
    printf("__%s__()\n", __func__);
    while (num > 1)
    {
        fact *= num;
        num--;
    }
    dummy();
    return fact;
}

int main(int argc, char *argv[])
{
    int (*fp)(int) = factorial; // Initialize function pointer to factorial
    void (*original_dummy)(void) = dummy; // Store original dummy function

    // Replace dummy function with mocked_dummy
    dummy = mocked_dummy;

    printf("factorial of 5 is = %d\n", fp(5)); // This should use mocked_dummy
    printf("factorial of 5 is = %d\n", factorial(5)); // This should use the original dummy

    // Restore original dummy function
    dummy = original_dummy;

    printf("factorial of 5 is = %d\n", factorial(5)); // This should use the original dummy

    return 0;
}
