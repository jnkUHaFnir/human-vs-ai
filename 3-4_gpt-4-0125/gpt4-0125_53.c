// mocks.c
#include <stdio.h>

void dummy(void) {
    printf("__%s__()\n", __func__);
}

This command generates a shared library named `libmocks.so` containing your mock implementation of `dummy()`.

### Step 3: Use LD_PRELOAD to Run Your Program with the Mock

Now you just need to run your main program with the `LD_PRELOAD` environment variable set to include `libmocks.so`. This tells the dynamic linker to load `libmocks.so` before any other library, including the C standard library, thereby overriding the `dummy()` function with your mocked version.

```bash
LD_PRELOAD=./libmocks.so ./your_program
