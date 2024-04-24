#include <stdio.h>
#include <stdlib.h>

void dummy_real(void);
void mocked_dummy(void);

/*---- do not modify ----*/
typedef void (*dummy_function_ptr)(void);
dummy_function_ptr dummy_func = dummy_real;

void dummy_real(void)
{
    printf("__%s__()\n", __func__);
}

void set_dummy(dummy_function_ptr new_dummy) {
    dummy_func = new_dummy;
}
/*---- do not modify ----*/

void mocked_dummy(void)
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
    dummy_func();
    return fact;
}

int main(int argc, char * argv[])
{
    printf("factorial of 5 is = %d\n", factorial(5)); // Calls the real dummy function

    set_dummy(mocked_dummy); // Replace the dummy function with the mocked one
    printf("factorial of 5 is = %d\n", factorial(5)); // Calls the mocked dummy function

    set_dummy(dummy_real); // Switch back to the real dummy function
    printf("factorial of 5 is = %d\n", factorial(5)); // Calls the real dummy function again

    return 1;
}
