#include <stdio.h>

int main()
{
    char answer;

    do
    {
        // Your main program logic here

        printf("\n\nWould you like to run the program again? Type y or n. Then, hit Enter.");
        // Consume any leftover newline character before reading the answer
        while (getchar() != '\n');
        scanf("%c", &answer);

        if (answer != 'y' && answer != 'n')
        {
            printf("\nERROR: Invalid input was provided. Your answer must be either y or n. Hit Enter to continue.");
        }
    } while (answer != 'n');

    return 0;
}
