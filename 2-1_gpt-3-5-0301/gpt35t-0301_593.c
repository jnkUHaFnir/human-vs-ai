#include <stdio.h>

int enter(int MeasurmentData[], int nrOfmeasurments)
{
    for (int i = 0; i < 10; ++i) 
    {
        scanf("%d", &MeasurmentData[i]);
        nrOfmeasurments++;
    }
    return nrOfmeasurments;
}

int main()
{
    int MeasurmentData[10] = {0};
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
            nrOfmeasurments = enter(MeasurmentData, nrOfmeasurments);
        }
        else if (menuoption == 'v') // view values
        {
            printf("Values entered:\n");
            for (int i = 0; i < nrOfmeasurments; ++i) {
                printf("%d ", MeasurmentData[i]);
            }
            printf("\n");
        }
        else if (menuoption == 'c') // compute values
        {
            if (nrOfmeasurments > 0) {
                int max_value = MeasurmentData[0];
                int min_value = MeasurmentData[0];
                for (int i = 1; i < nrOfmeasurments; ++i) {
                    if (MeasurmentData[i] > max_value) {
                        max_value = MeasurmentData[i];
                    }
                    if (MeasurmentData[i] < min_value) {
                        min_value = MeasurmentData[i];
                    }
                }
                printf("Maximum value: %d\n", max_value);
                printf("Minimum value: %d\n", min_value);
            } else {
                printf("No values entered yet.\n");
            }
        }
        else if (menuoption == 'r') // reset values
        {
            for (int i = 0; i < 10; ++i) {
                MeasurmentData[i] = 0;
            }
            nrOfmeasurments = 0;
        }
        else if (menuoption == 'q') // quit program
        {
            printf("Exiting Measurment tool 2.0\n");
            return 0; 
        }
        else // invalid option
        {
            printf("Invalid option.\n");
        }
    }
}
