#include <stdio.h>

#define SIZE 10

void enter(int MeasurmentData[], int *nrOfmeasurments)
    {
    int i;
    for(i=0;i<SIZE;++i) 
    {
        printf("Enter measure number %d (or -1 to stop): ", i+1);
        scanf("%d",&MeasurmentData[i]);
        if(MeasurmentData[i] == -1) 
        {
            break;   
        }
        *nrOfmeasurments += 1;
    }
}

void view(const int MeasurmentData[], int num)
{
    int j;
    for (j=0; j < num; ++j)
    {
        printf ("%d ", MeasurmentData[j]);
    }
    printf("\n");
}

void compute(const int MeasurmentData[], int num)
{
    int k;
    int min = MeasurmentData[0];
    int max = MeasurmentData[0];
    if(num>0){
        for (k=0; k < num; ++k)
        {
            min = (MeasurmentData[k] < min) ? MeasurmentData[k] : min;
            max = (MeasurmentData[k] > max) ? MeasurmentData[k] : max;
        }
        printf("Min = %d, Max = %d\n", min, max);
    }
}

void reset(int MeasurmentData[], int *nrOfmeasurments)
{
    int l;
    for(l = 0 ; l < SIZE ; l++)
    {
        MeasurmentData[l] = 0;
    }
    *nrOfmeasurments = 0;
}

int main()
    {
    int MeasurmentData[SIZE] = {0};
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

        switch(menuoption)
        {
            case 'e': // enter values
                enter(MeasurmentData, &nrOfmeasurments);
                break;
            case 'v': // view values
                view(MeasurmentData, nrOfmeasurments);
                break;
            case 'c': // compute min and max
                compute(MeasurmentData, nrOfmeasurments);
                break;
            case 'r': // reset MeasurmentData and nrOfmeasurments
                reset(MeasurmentData, &nrOfmeasurments);
                break;
            case 'q': // Quit
                printf("Exiting Measurment tool 2.0\n");
                return 0; 
        }
    }
}
