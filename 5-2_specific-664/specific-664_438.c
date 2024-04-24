#include <stdio.h>
#include <unistd.h>

int main() {
    if(access("/usr/bin/Rscript", X_OK) == 0) {
        printf("Rscript is installed on the system.\n");
    } else {
        printf("Rscript is not installed on the system.\n");
    }

    return 0;
}
