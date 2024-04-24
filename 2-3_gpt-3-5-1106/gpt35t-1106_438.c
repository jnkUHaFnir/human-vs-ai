#include <stdio.h>
#include <stdlib.h>

int main() {
    if (system("which Rscript") == 0) {
        printf("Rscript is installed on this system.\n");
    } else {
        printf("Rscript is not installed on this system.\n");
    }
    return 0;
}
