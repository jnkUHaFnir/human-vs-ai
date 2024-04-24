#include <stdio.h>

void enter(int MeasurmentData[], int *nrOfmeasurements) {
    for(int i = 0; i < 10; ++i) {
        scanf("%d", &MeasurmentData[i]);
        (*nrOfmeasurements)++;
    }
}

int main() {
    int MeasurmentData[10];
    int nrOfmeasurements = 0;
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
            enter(MeasurmentData, &nrOfmeasurements);
        } else if (menuOption == 'v') {
            printf("Values entered: ");
            for (int i = 0; i < nrOfmeasurements; ++i) {
                printf("%d ", MeasurmentData[i]);
            }
            printf("\n");
        } else if (menuOption == 'c') {
            // Compute highest, lowest values, etc.
        } else if (menuOption == 'q') {
            printf("Exiting Measurement tool 2.0\n");
            return 0;
        }
    }

    return 0;
}
