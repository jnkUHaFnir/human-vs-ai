#include <stdio.h>
#include <stdlib.h>

int menu() {
    char input[100];
    int choice;
    char *endptr;

    printf("1)Lab 5 (Repetetitions).\n2)Lab 10 (Passing 1D-Arrays to functions).\n3)GPA Calculation.\n4)EXIT.\n\nEnter your choice: ");
    
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        exit(1);
    }

    choice = strtol(input, &endptr, 10);

    if (endptr == input || *endptr != '\n') {
        printf("Invalid input. Please enter a valid integer.\n");
        return -1; // return a special value to indicate error
    }

    return choice;
}

int main() {
    int choice;

    do {
        choice = menu();

        if (choice != -1) {
            switch (choice) {
                case 1:
                    // lab5(choice);
                    break;
                case 2:
                    // lab10(choice);
                    break;
                case 3:
                    // lab11(choice);
                    break;
                case 4:
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
            }
        }

    } while (choice != 4);

    return 0;
}
