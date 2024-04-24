#include <stdio.h>
#include <stdlib.h>

int menu() {
    char input[100];  // Buffer to read user input
    int choice;

    printf("1)Lab 5 (Repetitions).\n2)Lab 10 (Passing 1D-Arrays to functions).\n3)GPA Calculation.\n4)EXIT.\n\nEnter your choice: ");
    
    // Read input as a string
    fgets(input, sizeof(input), stdin);

    // Convert the input to an integer
    choice = atoi(input);
    
    if(choice == 0 && input[0] != '0') {
        // Check if conversion failed
        choice = -1; // Set choice to an invalid value
    }

    return choice;
}

int main() {
    int choice;

    do {
        choice = menu();

        if (choice != 4) {
            if (choice == 1) {
                //lab5(choice);
            }
            else if (choice == 2) {
                //lab10(choice);
            }
            else if (choice == 3) {
                //lab11(choice);
            }
            else {
                printf("Invalid choice\n");
            }
        }

    } while (choice != 4);

    return 0;
}
