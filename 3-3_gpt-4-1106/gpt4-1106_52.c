// mocked.c
#include <stdio.h>

__attribute__((visibility("default")))
void dummy(void) {
    printf("__%s__()\n", "mocked_dummy");
}

Once you have this shared library, you then use the LD_PRELOAD environment variable to instruct the dynamic linker to load your shared library before any others when running your test program. This causes the linker to bind calls to `dummy()` to your implementation, `mocked_dummy()`, rather than the original. Here's how you would use it:

```sh
LD_PRELOAD=./libmocked.so ./your_application
