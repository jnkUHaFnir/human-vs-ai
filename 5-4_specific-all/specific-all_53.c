#include <stdio.h>
#include <stdlib.h>

void mocked_dummy(void)
{
    printf("__%s__()\n", __func__);
}

/*---- do not modify ----*/
void dummy(void)
{
    printf("__%s__()\n", __func__);
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
    int (*fp)(int);
    int useMocked = 1; // Set this to 1 to use mocked_dummy, 0 to use dummy

    if (useMocked)
    {
        fp = mocked_dummy;
    }
    else
    {
        fp = dummy;
    }

    printf("factorial of 5 is = %d\n", fp(5));
    printf("factorial of 5 is = %d\n", factorial(5));
    return 0;
}
