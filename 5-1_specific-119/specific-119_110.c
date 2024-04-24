#include <stdio.h>

struct book {
    char name[20];
};

int main() {
    struct book buk[10];
    int i;
    
    for (i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i + 1);
        scanf(" %[^\n]", buk[i].name); // Notice the space before %[^\n]
        
        // Clear the input buffer
        while (getchar() != '\n'); // Consume the newline character
    }

    // Print the entered names
    for (i = 0; i < 3; i++) {
        printf("Book %d: %s\n", i + 1, buk[i].name);
    }

    return 0;
}
