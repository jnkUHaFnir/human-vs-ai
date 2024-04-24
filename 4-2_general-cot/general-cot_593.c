#include <stdio.h>

#define MAX_MEASUREMENTS 10

int enter(int MeasurmentData[], int *nrOfMeasurements)
{
    *nrOfMeasurements = 0;
    for (int i = 0; i < MAX_MEASUREMENTS; ++i)
    {
        printf("Enter measurement %d: ", i + 1);
        if(scanf("%d", &MeasurmentData[i]) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            i--; // Decrement i to repeat the current input
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }
        (*nrOfMeasurements)++;
        if (*nrOfMeasurements >= MAX_MEASUREMENTS) {
            break;
        }
    }
    return *nrOfMeasurements;
}

void view(int MeasurmentData[], int nrOfMeasurements)
{
    printf("Measurements: ");
    for (int i = 0; i < nrOfMeasurements; ++i)
    {
        printf("%d ", MeasurmentData[i]);
    }
    printf("\n");
}

// You can add a compute function here to calculate min, max, etc.

int main()
{
    int MeasurmentData[MAX_MEASUREMENTS];
    int nrOfMeasurements = 0;
    char menuOption;

    while (1)
    {
        printf("Measurment tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("r (Reset)\n");
        printf("q (Quit)\n");

        printf("Enter your option: ");
        scanf(" %c", &menuOption);

        switch (menuOption)
        {
        case 'e':
            enter(MeasurmentData, &nrOfMeasurements);
            break;
        case 'v':
            view(MeasurmentData, nrOfMeasurements);
            break;
        case 'c':
            // Call your compute function here
            break;
        case 'r':
            nrOfMeasurements = 0;
            printf("Measurements reset.\n");
            break;
        case 'q':
            printf("Exiting Measurment tool 2.0\n");
            return 0;
        default:
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
