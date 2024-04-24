#include <stdio.h>

void mocked_dummy(void)
{
    printf("__%s__()\n", __func__);
}

2. **Dynamic Loading in the Main Program**: Modify your `main` function (without altering `dummy` or `factorial`) to dynamically load `mocked_dummy` and set up a function pointer to the desired mock/real function based on a runtime condition or command line argument.

Here's how you can modify the main program to incorporate dynamic function mocking:

**main.c** (your original program with modifications only outside the restricted sections)
```c
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h> // For dynamic loading

// Declaration for consistency, actual implementation is irrelevant here 
void dummy(void); 

// Updated main to dynamically load a mock or real function
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <0|1> (0 for real, 1 for mock)\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    void *handle;
    void (*func_ptr)(void);
    char *error;

    int use_mock = atoi(argv[1]);
    if (use_mock)
    {
        // Load the mock library and get the mocked_dummy function
        handle = dlopen("./libmock.so", RTLD_LAZY);
        if (!handle)
        {
            fputs(dlerror(), stderr);
            exit(EXIT_FAILURE);
        }

        dlerror(); // Clear any existing error
        
        // Load the symbol
        *(void **)(&func_ptr) = dlsym(handle, "mocked_dummy");
        if ((error = dlerror()) != NULL)
        {
            fputs(error, stderr);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        func_ptr = dummy; // Use the real dummy function
    }
    
    // Assuming you refactor your design to accommodate using the function pointer
    func_ptr(); // Call either dummy or mocked_dummy based on runtime decision

    // Clean up if necessary, e.g., if using a mock
    if (use_mock) dlclose(handle);

    return EXIT_SUCCESS;
}

3. **Execution**: Run the program, specifying whether to use the real `dummy` or `mocked_dummy` via command line argument to dynamically load and use the desired function.

**Remember**: This example simplifies handling and assumes `dummy` and your mock implementation are interchangeable without the need for any additional logic to intercept calls from within other unmodifiable functions (e.g., `factorial`). To fully redirect calls made inside `factorial` to `mocked_dummy` without changing `factorial`, you'd need a different approach, possibly involving more advanced techniques or even modifying the build process to include interposition or function hooking mechanisms.

This solution preserves the original request to not modify specific functions and shows a basic way to achieve dynamic behavior substitution for testing purposes, but it assumes you have the flexibility to adapt the way functions are called based on runtime conditions.
