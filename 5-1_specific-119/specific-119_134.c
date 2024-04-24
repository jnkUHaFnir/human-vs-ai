#include <stdio.h>

int validate(int low, int high);

int main()
{
    int sel;
    int low = 1;
    int high = 3;
    int Valid_Selection;

    //Main Menu
    printf("--Main Menu--\n\n");
    printf("1 - New Game\n");
    printf("2 - Load Game\n");
    printf("3 - Exit\n\n");
    printf("Selection: ");

    // Validate user input using a function
    Valid_Selection = validate(low, high);

    printf("You entered: %d\n", Valid_Selection);

    return 0;
}

int validate(int low, int high)
{
    int selection;

    do
    {
        printf("Enter a number between %d and %d: ", low, high);
        scanf("%d", &selection);

        if (selection < low || selection > high)
        {
            printf("Invalid Input, try again.\n");
        }

    } while (selection < low || selection > high);

    return selection;
}
