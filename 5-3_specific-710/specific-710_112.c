#include <stdio.h>

// Macro to define cleanup function for file handling
#define FILE_RAII(file) \
    FILE* file = NULL; \
    void cleanup_##file(void) { if(file) { fclose(file); } } \
    __attribute__((cleanup(cleanup_##file)))

int main() {
    // Using FILE_RAII macro to ensure file handle is closed when it goes out of scope
    FILE_RAII(fp) = fopen("test.txt", "r");

    if (other_condition) {
        perror("other error occurred!");
        return EXIT_FAILURE;
    }

    // Use fp as you normally would

    return 0;
}
