#include <stdio.h>

void enter(int MeasurmentData[], int *nrOfMeasurements)
{
    for (int i = 0; i < 10; ++i)
    {
        scanf("%d", &MeasurmentData[i]);
        (*nrOfMeasurements)++;
    }
}

void view(int MeasurmentData[], int nrOfMeasurements)
{
    printf("Values in the array:\n");
    for (int i = 0; i < nrOfMeasurements; ++i)
    {
        printf("%d ", MeasurmentData[i]);
    }
    printf("\n");
}

void compute(int MeasurmentData[], int nrOfMeasurements)
{
    if (nrOfMeasurements == 0)
    {
        printf("No measurements entered yet.\n");
        return;
    }

    int max = MeasurmentData[0];
    int min = MeasurmentData[0];

    for (int i = 1; i < nrOfMeasurements; ++i)
    {
        if (MeasurmentData[i] > max)
        {
            max = MeasurmentData[i];
        }
        if (MeasurmentData[i] < min)
        {
            min = MeasurmentData[i];
        }
    }

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
}

int main()
{
    int MeasurmentData[10];
    int nrOfMeasurements = 0;
    char menuOption;

    while (1)
    {
        printf("Measurement Tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("q (Quit)\n");

        printf("Enter your option: ");
        scanf(" %c", &menuOption);

        if (menuOption == 'e') // Enter values
        {
            enter(MeasurmentData, &nrOfMeasurements);
        }
        else if (menuOption == 'v') // View values
        {
            view(MeasurmentData, nrOfMeasurements);
        }
        else if (menuOption == 'c') // Compute values
        {
            compute(MeasurmentData, nrOfMeasurements);
        }
        else if (menuOption == 'q') // Quit
        {
            printf("Exiting Measurement Tool 2.0\n");
            return 0;
        }
    }

    return 0;
}
