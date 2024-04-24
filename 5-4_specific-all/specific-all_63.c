#include <stdio.h>
#include <string.h>

int main() {
    char temp; 
    char variable1[50];
    char variable2[50];

    printf("Enter string 1: "); 
    fgets(variable1, 50, stdin);
    strtok(variable1, "\n");
    
    printf("String 1: %s\n", variable1);

    // Clear input buffer before reading the second string
    while ((temp = getchar()) != '\n' && temp != EOF);

    printf("Enter string 2: ");
    fgets(variable2, 50, stdin);
    strtok(variable2, "\n");
    
    printf("String 2: %s\n", variable2);

    return 0;
}
