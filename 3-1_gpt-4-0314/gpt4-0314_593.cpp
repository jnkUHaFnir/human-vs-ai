#include <stdio.h>

int enter(int MeasurmentData[], int nrOfmeasurments)
{
    for(int i = 0; i < 10; ++i) 
    {
        scanf("%d", &MeasurmentData[i]);

        nrOfmeasurments++;
        if (getchar() == 'q')
            break;
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

        printf("enter your option:\n");
        scanf(" %c", &menuoption);

        if (menuoption == 'e') // enter values
        {
            nrOfmeasurments = enter(MeasurmentData, nrOfmeasurments);
        }
        else if(menuoption == 'v') // view values
        {
            for(int i = 0; i < nrOfmeasurments; ++i)
                printf("%d ", MeasurmentData[i]);
            printf("\n");
        }
        else if(menuoption == 'c')
        {
            // Compute logic here
        }
        if(menuoption == 'q')
        {
            printf("Exiting Measurment tool 2.0\n");
            return 0; 
        }
    }
}
