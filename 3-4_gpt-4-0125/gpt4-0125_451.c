#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

char global[MAX_LENGTH]; // allocate space for the string

int main() {
    printf("Please Enter Text: \n");
    fgets(global, sizeof(global), stdin); // read a line, including spaces
    
    // Remove newline character if present
    global[strcspn(global, "\n")] = '\0';

    printf("%s\n", global);

    return 0;
}
