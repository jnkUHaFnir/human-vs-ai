#include <stdio.h>
#include <unistd.h>

int main() {
    if (access("/usr/bin/Rscript", F_OK) != -1) {
        printf("Rscript is installed in /usr/bin/Rscript\n");
    } else {
        printf("Rscript is not installed\n");
    }

    return 0;
}
