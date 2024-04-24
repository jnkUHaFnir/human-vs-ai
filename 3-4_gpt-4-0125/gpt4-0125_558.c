#include <stdio.h>

int menu() {            
    int choice;
    int result;
    do {
        printf("1) Lab 5 (Repetitions).\n2) Lab 10 (Passing 1D-Arrays to functions).\n3) GPA Calculation.\n4) EXIT.\nEnter your choice: ");
        
        // Check the return value of scanf
        result = scanf("%d", &choice);
        
        if (result != 1) {
            printf("Please enter a valid integer.\n");
            // Clearing the input buffer
            while (getchar() != '\n');
            // Reset choice to encourage re-entry of the choice
            choice = 0;
        }
    // Condition to repeat the menu prompt if input was not valid
    } while (result != 1);

    return choice;
}

int main() {
    int choice;

    do {
        choice = menu();
        // Assuming the placeholder function calls commented out below would be defined elsewhere
        if (choice != 4) {
            if (choice == 1) {
                // lab5(choice);
            } else if (choice == 2) {
                // lab10(choice);
            } else if (choice == 3) {
                // lab11(choice);
            } else {
                printf("Invalid choice.\n");
            }
        }
    } while (choice != 4);
    return 0;
}
