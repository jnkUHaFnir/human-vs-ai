#include <stdio.h>

#define MAX_MEASUREMENTS 10

int enter(int MeasurementData[], int *nrOfMeasurements) {
    for (int i = 0; i < MAX_MEASUREMENTS; ++i) {
        if (scanf("%d", &MeasurementData[i]) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            return i;
        }
        (*nrOfMeasurements)++;
    }
    
    return MAX_MEASUREMENTS;
}

void view(const int MeasurementData[], int nrOfMeasurements) {
    for (int i = 0; i < nrOfMeasurements; i++) {
        printf("%d ", MeasurementData[i]);
    }
    printf("\n");
}

void compute(const int MeasurementData[], int nrOfMeasurements) {
    if (nrOfMeasurements == 0) {
        printf("No measurements entered.\n");
        return;
    }
    
    int max = MeasurementData[0];
    int min = MeasurementData[0];
    
    for (int i = 1; i < nrOfMeasurements; i++) {
        if (MeasurementData[i] > max) {
            max = MeasurementData[i];
        }
        if (MeasurementData[i] < min) {
            min = MeasurementData[i];
        }
    }
    
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
}

int main() {
    int MeasurementData[MAX_MEASUREMENTS];
    int nrOfMeasurements = 0;
    char menuOption;
    
    while (1) {
        printf("Measurement tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("r (Reset)\n");
        printf("q (Quit)\n");
        
        printf("Enter your option: ");
        scanf(" %c", &menuOption);
        
        if (menuOption == 'e') {
            nrOfMeasurements = enter(MeasurementData, &nrOfMeasurements);
        } else if (menuOption == 'v') {
            view(MeasurementData, nrOfMeasurements);
        } else if (menuOption == 'c') {
            compute(MeasurementData, nrOfMeasurements);
        } else if (menuOption == 'q') {
            printf("Exiting Measurement tool 2.0\n");
            return 0;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}
