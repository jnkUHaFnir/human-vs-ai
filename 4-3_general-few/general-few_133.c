#include <stdio.h>
#include <stdlib.h> // for exit()

int main()
{
    int number, sum = 0;
    int result;

    do
    {
        printf("Enter a number: ");
        result = scanf("%d", &number);

        // Check if the input was successful
        if (result != 1)
        {
            // Clear the input buffer
            while((result = getchar()) != '\n' && result != EOF)
            {
                // discard characters until newline or EOF
            }

            if (result == EOF)
            {
                printf("Error: End of file encountered. Exiting.\n");
                exit(1);
            }

            printf("Invalid input. Please enter a valid number.\n");
            continue; // Restart the loop
        }

        sum += number;
    }
    while(number != 0);

    printf("Sum = %d", sum);

    return 0;
}
