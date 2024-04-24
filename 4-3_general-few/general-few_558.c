#include <stdio.h>

int menu() {
    int choice;
    printf("1)Lab 5 (Repetitions).\n2)Lab 10 (Passing 1D-Arrays to functions).\n3)GPA Calculation.\n4)EXIT.\n\nEnter your choice: ");
    while (scanf("%d", &choice) != 1) {  // Keep asking for input until an integer is entered
        printf("Invalid input. Please enter an integer.\n");
        while (getchar() != '\n');  // Clear input buffer
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
