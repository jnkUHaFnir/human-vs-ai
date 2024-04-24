#include <stdio.h>

void enter(int MeasurmentData[], int *nrOfmeasurments) {
    int input;
    // Loop to receive up to 10 measurements or until 'q' is input
    for(int i = 0; i < 10; ++i) {
        scanf("%d", &input);
        if(input == 'q') { // If user inputs 'q', break from loop
            break;
        }
        MeasurmentData[i] = input;
        (*nrOfmeasurments)++;
    }
}

void view(int MeasurmentData[], int nrOfmeasurments) {
    for(int i = 0; i < nrOfmeasurments; ++i) {
        printf("%d\n", MeasurmentData[i]);
    }
}

// Example compute function - computes and prints max and min values in the array
void compute(int MeasurmentData[], int nrOfmeasurments) {
    int max = MeasurmentData[0];
    int min = MeasurmentData[0];
    for(int i = 1; i < nrOfmeasurments; ++i) {
        if(MeasurmentData[i] > max) max = MeasurmentData[i];
        if(MeasurmentData[i] < min) min = MeasurmentData[i];
    }
    printf("Max: %d\nMin: %d\n", max, min);
}

int main() {
    int MeasurmentData[10] = {0};
    int nrOfmeasurments = 0;
    char menuoption;

    while (1) {
        printf("Measurment tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("r (Reset)\n");
        printf("q (Quit)\n");

        printf("enter your option:\n");
        scanf(" %c", &menuoption);

        switch (menuoption) {
            case 'e': // Enter values
                enter(MeasurmentData, &nrOfmeasurments);
                break;
            case 'v': // View values
                view(MeasurmentData, nrOfmeasurments);
                break;
            case 'c': // Compute values
                compute(MeasurmentData, nrOfmeasurments);
                break;
            case 'r': // Reset
                nrOfmeasurments = 0;
                break;
            case 'q': // Quit
                printf("Exiting Measurement tool 2.0\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}
