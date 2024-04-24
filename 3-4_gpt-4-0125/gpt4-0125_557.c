#include <stdio.h>
#include <stdlib.h> // for atoi()

int menu() {
    char input[10]; // Assuming the input will not be longer than 9 characters
    int choice;
    printf("1)Lab 5 ( Repetitions ).\n2)Lab 10 ( Passing 1D-Arrays to functions ).\n3)GPA Calculation.\n4)EXIT.\n\nEnter your choice: ");
    
    // Read input as string
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Attempt to convert string to integer
        choice = atoi(input);
        // atoi returns 0 if the conversion fails, which isn't a valid menu option
        return choice;
    } else {
        // fgets failed to read, probably should handle this case too but for simplicity returning 0
        return 0;
    }
}

int main() {
    int choice;

    do {
        choice = menu();
        if (choice != 4) {
            if (choice == 1)
                printf("Lab 5 (Repetitions).\n"); // Placeholder for lab5(choice);
            else if (choice == 2)
                printf("Lab 10 (Passing 1D-Arrays to functions).\n"); // Placeholder for lab10(choice);
            else if (choice == 3)
                printf("GPA Calculation.\n"); // Placeholder for lab11(choice);
            else
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}
