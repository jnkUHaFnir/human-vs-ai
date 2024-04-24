#include <stdio.h>

// Function to enter measurements into the array
int enter(int MeasurmentData[], int size) {
    int nrOfmeasurments = 0;
    char input[10];
    printf("Enter up to 10 values (type 'q' to quit):\n");
    for (int i = 0; i < size; ++i) {
        fgets(input, 10, stdin); // Read input as string to check for 'q'
        if (input[0] == 'q') {
            break; // Quit the input loop
        }
        sscanf(input, "%d", &MeasurmentData[i]); // Parse integer from input string
        nrOfmeasurments++;
    }
    return nrOfmeasurments;
}

// Function to print the array
void view(int MeasurmentData[], int nrOfmeasurments) {
    for (int i = 0; i < nrOfmeasurments; i++) {
        printf("%d ", MeasurmentData[i]);
    }
    printf("\n");
}

// Function computing and printing the highest and the lowest values in the array
void compute(int MeasurmentData[], int nrOfmeasurments) {
    if (nrOfmeasurments == 0) {
        printf("No measurements entered.\n");
        return;
    }
    int max = MeasurmentData[0], min = MeasurmentData[0];
    for (int i = 1; i < nrOfmeasurments; i++) {
        if (MeasurmentData[i] > max) max = MeasurmentData[i];
        if (MeasurmentData[i] < min) min = MeasurmentData[i];
    }
    printf("Highest value: %d\n", max);
    printf("Lowest value: %d\n", min);
}

int main() {
    int MeasurmentData[10];
    int nrOfmeasurments = 0;

    while (1) {
        printf("Measurement tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("r (Reset)\n");
        printf("q (Quit)\n");

        printf("Enter your option:\n");
        char menuoption;
        scanf(" %c", &menuoption); // Note the space before %c to consume any newlines

        if (menuoption == 'e') {
            nrOfmeasurments = enter(MeasurmentData, 10); // Pass the array and its size
        } else if (menuoption == 'v') {
            view(MeasurmentData, nrOfmeasurments); // View the entered values
        } else if (menuoption == 'c') {
            compute(MeasurmentData, nrOfmeasurments); // Compute and print max and min values
        } else if (menuoption == 'r') {
            nrOfmeasurments = 0; // Reset the number of measurements
            printf("Measurements reset.\n");
        } else if (menuoption == 'q') {
            printf("Exiting Measurement tool 2.0\n");
            break; // Exit the loop and end the program
        }
    }
    
    return 0;
}
