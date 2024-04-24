#include <stdio.h>

int menu() {
    int choice;
    printf("1)Lab 5 (Repetitions).\n2)Lab 10 (Passing 1D-Arrays to functions).\n3)GPA Calculation.\n4)EXIT.\n\nEnter your choice: ");

    // Keep reading input until a valid integer is entered
    while (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        // Clear input buffer
        while (getchar() != '\n');
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
