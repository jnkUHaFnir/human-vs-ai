#include <stdio.h>

struct book {
    char name[20];
};

int main() {
    struct book buk[10];
    int i;
    for (i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i+1);
        
        // The following line reads any potential newline character
        scanf(" %[^\n]", buk[i].name);
    }
    
    // Print the book names to verify the input
    for (i = 0; i < 3; i++) {
        printf("Book %d: %s\n", i+1, buk[i].name);
    }
    
    return 0;
}
