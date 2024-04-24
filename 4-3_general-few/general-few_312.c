#include <stdio.h>

#define MAX_LENGTH 20

struct book {
    char name[MAX_LENGTH];
};

int main() {
    struct book buk[10];
    int i;

    for (i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i+1);
        // Change the format specifier to %[^\n] to read input until newline character
        // Remove the 's' after %[^\n]
        scanf(" %[^\n]", buk[i].name); // Notice the space before % to consume the newline left in the buffer

        // Consume the newline character left in the buffer after the input
        while (getchar() != '\n');

    }

    // Printing the entered names for verification
    for (i = 0; i < 3; i++) {
        printf("Name of book %d: %s\n", i+1, buk[i].name);
    }

    return 0;
}
