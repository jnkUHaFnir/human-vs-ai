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

// Set up function pointer to point to the real dummy function by default
void (*dummy_func)(void) = dummy;

int factorial(int num)
{
    int fact = 1;
    printf("__%s__()\n", __func__);
    while (num > 1)
    {
        fact *= num;
        num--;
    }
    dummy_func(); // Call through the function pointer
    return fact;
}

int main(int argc, char *argv[])
{
    // Check if we should mock the dummy function
    if (argc > 1 && atoi(argv[1]) == 1)
    {
        dummy_func = mocked_dummy; // Set function pointer to mocked_dummy
    }

    printf("factorial of 5 is = %d\n", factorial(5));

    // Reset function pointer to point to real dummy function for subsequent calls
    dummy_func = dummy;

    printf("factorial of 5 is = %d\n", factorial(5));

    return 0;
}
