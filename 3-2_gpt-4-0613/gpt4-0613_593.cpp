#include <stdio.h>

int enter(int MeasurementData[], int *nrOfMeasurements)
{
    int value = 0;
    
    printf("Enter measurements (up to 10, 'q' to end):\n");
    for(int i=0;i<10;++i) 
    {
        if(scanf("%d", &value))
        {
            MeasurementData[i] = value;
            (*nrOfMeasurements)++;
        }
        else 
        {
            int c;
            while((c = getchar()) != '\n' && c != EOF); // Clear input buffer
            break;
        }
    }
    return 0;
}

void view(const int MeasurementData[], int nrOfMeasurements)
{
    printf("Current measurements:\n");
    for(int i = 0; i < nrOfMeasurements; ++i) 
    {
        printf("%d ", MeasurementData[i]);
    }
    printf("\n");
}

void compute(const int MeasurementData[], int nrOfMeasurements)
{
    if(nrOfMeasurements > 0) 
    {
        int min = MeasurementData[0];
        int max = MeasurementData[0];
        double avg = 0.0;

        for(int i = 0; i < nrOfMeasurements; ++i) 
        {
            if(MeasurementData[i] < min) min = MeasurementData[i];
            if(MeasurementData[i] > max) max = MeasurementData[i];
            avg += MeasurementData[i];
        }
        avg /= nrOfMeasurements;

        printf("Min: %d, Max: %d, Avg: %.2f\n", min, max, avg);
    }
}

void reset(int MeasurementData[], int *nrOfMeasurements)
{
    for(int i = 0; i < *nrOfMeasurements; ++i)
    {
        MeasurementData[i] = 0;
    }
    *nrOfMeasurements = 0;
}

int main()
{
    int MeasurementData[10] = {0};
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

        printf("Enter your option:\n");
        scanf(" %c", &menuoption);

        switch(menuoption)
        {
            case 'e':
                enter(MeasurementData, &nrOfMeasurements);
                break;
            case 'v':
                view(MeasurementData, nrOfMeasurements);
                break;
            case 'c':
                compute(MeasurementData, nrOfMeasurements);
                break;
            case 'r':
                reset(MeasurementData, &nrOfMeasurements);
                break;
            case 'q':
                printf("Exiting Measurement tool 2.0\n");
                return 0;
            default:
                printf("Unknown option\n");
        }
    }

    return 0;
}
