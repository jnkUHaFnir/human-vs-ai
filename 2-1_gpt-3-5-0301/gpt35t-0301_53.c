// libmock.c
#include <stdio.h>

void mocked_dummy(void)
{
    printf("__%s__()\n",__func__);
}
gcc -shared -fPIC libmock.c -o libmock.so
int (*dummy_ptr)(int) = dummy;
void *lib_handle = dlopen("libmock.so", RTLD_LAZY);
if (lib_handle) {
    int (*mocked_dummy_ptr)(int) = dlsym(lib_handle, "mocked_dummy");
    if (mocked_dummy_ptr) {
        dummy_ptr = mocked_dummy_ptr;
    }
}
printf("factorial of 5 is = %d\n",dummy_ptr(5));
