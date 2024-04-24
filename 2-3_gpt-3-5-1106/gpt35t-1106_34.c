#include <stdio.h>
#include <string.h>

int main() {
    char firstname[50];
    char lastname[50];

    printf("Please type your first and last name: ");
    scanf("%s %s", firstname, lastname);

    if (strlen(firstname) == 0 || strlen(lastname) == 0) {
        printf("Error: Empty input.");
    } else if (strcmp(firstname, lastname) == 0) {
        printf("Error: First and last name are the same.");
    } else {
        printf("Names entered: %s %s", firstname, lastname);
    }

    return 0;
}
