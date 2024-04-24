#include <stdio.h>
#include <unistd.h>

int main() {
    // Path to the executable to check
    const char* program = "/usr/bin/Rscript";

    // Check if the program exists and is executable
    if (access(program, X_OK) == 0) {
        printf("Program %s is installed.\n", program);
    } else {
        printf("Program %s is not installed or is not executable.\n", program);
    }

    return 0;
}
