#include <stdio.h>

int enter(int MeasurmentData[], int *nrOfmeasurments) {
    for(int i = 0; i < 10; ++i) {
        scanf("%d", &MeasurmentData[i]);
        (*nrOfmeasurments)++;
        if (*nrOfmeasurments == 10) {
            break; // Maximum number of measurements reached
        }
    }
    return *nrOfmeasurments;
}

int main() {
    int MeasurmentData[10];
    int nrOfmeasurments = 0;
    char menuoption;

    while (1) {
        printf("Measurment tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("r (Reset)\n");
        printf("q (Quit)\n");

        printf("Enter your option:\n");
        scanf(" %c", &menuoption);

        if (menuoption == 'e') {
            enter(MeasurmentData, &nrOfmeasurments);
        } else if(menuoption == 'v') {
            printf("Values in array:\n");
            for (int i = 0; i < nrOfmeasurments; ++i) {
                printf("%d ", MeasurmentData[i]);
            }
            printf("\n");
        } else if(menuoption == 'c') {
            // Compute highest and lowest values
        }

        if(menuoption == 'q') {
            printf("Exiting Measurment tool 2.0\n");
            return 0; 
        }
    }

    return 0;
}
