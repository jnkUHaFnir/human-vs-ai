#include <stdio.h>

#define MAX_MEASUREMENTS 10

int enter(int MeasurmentData[], int *nrOfmeasurements) {
    for (int i = 0; i < MAX_MEASUREMENTS; ++i) {
        if (scanf("%d", &MeasurmentData[i]) != 1) {
            printf("Invalid input. Please enter a number.\n");
            return i;  // Return number of valid inputs
        }
        (*nrOfmeasurements)++;
    }

    return MAX_MEASUREMENTS;
}

void view(int MeasurmentData[], int nrOfmeasurements) {
    printf("Measurement Data:\n");
    for (int i = 0; i < nrOfmeasurements; ++i) {
        printf("%d ", MeasurmentData[i]);
    }
    printf("\n");
}

void compute(int MeasurmentData[], int nrOfmeasurements) {
    if (nrOfmeasurements == 0) {
        printf("No measurements entered.\n");
        return;
    }

    int min = MeasurmentData[0];
    int max = MeasurmentData[0];

    for (int i = 1; i < nrOfmeasurements; ++i) {
        if (MeasurmentData[i] < min) {
            min = MeasurmentData[i];
        }
        if (MeasurmentData[i] > max) {
            max = MeasurmentData[i];
        }
    }

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n");
}

int main() {
    int MeasurmentData[MAX_MEASUREMENTS];
    int nrOfmeasurements = 0;
    char menuoption;

    while (1) {
        printf("\nMeasurement Tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("q (Quit)\n");

        printf("Enter your option: ");
        scanf(" %c", &menuoption);

        if (menuoption == 'e') {
            nrOfmeasurements = enter(MeasurmentData, &nrOfmeasurements);
        } else if (menuoption == 'v') {
            view(MeasurmentData, nrOfmeasurements);
        } else if (menuoption == 'c') {
            compute(MeasurmentData, nrOfmeasurements);
        } else if (menuoption == 'q') {
            printf("Exiting Measurement Tool 2.0\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
