#include <stdio.h>
#include <stdlib.h>

void mocked_dummy(void)
{
    printf("__%s__()\n", __func__);
}

/* Function pointer for dummy function */
void (*dummy_ptr)(void) = dummy;

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
    dummy_ptr(); // Call through function pointer
    return fact;
}

int main(int argc, char *argv[])
{
    // Change the function pointer to point to mocked_dummy
    dummy_ptr = mocked_dummy;

    printf("factorial of 5 is = %d\n", factorial(5));

    // Change back to dummy for normal execution
    dummy_ptr = dummy;
    printf("factorial of 5 is = %d\n", factorial(5));

    return 0;
}
