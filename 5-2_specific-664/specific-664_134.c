#include <stdio.h>

int validate(int low, int high);

int main ()
{
    int low = 1;
    int high = 3;
    int selection;

    printf("--Main Menu--\n");
    printf("\n");
    printf("1 - New Game\n");
    printf("2 - Load Game\n");
    printf("3 - Exit\n");
    printf("\n");
    printf("Selection: ");

    selection = validate(low, high);

    printf("You selected: %d\n", selection);

    return 0;
}

int validate(int low, int high) {
    int selection;

    do {
        printf("Enter a number between %d and %d: ", low, high);
        if (scanf("%d", &selection) != 1) {
            // Handle non-integer input
            while (fgetc(stdin) != '\n');
            printf("Invalid input. Please enter a valid number.\n");
        } else if (selection < low || selection > high) {
            printf("Invalid input. Please enter a number between %d and %d.\n", low, high);
        }
    } while (selection < low || selection > high);

    return selection;
}
