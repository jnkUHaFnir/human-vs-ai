#include <stdio.h>

struct book {
    char name[20];
};

int main() {
    struct book buk[10];
    int i;
    for(i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i + 1);
        // Use a space before %[^\n] to consume any leading whitespace characters
        scanf(" %[^\n]", buk[i].name);
    }

    // Printing the entered names for verification
    for(i = 0; i < 3; i++) {
        printf("Name of book %d: %s\n", i + 1, buk[i].name);
    }

    return 0;
}
