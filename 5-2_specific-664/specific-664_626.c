#include <stdio.h>

struct book { 
    char name[20];
};

int main() {
    struct book buk[10];
    int i;
    char buffer[20]; // buffer to clear input buffer

    for (i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i + 1);
        scanf("%[^\n]%*c", buk[i].name); // %*c to consume newline character
        
        // Clear input buffer
        while (getchar() != '\n');
    }

    // Display the entered names
    for (i = 0; i < 3; i++) {
        printf("Book %d: %s\n", i + 1, buk[i].name);
    }

    return 0;
}
