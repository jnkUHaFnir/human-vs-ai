#include <stdio.h>

void enter(int MeasurmentData[], int *nrOfmeasurments) {
    for(int i=0; i<10; ++i) {
        printf("Enter value #%d (or q to quit): ", i+1);
        char input[10];
        scanf("%9s", input);
        if(input[0] == 'q') {
            break;
        } else {
            MeasurmentData[i] = atoi(input);
            (*nrOfmeasurments)++;
        }  
    }
}

void view(int MeasurmentData[], int nrOfmeasurments) {
    for(int i = 0; i < nrOfmeasurments; i++) {
        printf("%d ", MeasurmentData[i]);
    }
    printf("\n");
}

void compute(int MeasurmentData[], int nrOfmeasurments) {
    if (nrOfmeasurments <= 0) {
        printf("No data to compute.\n");
        return;
    }

    int min = MeasurmentData[0];
    int max = MeasurmentData[0];

    for (int i = 1; i < nrOfmeasurments; i++) {
        if (MeasurmentData[i] > max) {
            max = MeasurmentData[i];
        }
        if (MeasurmentData[i] < min) {
            min = MeasurmentData[i];
        }
    }

    printf("Max value: %d\n", max);
    printf("Min value: %d\n", min);
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

        printf("Enter your option: ");
        scanf(" %c", &menuoption);

        switch (menuoption) {
            case 'e':
                enter(MeasurmentData, &nrOfmeasurments);
                break;
            case 'v':
                view(MeasurmentData, nrOfmeasurments);
                break;
            case 'c':
                compute(MeasurmentData, nrOfmeasurments);
                break;
            case 'r':
                nrOfmeasurments = 0; // Reset
                break;
            case 'q':
                printf("Exiting Measurement tool 2.0\n");
                return 0;
            default:
                printf("Invalid option, please choose again.\n");
                break;
        }
    }
}
