#include <stdio.h>
#include <stdlib.h>

void mocked_dummy(void)
{
    printf("__%s__()\n", __func__);
}

/* Define a function pointer type that matches the signature of dummy */
typedef void (*dummy_function)(void);

/* Define and initialize a function pointer to dummy function */
dummy_function dummy_ptr = dummy;

/* Replace dummy function with mocked_dummy */
void replace_dummy_with_mocked() {
    dummy_ptr = mocked_dummy;
}

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
        // Call the function through the function pointer
        dummy_ptr();
    }
    return fact;
}
/*---- do not modify ----*/

int main(int argc, char *argv[])
{
    // Using function pointer for dynamic function call
    printf("factorial of 5 is = %d\n", factorial(5));

    // Replace dummy with mocked_dummy at runtime
    replace_dummy_with_mocked();

    // Call factorial again to see the mocked_dummy in action
    printf("factorial of 5 is = %d\n", factorial(5));

    return 0;
}
