#include <stdlib.h>
#include <stdio.h>

int main() {
    int result;

    // Use the 'which' command to find the program
    result = system("which Rscript > /dev/null 2>&1");

    if (result == 0) {
        // If the return value of the 'which' command is 0, Rscript was found
        printf("Rscript is installed\n");
    } else {
        // If the return value is not 0, Rscript was not found
        printf("Rscript is not installed\n");
    }

    return 0;
}
