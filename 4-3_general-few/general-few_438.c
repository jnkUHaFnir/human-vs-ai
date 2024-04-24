#include <stdio.h>
#include <stdlib.h>

int main() {
    if(system("which Rscript") == 0) {
        printf("'Rscript' is installed.\n");
    } else {
        printf("'Rscript' is not installed.\n");
    }
    
    return 0;
}
