#include <stdio.h>
#include <stdlib.h>

void dummy(void)
{
    printf("__%s__()\n",__func__);
}

void mocked_dummy(void)
{
    printf("__%s__()\n",__func__);
}

/* Function pointer for indirection */
void (*dummy_function_pointer)(void) = dummy;

/* New wrapper function that uses the function pointer */
void call_dummy(void) {
    dummy_function_pointer();
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
    call_dummy();
    return fact;
}

void set_mock_function(void (*mock_function)(void)) {
    dummy_function_pointer = mock_function;
}

int main(int argc, char *argv[])
{
    printf("factorial of 5 is = %d\n", factorial(5));
    
    /* Set the mock function before the test */
    set_mock_function(mocked_dummy);
    
    printf("factorial of 5 with mock is = %d\n", factorial(5));
    
    return 0;
}
