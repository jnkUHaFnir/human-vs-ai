#include <stdio.h>

void dummy(void)
{
    printf("__%s__()\n", __func__);
}

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
    
    return fact;
}

int main(int argc, char *argv[])
{
    int (*fp)(int);
    
    if (argc > 1 && atoi(argv[1]))
    {
        fp = &mocked_dummy;
    }
    else
    {
        fp = &dummy;
    }
    
    printf("factorial of 5 using selected function: %d\n", fp(5));
    
    return 0;
}
