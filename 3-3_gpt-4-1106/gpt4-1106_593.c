#include <stdio.h>

int enter(int MeasurementData[], int *nrOfMeasurements) {
    int input;
    for (int i = 0; i < 10; ++i) {
        printf("Enter value #%d (or 'q' to quit): ", i + 1);
        if (scanf("%d", &input) == 1) {
            MeasurementData[i] = input;
            (*nrOfMeasurements)++;
        } else {
            scanf("%*s"); // Consume the incorrect input.
            break; // Exit if the user doesn't enter a number.
        }
    }
    return *nrOfMeasurements;
}

int main() {
    int MeasurementData[10];
    int nrOfMeasurements = 0;
    char menuOption;

    while (1) {
        printf("Measurement tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("r (Reset)\n");
        printf("q (Quit)\n");

        printf("Enter your option:\n");
        scanf(" %c", &menuOption);

        if (menuOption == 'e') {
            nrOfMeasurements = 0; // Reset counter each time we re-enter values.
            enter(MeasurementData, &nrOfMeasurements);
        } else if (menuOption == 'v') {
            for (int i = 0; i < nrOfMeasurements; ++i) {
                printf("%d ", MeasurementData[i]);
            }
            printf("\n");
        } else if (menuOption == 'c') {
            // Further computations can be added here.
        } else if (menuOption == 'q') {
            printf("Exiting Measurement tool 2.0\n");
            return 0;
        }
    }
}
