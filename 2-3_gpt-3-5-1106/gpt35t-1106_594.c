#include <stdio.h>

void enter(int MeasurmentData[], int *nrOfmeasurments) {
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &MeasurmentData[i]);
        (*nrOfmeasurments)++;
    }
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

        printf("Enter your option: ");
        scanf(" %c", &menuoption);

        if (menuoption == 'e') {
            enter(MeasurmentData, &nrOfmeasurments);
        }
        else if (menuoption == 'v') {
            printf("Measurement Data:\n");
            for (int i = 0; i < nrOfmeasurments; i++) {
                printf("%d ", MeasurmentData[i]);
            }
            printf("\n");
        }
        else if (menuoption == 'c') {
            // Add code to compute highest and lowest values
        }
        else if (menuoption == 'q') {
            printf("Exiting Measurment tool 2.0\n");
            return 0; 
        }
    }

    return 0;
}
