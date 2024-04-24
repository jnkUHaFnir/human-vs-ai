#include <stdio.h>

int validate(int low, int high);

int main()
{
    int sel;
    int low = 1;
    int high = 3;
    int Valid_Selection;

    // Display menu and validate user input
    printf("--Main Menu--\n");
    printf("\n");
    printf("1 - New Game\n");
    printf("2 - Load Game\n");
    printf("3 - Exit\n");
    printf("\n");
    printf("Selection: \n\n");

    Valid_Selection = validate(low, high);

    // Further code can use Valid_Selection for menu options or other selections

    return 0;
}

int validate(int low, int high)
{
    int s;

    do {
        printf("Enter your choice between %d and %d: ", low, high);
        scanf("%d", &s);

        if (s < low || s > high) {
            printf("Invalid input. Please try again.\n");
        }

    } while (s < low || s > high);

    return s;
}
