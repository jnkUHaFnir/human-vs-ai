#include <unistd.h>

int main() {
    if (access("/usr/bin/Rscript", X_OK) == 0) {
        printf("Rscript is installed on this system.\n");
    } else {
        printf("Rscript is not installed on this system.\n");
    }

    return 0;
}
