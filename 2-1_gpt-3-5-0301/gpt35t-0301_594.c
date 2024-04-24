#include <stdio.h>

int enter(int MeasurmentData[], int *nrOfmeasurments)
{
    for (int i = 0; i < 10; ++i)
    {
        scanf("%d", &MeasurmentData[i]);
        (*nrOfmeasurments)++;
    }
    return *nrOfmeasurments;
}

int main()
{
    int MeasurmentData[10];
    int nrOfmeasurments = 0;
    char menuoption;

    while (1)
    {
        printf("Measurement tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("r (Reset)\n");
        printf("q (Quit)\n");

        printf("Enter your option:\n");
        scanf(" %c", &menuoption);

        if (menuoption == 'e') // enter values
        {
            enter(MeasurmentData, &nrOfmeasurments);
        }
        else if (menuoption == 'v') // view values
        {
            for (int i = 0; i < nrOfmeasurments; i++)
            {
                printf("%d ", MeasurmentData[i]);
            }
            printf("\n");
        }
        else if (menuoption == 'c') // compute
        {
            if (nrOfmeasurments > 0)
            {
                int maxVal = MeasurmentData[0], minVal = MeasurmentData[0];
                for (int i = 1; i < nrOfmeasurments; i++)
                {
                    if (MeasurmentData[i] > maxVal)
                    {
                        maxVal = MeasurmentData[i];
                    }
                    if (MeasurmentData[i] < minVal)
                    {
                        minVal = MeasurmentData[i];
                    }
                }
                printf("Maximum value: %d\n", maxVal);
                printf("Minimum value: %d\n", minVal);
            }
            else
            {
                printf("No measurements recorded\n");
            }
        }
        else if (menuoption == 'r') // reset
        {
            nrOfmeasurments = 0;
        }
        else if (menuoption == 'q') // quit
        {
            printf("Exiting Measurement tool 2.0\n");
            return 0;
        }
    }
}
