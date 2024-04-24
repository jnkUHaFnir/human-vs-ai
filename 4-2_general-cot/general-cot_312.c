#include <stdio.h>

struct book {
    char name[20];
};

int main() { // Changed void to int for main function
    struct book buk[10];
    int i;
    char c; // Variable to clear input buffer

    for (i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i + 1);
        scanf(" %[^\n]", buk[i].name); // Added space before %[^\n] to consume any leading whitespace

        // Clear input buffer
        while ((c = getchar()) != '\n' && c != EOF);

    }

    for (i = 0; i < 3; i++) {
        printf("Book %d: %s\n", i + 1, buk[i].name);
    }

    return 0;
}
