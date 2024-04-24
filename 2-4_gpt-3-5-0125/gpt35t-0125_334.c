#include <stdio.h>

int main() {
    FILE *spTemp;
    char path[100] = "/home/chronos/user/Downloads/grades.txt";
    spTemp = fopen(path, "r");

    if (spTemp == NULL) {
        printf("Error opening file");
        return 1;
    }

    // Read and process the file here

    fclose(spTemp);
    return 0;
}
