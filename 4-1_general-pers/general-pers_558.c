#include <stdio.h>
#include <stdlib.h>

int menu() {
    int choice;
    char input[100]; // Assuming a reasonable maximum size for input

    printf("1)Lab 5 (Repetitions).\n2)Lab 10 (Passing 1D-Arrays to functions).\n3)GPA Calculation.\n4)EXIT.\n\nEnter your choice: ");
    
    // Read input as a string
    fgets(input, sizeof(input), stdin);
    
    // Convert the string to an integer with error checking
    char *endptr;
    choice = strtol(input, &endptr, 10);
    
    // Check if conversion was successful
    if (*endptr != '\n' && *endptr != '\0') {
        printf("Invalid input. Please enter a valid choice.\n");
        return -1; // Return a flag value to signal invalid input
    }
    
    return choice;
}

int main() {
    int choice;

    do {
        choice = menu();
        
        if (choice != 4 && choice != -1) {
            if (choice == 1)
                ; // lab5(choice);
            else if (choice == 2)
                ; // lab10(choice);
            else if (choice == 3)
                ; // lab11(choice);
            else
                printf("Invalid choice\n");
        }

    } while (choice != 4);
    
    return 0;
}
