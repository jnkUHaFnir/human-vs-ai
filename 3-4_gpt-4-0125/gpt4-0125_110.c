#include <stdio.h>

struct book {
    char name[20];
};

int main() {
    struct book buk[10];
    int i;
    for(i=0; i<3; i++) {
        printf("Enter name of book %d: ", i+1); // It's good to put a space or newline after the colon for better formatting.
        scanf(" %[^\n]%*c", buk[i].name); // Note: no '&' is used here, and we've changed the format string to handle newline.
    }
    
    // For demonstration, let's print the entered names.
    for(i=0; i<3; i++) {
        printf("Book %d: %s\n", i+1, buk[i].name);
    }
    return 0;
}
