#include <stdio.h>
#include <string.h>

struct book {
    char name[20];
};

int main(){
    struct book buk[10];
    int i;
    char buffer[100]; // Buffer for reading input
    
    for(i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i+1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline if present
        strncpy(buk[i].name, buffer, sizeof(buk[i].name)); // Copy input to structure member
    }
    
    // Output the names
    for(i = 0; i < 3; i++) {
        printf("Book %d: %s\n", i+1, buk[i].name);
    }

    return 0;
}
