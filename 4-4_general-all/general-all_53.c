#include <stdio.h>
#include <stdlib.h>

// Function pointer to point to the actual function
void (*dummy_func)(void) = dummy;

void mocked_dummy(void)
{
    printf("__%s__()\n", __func__);
}

/*---- do not modify ----*/
void dummy(void)
{
    dummy_func();
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
    // Conditionally set the function pointer to the mocked function at runtime
    if (argc > 2 && atoi(argv[2]) == 1) {
        dummy_func = mocked_dummy;
    }

    int (*fp)(int) = factorial; // Point fp to the factorial function
    printf("factorial of 5 is = %d\n", fp(5));

    return 0;
}
