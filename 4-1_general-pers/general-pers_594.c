#include <stdio.h>

#define MAX_MEASUREMENTS 10

int enter(int MeasurementData[], int *nrOfMeasurements)
{
    int i;

    for (i = 0; i < MAX_MEASUREMENTS; ++i)
    {
        if (scanf("%d", &MeasurementData[i]) != 1) {
            printf("Error reading input.\n");
            return -1; // Return an error code
        }

        (*nrOfMeasurements)++;

        if (*nrOfMeasurements == MAX_MEASUREMENTS)
        {
            break; // Exit loop when reaching the maximum number of measurements
        }
    }

    return 0; // Return success code
}

void view(int MeasurementData[], int nrOfMeasurements)
{
    for (int i = 0; i < nrOfMeasurements; i++)
    {
        printf("%d ", MeasurementData[i]);
    }
    printf("\n");
}

int main()
{
    int MeasurementData[MAX_MEASUREMENTS];
    int nrOfMeasurements = 0;
    char menuoption;

    while (1)
    {
        printf("Measurement tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("r (Reset)\n");
        printf("q (Quit)\n");

        printf("Enter your option: ");
        scanf(" %c", &menuoption);

        switch(menuoption)
        {
            case 'e':
                if (enter(MeasurementData, &nrOfMeasurements) != 0)
                {
                    printf("Error entering measurements.\n");
                }
                break;
            case 'v':
                view(MeasurementData, nrOfMeasurements);
                break;
            case 'c':
                // Compute logic here
                break;
            case 'q':
                printf("Exiting Measurement tool 2.0\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
