#include <stdio.h>
#include <stdlib.h>

void mocked_dummy(void)
{
    printf("__%s__()\n", __func__);
}

// Function pointer to dummy function
void (*dummy_function)(void) = dummy;

void dummy()
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
    // Call through function pointer, so that it can be changed at runtime
    (*dummy_function)();
    return fact;
}

int main(int argc, char *argv[])
{
    // Use mocked_dummy function as the dummy function
    dummy_function = mocked_dummy;

    printf("factorial of 5 is = %d\n", factorial(5));

    // Reset function pointer to original dummy function
    dummy_function = dummy;
    printf("factorial of 5 is = %d\n", factorial(5));

    return 0;
}
