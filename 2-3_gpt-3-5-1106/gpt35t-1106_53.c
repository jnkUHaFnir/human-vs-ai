void (*dummy_ptr)(void) = &dummy;
int factorial(int num) 
{
    // ...
    while (num > 1)
    {
        fact *= num;
        num--;
    }
    (*dummy_ptr)();
    return fact;
}
int main(int argc, char * argv[])
{
    dummy_ptr = &mocked_dummy;
    // ...
}
