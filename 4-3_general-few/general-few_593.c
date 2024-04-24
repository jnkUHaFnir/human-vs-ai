#include <stdio.h>

int enter(int MeasurmentData[], int *nrOfmeasurments)
{
    for (int i = 0; i < 10; ++i)
    {
        scanf("%d", &MeasurmentData[i]);
        *nrOfmeasurments += 1;
        if (*nrOfmeasurments == 10)
        {
            break;
        }
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
        printf("Measurment tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("r (Reset)\n");
        printf("q (Quit)\n");

        printf("Enter your option: ");
        scanf(" %c", &menuoption);

        if (menuoption == 'e') // enter values
        {
            nrOfmeasurments = enter(MeasurmentData, &nrOfmeasurments);
        }
        else if (menuoption == 'v') // view values
        {
            printf("Elements in the array: ");
            for (int i = 0; i < nrOfmeasurments; ++i)
            {
                printf("%d ", MeasurmentData[i]);
            }
            printf("\n");
        }
        else if (menuoption == 'c')
        {
            if (nrOfmeasurments > 0)
            {
                int max_val = MeasurmentData[0];
                int min_val = MeasurmentData[0];

                for (int i = 1; i < nrOfmeasurments; ++i)
                {
                    if (MeasurmentData[i] > max_val)
                    {
                        max_val = MeasurmentData[i];
                    }
                    if (MeasurmentData[i] < min_val)
                    {
                        min_val = MeasurmentData[i];
                    }
                }

                printf("Maximum value in the array: %d\n", max_val);
                printf("Minimum value in the array: %d\n", min_val);
            }
            else
            {
                printf("No elements entered yet.\n");
            }
        }

        if (menuoption == 'q')
        {
            printf("Exiting Measurment tool 2.0\n");
            return 0;
        }
    }

    return 0;
}
