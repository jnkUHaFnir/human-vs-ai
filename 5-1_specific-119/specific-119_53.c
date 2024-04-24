#include <stdio.h>
#include <stdlib.h>

void mocked_dummy(void)
{
    printf("__%s__()\n", __func__);
}

/* Function pointer for dummy function */
void (*dummy_func)(void) = dummy;

/*---- do not modify ----*/
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
    dummy_func(); // Call the dummy function via function pointer
    return fact;
}
/*---- do not modify ----*/

int main(int argc, char *argv[])
{
    // Assign mocked_dummy function to the function pointer
    dummy_func = mocked_dummy;

    printf("factorial of 5 is = %d\n", factorial(5));

    return 1;
}
