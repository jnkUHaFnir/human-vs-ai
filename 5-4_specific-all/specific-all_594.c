#include <stdio.h>

#define MAX_SIZE 10

int enter(int MeasurmentData[], int *nrOfmeasurments) {
    for(int i = 0; i < MAX_SIZE; ++i) {
        scanf("%d", &MeasurmentData[i]);
        *nrOfmeasurments = i + 1;

        if(MeasurmentData[i] == -1) { // Break loop if user enters -1
            break;
        }
    }

    return *nrOfmeasurments;
}

void view(int MeasurmentData[], int nrOfmeasurments) {
    printf("Elements in the array:\n");
    for(int i = 0; i < nrOfmeasurments; ++i) {
        printf("%d ", MeasurmentData[i]);
    }
    printf("\n");
}

int main() {
    int MeasurmentData[MAX_SIZE];
    int nrOfmeasurments = 0;
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
            enter(MeasurmentData, &nrOfmeasurments);
        } else if (menuOption == 'v') {
            view(MeasurmentData, nrOfmeasurments);
        } else if (menuOption == 'c') {
            // Compute highest and lowest values
        } else if (menuOption == 'q') {
            printf("Exiting Measurement tool 2.0\n");
            return 0;
        }
    }

    return 0;
}
