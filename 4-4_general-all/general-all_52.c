#include <stdio.h>
#include <stdlib.h>

void (*dummy_func)(void) = dummy;

void mocked_dummy(void)
{
    printf("__%s__()\n", __func__);
}

/*---- do not modify ----*/
void dummy(void)
{
    dummy_func(); // Call the original dummy function or the mocked one based on the function pointer
}
/*---- do not modify ----*/

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

    // Replace dummy function with mocked_dummy at runtime
    dummy_func = mocked_dummy;

    printf("factorial of 5 is = %d\n", fp(5)); // Call factorial function through function pointer
    return 0;
}
