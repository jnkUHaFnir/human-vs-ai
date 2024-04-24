#include <stdio.h>

void enter(int MeasurmentData[], size_t *nrOfmeasurments) {
    printf("Enter up to 10 values (or enter 'q' to stop):\n");

    for (*nrOfmeasurments = 0; *nrOfmeasurments < 10; (*nrOfmeasurments)++) {
        if (scanf("%d", &MeasurmentData[*nrOfmeasurments]) != 1) {
            break;  // If input is not an integer, stop taking input
        }
    }
}

void view(int MeasurmentData[], size_t nrOfmeasurments) {
    printf("Values entered:\n");
    for (size_t i = 0; i < nrOfmeasurments; i++) {
        printf("%d ", MeasurmentData[i]);
    }
    printf("\n");
}

int main() {
    int MeasurmentData[10];
    size_t nrOfmeasurments = 0;
    char menuoption;

    while (1) {
        printf("Measurement tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("q (Quit)\n");

        printf("Enter your option: ");
        scanf(" %c", &menuoption);

        if(menuoption == 'e') {
            enter(MeasurmentData, &nrOfmeasurments);
        } else if(menuoption == 'v') {
            view(MeasurmentData, nrOfmeasurments);
        } else if(menuoption == 'q') {
            printf("Exiting Measurement tool 2.0\n");
            return 0;
        }
    }

    return 0;
}
