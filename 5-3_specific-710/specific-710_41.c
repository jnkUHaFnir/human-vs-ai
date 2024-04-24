#include <stdio.h>
#include <string.h>

int main() {
    char fpath[] = "file.exe";
    int binFile = 0;

    // Check if the file ends with ".exe\0" or ".o\0" exactly
    if (strcmp(fpath + strlen(fpath) - 4, ".exe") == 0 || strcmp(fpath + strlen(fpath) - 2, ".o") == 0) {
        binFile = 1;
    }

    if (binFile) {
        printf("Binary file detected.\n");
    } else {
        printf("Not a binary file.\n");
    }

    return 0;
}
