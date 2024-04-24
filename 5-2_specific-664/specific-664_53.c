#include <stdio.h>
#include <stdlib.h>

// Function pointers for dummy() and mocked_dummy()
void (*mock_function)(void) = NULL;
void dummy(void);
void mocked_dummy(void);

// Mock flag to switch between dummy and mocked_dummy
int use_mock = 0;

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
    if (mock_function != NULL) {
        mock_function(); // Call the mock function
    } else {
        dummy(); // Call the original function
    }
    return fact;
}

int main(int argc, char * argv[])
{
    if (argc < 2) {
        printf("Usage: %s <0/1> (0 for original, 1 for mocked)\n", argv[0]);
        return 1;
    }

    use_mock = atoi(argv[1]);
    if (use_mock) {
        mock_function = &mocked_dummy; // Set function pointer to mocked function
    }

    printf("factorial of 5 is = %d\n", factorial(5));

    return 0;
}
