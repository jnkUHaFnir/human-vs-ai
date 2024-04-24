#include <stdio.h>

int enter(int MeasurmentData[], int nrOfmeasurments)
{
    int i;
    for(i = 0; i < nrOfmeasurments && i < 10; ++i)
    {
        scanf("%d", &MeasurmentData[i]);
    }

    return i;  // Return the number of measurements entered
}

void view(int MeasurmentData[], int nrOfmeasurments)
{
    printf("Entered values: ");
    for(int i = 0; i < nrOfmeasurments; ++i)
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
        printf("Measurment tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("r (Reset)\n");
        printf("q (Quit)\n");

        printf("Enter your option: ");
        scanf(" %c", &menuoption);

        if (menuoption == 'e') // Enter values
        {
            printf("How many values do you want to enter (up to 10)? ");
            scanf("%d", &nrOfmeasurments);
            if(nrOfmeasurments > 10)
            {
                printf("Invalid number of values. Please enter no more than 10.\n");
                nrOfmeasurments = 10;
            }

            enter(MeasurmentData, nrOfmeasurments);
        }
        else if(menuoption == 'v') // View values
        {
            view(MeasurmentData, nrOfmeasurments);
        }
        else if(menuoption == 'c') // Compute
        {
            // Add your code here to compute highest and lowest values
        }
        else if(menuoption == 'q') // Quit
        {
            printf("Exiting Measurment tool 2.0\n");
            return 0; 
        }
    }

    return 0;
}
