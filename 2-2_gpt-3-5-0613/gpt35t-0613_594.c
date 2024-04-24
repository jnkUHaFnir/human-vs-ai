#include <stdio.h>

int enter(int MeasurmentData[], int nrOfmeasurments) {
    for(int i = 0; i < nrOfmeasurments; ++i) {
        scanf("%d", &MeasurmentData[i]);
    }
    
    return nrOfmeasurments;
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

        if (menuoption == 'e') { // Enter values
            printf("Enter the number of measurements (up to 10):\n");
            scanf("%d", &nrOfmeasurments);
            if(nrOfmeasurments > 10) {
                printf("Number of measurements exceeding array size. Resetting to 10.\n");
                nrOfmeasurments = 10;
            }
            enter(MeasurmentData, nrOfmeasurments);
        }
        else if(menuoption == 'v') { // View values
            if (nrOfmeasurments == 0) {
                printf("No values entered yet.\n");
            } else {
                printf("Measurement Data: ");
                for (int i = 0; i < nrOfmeasurments; i++) {
                    printf("%d ", MeasurmentData[i]);
                }
                printf("\n");
            }
        }
        else if(menuoption == 'c') { // Compute
            if (nrOfmeasurments == 0) {
                printf("No values entered yet.\n");
            } else {
                int max = MeasurmentData[0];
                int min = MeasurmentData[0];
                
                for (int i = 1; i < nrOfmeasurments; i++) {
                    if (MeasurmentData[i] > max) {
                        max = MeasurmentData[i];
                    }
                    if (MeasurmentData[i] < min) {
                        min = MeasurmentData[i];
                    }
                }
                
                printf("Maximum value: %d\n", max);
                printf("Minimum value: %d\n", min);
            }
        }
        else if(menuoption == 'r') { // Reset
            nrOfmeasurments = 0;
            printf("Measurement data reset.\n");
        }
        else if(menuoption == 'q') {
            printf("Exiting Measurment tool 2.0\n");
            return 0; 
        }
        else {
            printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}
