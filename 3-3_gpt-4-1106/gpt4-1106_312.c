#include <stdio.h>

struct book {
    char name[20];
};

int main() {
    struct book buk[10];
    int i;
    
    for (i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i+1);
        // Consume any leftover newline character in the input buffer
        // Including this even before the first scanf clears any previous input
        // that was left in the buffer, such as by the program that started this one (e.g., a shell)
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }

        // Using %[^\n] and passing buk[i].name without & because it's already an address
        scanf("%19[^\n]", buk[i].name);
    }

    // Print the book names to verify it worked
    for (i = 0; i < 3; i++) {
        printf("Book %d: %s\n", i+1, buk[i].name);
    }

    return 0;
}
