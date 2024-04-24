#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int menu() {// prints the main menu of labs///
    int choice;
    char input[100]; // Assuming input will not exceed 100 characters

    printf("1)Lab 5 ( Repetetions ).\n2)Lab 10 ( Passing 1D-Arrays to functions ).\n3)GPA Calculation.\n4)EXIT.\n\nEnter your choice: ");
    fgets(input, sizeof(input), stdin); // Read as a string

    // Check if the input is a valid integer
    if (sscanf(input, "%d", &choice) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return menu(); // Recursively call menu() until a valid integer is entered
    }

    return choice;
}

int main() {
    int choice;

    do {
        choice = menu();

        if (choice != 4) {
            if (choice == 1)
                //lab5(choice);
            else if (choice == 2)
                //lab10(choice);
            else if (choice == 3)
                //lab11(choice);
            else
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}
