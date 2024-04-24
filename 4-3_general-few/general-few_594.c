#include <stdio.h>

void enter(int MeasurmentData[], int *nrOfmeasurments)
{
    printf("Enter up to 10 values:\n");
    
    for (int i = 0; i < 10; ++i) 
    {
        scanf("%d", &MeasurmentData[i]);
        (*nrOfmeasurments)++;
        
        if (MeasurmentData[i] == -1) 
        {
            break;
        }
    }
}

void view(int MeasurmentData[], int nrOfmeasurments)
{
    printf("Values in the array:\n");
    
    for (int i = 0; i < nrOfmeasurments; ++i)
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
        else if (menuoption == 'q') // quit
        {
            printf("Exiting Measurment tool 2.0\n");
            break;
        }
    }
    
    return 0;
}
