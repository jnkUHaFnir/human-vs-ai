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
    return fact;
}

int main(int argc, char *argv[])
{
    int (*fp)(int) = &dummy; // Initialize function pointer to dummy by default
    printf("fp = %p\n", (void *)fp);

    // Check if a command line argument is provided to switch between functions
    if (argc > 1 && atoi(argv[1]) == 1)
    {
        fp = &mocked_dummy; // Point function pointer to mocked_dummy if argument is provided
    }

    printf("factorial of 5 is = %d\n", factorial(5)); // Call factorial normally
    printf("factorial of 5 is = %d\n", fp(5)); // Call either dummy() or mocked_dummy() based on function pointer

    return 0;
}
