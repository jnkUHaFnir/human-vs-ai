#include <stdio.h>
#include <stdlib.h>

// Function pointer type for the dummy function
typedef void (*dummy_func_t)(void);

// Original dummy function
void dummy(void)
{
    printf("__%s__()\n", __func__);
}

// Mocked dummy function
void mocked_dummy(void)
{
    printf("__%s__()\n", __func__);
}

int factorial(int num, dummy_func_t dummy_func)
{
    int fact = 1;
    printf("__%s__()\n", __func__);
    while (num > 1)
    {
        fact *= num;
        num--;
    }
    
    // Call the provided dummy function
    dummy_func();
    
    return fact;
}

int main(int argc, char *argv[])
{
    // Initially set the function pointer to dummy()
    dummy_func_t fp = dummy;
    
    printf("factorial of 5 with dummy() is = %d\n", factorial(5, fp));

    // Switch function pointer to mocked_dummy()
    fp = mocked_dummy;
    
    printf("factorial of 5 with mocked_dummy() is = %d\n", factorial(5, fp));

    return 0;
}
