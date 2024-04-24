#include <stdio.h>

int menu() {
    int choice;
    int validInput;
    
    do {
        printf("1)Lab 5 (Repetitions).\n2)Lab 10 (Passing 1D-Arrays to functions).\n3)GPA Calculation.\n4)EXIT.\n\nEnter your choice: ");
        
        validInput = scanf("%d", &choice);
        
        if (validInput != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while (fgetc(stdin) != '\n'); // Clear input buffer
        }
    } while (validInput != 1);

    return choice;
}

int main() {
    int choice;

    do {
        choice = menu();

        if (choice != 4) {
            if (choice == 1) {
                // lab5(choice);
            }
            else if (choice == 2) {
                // lab10(choice);
            }
            else if (choice == 3) {
                // lab11(choice);
            }
            else {
                printf("Invalid choice. Please try again.\n");
            }
        }

    } while (choice != 4);

    return 0;
}
