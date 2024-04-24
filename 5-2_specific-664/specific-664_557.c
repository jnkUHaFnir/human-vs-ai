#include <stdio.h>
#include <stdlib.h>

int menu() {
    int choice;
    char input[10]; // Assuming input is not more than 10 characters

    printf("1)Lab 5 ( Repetitions ).\n2)Lab 10 ( Passing 1D-Arrays to functions ).\n3)GPA Calculation.\n4)EXIT.\n\nEnter your choice: ");
    
    // Read input as a string
    fgets(input, sizeof(input), stdin);

    // Convert string to integer
    choice = strtol(input, NULL, 10);

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
