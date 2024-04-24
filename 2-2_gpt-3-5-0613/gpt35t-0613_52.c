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

int factorial(int num, void (*dummy_func)(void))
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
/*---- do not modify ----*/

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <mode>\n", argv[0]);
        return 1;
    }

    void (*dummy_func)(void);

    if (atoi(argv[1]) == 0)
    {
        dummy_func = dummy;
    }
    else
    {
        dummy_func = mocked_dummy;
    }

    printf("factorial of 5 is = %d\n", factorial(5, dummy_func));
    return 0;
}
