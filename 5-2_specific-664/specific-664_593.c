#include <stdio.h>

int enter(int MeasurmentData[], int *nrOfmeasurments) {
    *nrOfmeasurments = 0;
    
    for(int i = 0; i < 10; ++i) {
        printf("Enter value %d: ", i + 1);
        if (scanf("%d", &MeasurmentData[i]) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            return 0;
        }
        (*nrOfmeasurments)++;
    }
    
    return 1;
}

void view(int MeasurmentData[], int nrOfmeasurments) {
    printf("Values in the array:\n");
    for(int i = 0; i < nrOfmeasurments; ++i) {
        printf("%d ", MeasurmentData[i]);
    }
    printf("\n");
}

void compute(int MeasurmentData[], int nrOfmeasurments) {
    if (nrOfmeasurments == 0) {
        printf("Please enter values before computing.\n");
        return;
    }
    
    int max = MeasurmentData[0];
    int min = MeasurmentData[0];
    
    for (int i = 1; i < nrOfmeasurments; ++i) {
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

int main() {
    int MeasurmentData[10];
    int nrOfmeasurments = 0;
    char menuoption;

    while (1) {
        printf("Measurement tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("q (Quit)\n");

        printf("Enter your option: ");
        scanf(" %c", &menuoption);

        switch (menuoption) {
            case 'e':
                if (!enter(MeasurmentData, &nrOfmeasurments)) {
                    break;
                }
                break;
            case 'v':
                view(MeasurmentData, nrOfmeasurments);
                break;
            case 'c':
                compute(MeasurmentData, nrOfmeasurments);
                break;
            case 'q':
                printf("Exiting Measurement tool 2.0\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
