#include <stdio.h>
#include <stdlib.h>

// Function pointer to dummy implementation
void (*dummy_func)(void) = dummy;

void mocked_dummy(void)
{
    printf("__%s__()\n",__func__);
}

/*---- do not modify ----*/
void dummy(void)
{
    printf("__%s__()\n",__func__);
}

int factorial(int num)
{
    int fact = 1;
    printf("__%s__()\n",__func__);
    while (num > 1)
    {
        fact *= num;
        num--;
    }
    dummy_func(); // Call through function pointer
    return fact;
}
/*---- do not modify ----*/

int main(int argc, char * argv[])
{
    int (*fp)(int) = factorial; // Assign factorial to function pointer
    printf("factorial of 5 is = %d\n",fp(5)); // Call factorial through function pointer

    // Change the function pointer to point to mocked_dummy
    dummy_func = mocked_dummy;
    printf("factorial of 5 is = %d\n",fp(5)); // Now, mocked_dummy will be called instead of dummy

    return 1;
}
