#include <stdio.h>

int enter(int MeasurmentData[], int *nrOfmeasurments)
{
    for (int i = 0; i < 10; ++i)
    {
        printf("Enter a measurement (or 'q' to quit): ");
        char input[10];
        scanf("%s", input);

        if (input[0] == 'q' || input[0] == 'Q')
        {
            break;
        }
        else
        {
            sscanf(input, "%d", &MeasurmentData[*nrOfmeasurments]);
            *nrOfmeasurments += 1;
        }
    }
}

void view(int MeasurmentData[], int nrOfmeasurments)
{
    printf("Measurements:\n");
    for (int i = 0; i < nrOfmeasurments; i++)
    {
        printf("%d ", MeasurmentData[i]);
    }
    printf("\n");
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
            view(MeasurmentData, nrOfmeasurments);
        }
        else if (menuoption == 'c')
        {
            // Compute
        }
        else if (menuoption == 'r')
        {
            // Reset
        }
        else if (menuoption == 'q')
        {
            printf("Exiting Measurement tool 2.0\n");
            break;
        }
    }
    return 0;
}
