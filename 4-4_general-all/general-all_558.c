#include <stdio.h>

int menu() {
    int choice;
    while (1) {
        printf("1)Lab 5 ( Repetetions ).\n2)Lab 10 ( Passing 1D-Arrays to functions ).\n3)GPA Calculation.\n4)EXIT.\n\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            // Clear input buffer in case of non-integer input
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Please enter a number.\n");
        } else {
            return choice;
        }
    }
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
