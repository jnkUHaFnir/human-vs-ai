#include <stdio.h>
#include <stdlib.h>

struct book {
    char name[20];
};

int main() {
    struct book buk[10];
    int i;
    char c; // variable to store newline character

    for (i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i + 1);

        // Read and discard the newline character left in the input buffer
        while ((c = getchar()) != '\n' && c != EOF);

        // Read the name using %[^\n] to allow spaces in the input
        scanf("%19[^\n]", buk[i].name);
    }

    for (i = 0; i < 3; i++) {
        printf("Name of book %d: %s\n", i + 1, buk[i].name);
    }

    return 0;
}
