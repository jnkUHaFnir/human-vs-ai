#include <stdio.h>
#include <stdlib.h>

int menu() {
    int choice;
    printf("1)Lab 5 ( Repetitions ).\n2)Lab 10 ( Passing 1D-Arrays to functions ).\n3)GPA Calculation.\n4)EXIT.\n\nEnter your choice: ");
    
    // Read input as a string first
    char input[10];
    fgets(input, sizeof(input), stdin);

    // Convert the input string to an integer
    if (sscanf(input, "%d", &choice) != 1) {
        choice = -1; // Set an invalid choice if input cannot be converted to an integer
    }

    return choice;
}

int main() {
    int choice;

    do {
        choice = menu();

        switch (choice) {
            case 1:
                //lab5(choice);
                break;
            case 2:
                //lab10(choice);
                break;
            case 3:
                //lab11(choice);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}
