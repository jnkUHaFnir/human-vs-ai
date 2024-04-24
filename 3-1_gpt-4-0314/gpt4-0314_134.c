#include <stdio.h>

int validate(int low, int high);

int main()
{
    // ... (remaining code unchanged)

    // Validate user input using a function
    Valid_Selection = validate(low, high);

    // ... (remaining code unchanged)

    return 0;
}

int validate(int low, int high)
{
    int selection;

    do
    {
        scanf("%d", &selection);
        if (selection < low || selection > high)
            printf("Invalid Input, try again: ");
    } while (selection < low || selection > high);

    return selection;
}
