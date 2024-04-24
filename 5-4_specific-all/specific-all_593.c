#include <stdio.h>

int enter(int MeasurmentData[], int nrOfmeasurments)
{
    for(int i = 0; i < nrOfmeasurments; ++i)
    {
        scanf("%d", &MeasurmentData[i]);
    }

    return nrOfmeasurments;
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

        if (menuoption == 'e') 
        {
            printf("Enter the number of measurements (up to 10): ");
            scanf("%d", &nrOfmeasurments);
            if (nrOfmeasurments > 10) {
                nrOfmeasurments = 10;
            }

            enter(MeasurmentData, nrOfmeasurments);

        }
        else if(menuoption == 'v') 
        {
            printf("Values in the array: ");
            for (int i = 0; i < nrOfmeasurments; ++i)
            {
                printf("%d ", MeasurmentData[i]);
            }
            printf("\n");
        }
        else if(menuoption == 'c')
        {
            // Add computation logic here
        }
        else if(menuoption == 'q')
        {
            printf("Exiting Measurment tool 2.0\n");
            break; // Exit the while loop
        }
    }

    return 0;
}
