#include <stdio.h>

#define MAX_SIZE 10

int enter(int MeasurmentData[], int *nrOfmeasurements) {
    for (int i = 0; i < MAX_SIZE; i++) {
        scanf("%d", &MeasurmentData[i]);
        (*nrOfmeasurements)++;
    }
    return *nrOfmeasurements;
}

void view(int MeasurmentData[], int nrOfmeasurements) {
    printf("Array values: ");
    for (int i = 0; i < nrOfmeasurements; i++) {
        printf("%d ", MeasurmentData[i]);
    }
    printf("\n");
}

int main() {
    int MeasurmentData[MAX_SIZE];
    int nrOfmeasurements = 0;
    char menuoption;

    while (1) {
        printf("Measurment tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("r (Reset)\n");
        printf("q (Quit)\n");

        printf("Enter your option: ");
        scanf(" %c", &menuoption);

        if (menuoption == 'e') {
            enter(MeasurmentData, &nrOfmeasurements);
        } else if (menuoption == 'v') {
            view(MeasurmentData, nrOfmeasurements);
        } else if (menuoption == 'c') {
            // Add your compute logic here
        } else if (menuoption == 'q') {
            printf("Exiting Measurment tool 2.0\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
