#include <stdio.h>
#include <stdbool.h>

void mocked_dummy(void)
{
    printf("__%s__()\n",__func__);
}

/*---- do not modify ----*/
void dummy(void)
{
    printf("__%s__()\n",__func__);
}

// Function pointer type and dummy_ptr to point to either dummy or mocked_dummy func
typedef void (*dummy_func_t)(void);
dummy_func_t dummy_ptr = &dummy;

void set_dummy_ptr(bool use_mock)
{
    dummy_ptr = use_mock ? &mocked_dummy : &dummy;
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
    dummy_ptr(); // Call selected function (dummy or mocked_dummy) through function pointer
    return fact;
}
/*---- do not modify ----*/

int main(int argc, char * argv[])
{
    // Run normal code
    set_dummy_ptr(false);
    printf("factorial of 5 is = %d\n",factorial(5));
    
    // Run test code using mocked_dummy
    set_dummy_ptr(true);
    printf("factorial of 5 is = %d\n",factorial(5));
    
    return 0;
}
