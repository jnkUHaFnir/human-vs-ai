#include <stdio.h>
#include <stdlib.h>

int menu() {
    int choice;
    printf("1)Lab 5 (Repetitions).\n2)Lab 10 (Passing 1D-Arrays to functions).\n3)GPA Calculation.\n4)EXIT.\n\nEnter your choice: ");

    if (scanf("%d", &choice) != 1) { // Check if the input is not an integer
        printf("Invalid input. Please enter a number.\n");
        // Clear input buffer
        while (getchar() != '\n');
        choice = -1; // Set choice to a default value (-1 in this case)
    }

    return choice;
}

int main() {
    int choice;

    do {
        choice = menu();

        if (choice != 4 && choice != -1) {
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
