#include <stdio.h>

struct book {
    char name[20];
};

int main() {
    struct book buk[10];
    int i;
    char c; // to capture the newline character
    
    for (i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i + 1);
        scanf(" %19[^\n]%c", buk[i].name, &c); // Read up to 19 characters (leaving space for NULL terminator) and consume the newline character
    }
    
    for (i = 0; i < 3; i++) {
        printf("Book %d name: %s\n", i + 1, buk[i].name);
    }

    return 0;
}
