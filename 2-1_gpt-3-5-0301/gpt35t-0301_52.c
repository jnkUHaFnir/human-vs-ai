gcc -shared -o libmocked.so mocked_dummy.c
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void (*dummy_ptr)(void); // pointer to dummy()

int main(int argc, char * argv[])
{
    void * handle = dlopen("./libmocked.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error loading library: %s\n", dlerror());
        return 1;
    }

    void * symbol = dlsym(handle, "mocked_dummy");
    if (!symbol) {
        fprintf(stderr, "Error finding symbol: %s\n", dlerror());
        return 1;
    }

    dummy_ptr = symbol; // set dummy_ptr to mocked_dummy()

    dlclose(handle); // close library handle

    printf("factorial of 5 is = %d\n",factorial(5)); // will call mocked_dummy() instead of dummy()
    return 0;
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
    dummy_ptr(); // call whatever dummy_ptr is pointing to (dummy() or mocked_dummy())
    return fact;
}
