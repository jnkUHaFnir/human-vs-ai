#include <stdio.h>

struct book {
    char name[20];
};

int main(){
    struct book buk[10];
    int i;
    char c; // variable to store the newline character

    for(i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i + 1);
        scanf(" %[^\n]", buk[i].name); // note the space before %[^\n] to consume trailing newline

        // Clear input buffer
        while ((c = getchar()) != '\n' && c != EOF); // consumes all characters until newline or EOF
    }

    // Printing the names
    for(i = 0; i < 3; i++) {
        printf("Name of book %d: %s\n", i + 1, buk[i].name);
    }

    return 0;
}
