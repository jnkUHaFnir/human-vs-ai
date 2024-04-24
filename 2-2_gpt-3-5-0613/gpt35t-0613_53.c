#include <stdio.h>

void mocked_dummy(void)
{
    printf("__%s__()\n", __func__);
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
    }
    dummy();
    return fact;
}
/*---- do not modify ----*/

int main()
{
    int (*old_dummy)() = dummy;
    dummy = mocked_dummy;
    printf("factorial of 5 is = %d\n", factorial(5));
    dummy = old_dummy;
    printf("factorial of 5 is = %d\n", factorial(5));
    return 0;
}
