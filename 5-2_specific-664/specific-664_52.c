#include <stdio.h>

// Function pointer type matching the signature of dummy function
typedef void (*DummyFuncPtr)(void);

// Global flag to indicate whether to use the original dummy function or the mocked one
int useMockedDummy = 0;

void mocked_dummy(void)
{
    printf("__%s__()\n", __func__);
}

// Original dummy function
void dummy(void)
{
    if (useMockedDummy) {
        mocked_dummy();
    } else {
        printf("__%s__()\n", __func__);
    }
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

int main()
{
    DummyFuncPtr originalDummy = &dummy;

    // Set the function pointer to the mocked function
    void (*fp)(void) = &mocked_dummy;

    // Set the global flag to use the mocked function
    useMockedDummy = 1;
    factorial(5);

    // Reset the global flag to use the original function
    useMockedDummy = 0;
    factorial(5);

    return 0;
}
