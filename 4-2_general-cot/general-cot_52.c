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
    dummy(); // This call will be replaced with mocked_dummy
    return fact;
}

int main(int argc, char *argv[])
{
    void (*original_dummy)(void) = dummy; // Store the original dummy function

    // Change the dummy function to point to mocked_dummy
    void (*fptr)(void) = mocked_dummy;
    dummy = fptr;

    printf("factorial of 5 is = %d\n", factorial(5));

    // Restore the original dummy function
    dummy = original_dummy;

    printf("factorial of 5 is = %d\n", factorial(5));

    return 0;
}
