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

int main(int argc, char * argv[])
{
    int (*fp)(int);

    if (argc > 1 && atoi(argv[1]) == 1) {
        fp = mocked_dummy;
    } else {
        fp = dummy;
    }

    printf("factorial of 5 is = %d\n", factorial(5));

    // Switch to using mocked_dummy() at runtime
    printf("Switching to mocked_dummy...\n");
    printf("factorial of 5 is = %d\n", fp(5));

    return 0;
}
