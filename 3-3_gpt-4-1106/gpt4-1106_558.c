#include <stdio.h>
#include <stdlib.h> // For the system("cls") or system("clear") function

int menu() {            // prints the main menu of labs
    int choice;
    int status; // to store the return value of scanf
    do {
        printf("1)Lab 5 ( Repetitions ).\n");
        printf("2)Lab 10 ( Passing 1D-Arrays to functions ).\n");
        printf("3)GPA Calculation.\n");
        printf("4)EXIT.\n\n");
        printf("Enter your choice: ");

        status = scanf("%d", &choice);

        // Check if scanf read an integer successfully
        if(status != 1) {
            printf("Invalid input. Please enter a number (1-4).\n");
            // Clear the input buffer:
            while (getchar() != '\n');
            // An optional feature would be to clear the screen:
            // system("cls"); // For Windows
            // system("clear"); // For Unix/Linux
        }

    } while (status != 1); // Repeat if input was not an integer

    return choice;
}

int main() {
    int choice;

    do {
        choice = menu();

        if (choice != 4) {
            switch(choice) {
                case 1:
                    //lab5(choice);
                    break;
                case 2:
                    //lab10(choice);
                    break;
                case 3:
                    //lab11(choice);
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
            }
        }

    } while (choice != 4);

    printf("Exiting program.\n");
    return 0;
}
