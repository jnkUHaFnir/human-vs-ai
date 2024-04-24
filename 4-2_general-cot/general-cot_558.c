#include <stdio.h>

int menu() {
    int choice;
    printf("1) Lab 5 (Repetitions).\n2) Lab 10 (Passing 1D-Arrays to functions).\n3) GPA Calculation.\n4) EXIT.\n\nEnter your choice: ");

    // Validate input
    while (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a valid number: ");
        while (getchar() != '\n'); // Clear input buffer
    }
    
    return choice;
}

int main() {
    int choice;

    do {
        choice = menu();

        if (choice != 4) {
            if (choice == 1)
                printf("Lab 5 selected.\n");
            else if (choice == 2)
                printf("Lab 10 selected.\n");
            else if (choice == 3)
                printf("GPA Calculation selected.\n");
            else
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}
