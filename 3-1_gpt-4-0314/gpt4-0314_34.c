#include <stdio.h>
#include <string.h>

int main() {
    char firstname[50];
    char lastname[50];

    printf("Please type input file, and output file please type legibly\n");
    
    fgets(firstname, sizeof(firstname), stdin);
    fgets(lastname, sizeof(lastname), stdin);

    // Remove the newline characters from the inputs
    firstname[strcspn(firstname, "\n")] = 0;
    lastname[strcspn(lastname, "\n")] = 0;

    if (strcmp(firstname, lastname) == 0) {
        printf("Error: Cannot open input file %s.\n", firstname);
    } else {
        printf("file found\n");
    }

    return 0;
}
