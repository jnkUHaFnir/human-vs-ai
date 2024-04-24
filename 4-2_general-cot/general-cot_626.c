#include <stdio.h>

struct book {
    char name[20];
};

int main() {
    struct book buk[10];
    int i;
    char buffer[20];  // Buffer to consume the newline character

    for (i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i + 1);
        
        // Consume newline character left in the input buffer
        scanf("%*[^\n]");
        scanf("%*c"); // %*c consumes the newline character
        
        // Read the book name
        scanf("%19[^\n]", buffer); // Read up to 19 characters (leave 1 for null terminator)
        
        // Copy the scanned name to the structure's name field
        snprintf(buk[i].name, sizeof(buk[i].name), "%s", buffer);
    }

    // Print the names of the books
    for (i = 0; i < 3; i++) {
        printf("Book %d: %s\n", i + 1, buk[i].name);
    }

    return 0;
}
