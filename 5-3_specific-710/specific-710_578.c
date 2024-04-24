#include <stdlib.h>

static void free_envp(char **envp)
{
    if (envp == NULL) {
        // Optionally handle this error case, or just return
        return;
    }

    free(*envp); // Assuming envp points to a single allocated block of memory
    *envp = NULL; // Set the pointer to NULL after freeing

    // Optionally, if envp was dynamically allocated as an array of pointers,
    // you would iterate through and free each element before freeing the array itself
}

int main() {
    char *envp = malloc(sizeof(char) * 10); // Allocate memory for testing

    // Perform operations with envp...

    free_envp(&envp); // Call the function to free memory

    return 0;
}
