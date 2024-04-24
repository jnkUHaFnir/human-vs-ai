#include <stdio.h>

char menu() { // Prints the main menu of labs ///
    char choice;
    printf("1) Lab 5 (Repetitions).\n"
           "2) Lab 10 (Passing 1D-Arrays to functions).\n"
           "3) GPA Calculation.\n"
           "4) EXIT.\n\n"
           "Enter your choice: ");
    scanf(" %c", &choice); //added space to remove the newline character
    while (getchar() != '\n')
        ; // Ignore any remaining characters in the input buffer
    return choice;
}

int main() {
    char choice;

    do {
        choice = menu();
        switch (choice) {
            case '1':
                // lab5();
                break;
            case '2':
                // lab10();
                break;
            case '3':
                // lab11();
                break;
            case '4':
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != '4');
    return 0;
}
