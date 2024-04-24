#include <stdio.h>
#include <string.h>

int main() {
    char firstname[50];
    char lastname[50];

    printf("Please type input file and output file, please type legibly pwease\n");

    fgets(firstname, 50, stdin);
    fgets(lastname, 50, stdin);

    // Remove trailing newline characters
    firstname[strcspn(firstname, "\n")] = '\0';
    lastname[strcspn(lastname, "\n")] = '\0';

    if (firstname[0] == '\0' && lastname[0] == '\0') {
        printf("Error: Both input file and output file are empty.\n");
    } else if (firstname[0] != '\0' && lastname[0] == '\0') {
        printf("Output file is empty.\n");
    } else {
        printf("Files provided.\n");
    }

    return 0;
}
