#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

struct book { 
    char name[MAX_NAME_LENGTH];
};

int main() {
    struct book buk[10];
    int i;

    for(i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i+1);
        fgets(buk[i].name, sizeof(buk[i].name), stdin);
        
        // Remove the newline character from the input
        buk[i].name[strcspn(buk[i].name, "\n")] = '\0';
    }

    // Display the input book names
    for(i = 0; i < 3; i++) {
        printf("Book %d: %s\n", i+1, buk[i].name);
    }

    return 0;
}
