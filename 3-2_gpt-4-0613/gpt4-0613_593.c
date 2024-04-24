#include <stdio.h>

void enter(int MeasurementData[], int* nrOfMeasurements) {
    printf("Enter up to 10 measurements (or 'q' to go back to menu):\n");
    for(int i=0; i<10; ++i) {
        int val;
        char ch = scanf("%d",&val);
        if (ch != 1) { // q was entered
            int c;
            while((c = getchar()) != '\n' && c != EOF); // flush the buffer
            break;
        }
        MeasurementData[i] = val;
        (*nrOfMeasurements)++;
    }
}

void view(int MeasurementData[], int nrOfMeasurements) {
    for(int i = 0; i < nrOfMeasurements; i++) {
        printf("%d ", MeasurementData[i]);
    }
    printf("\n");
}

int main() {
    int MeasurementData[10];
    int nrOfMeasurements = 0;
    char menuoption;

    while (1) {
        printf("Measurement tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("r (Reset)\n");
        printf("q (Quit)\n");

        printf("enter your option:\n");
        scanf(" %c", &menuoption);

        if (menuoption =='e') { // enter values
            enter(MeasurementData, &nrOfMeasurements);
        }
        else if(menuoption == 'v') { // view values
            view(MeasurementData, nrOfMeasurements);
        }
        else if(menuoption == 'c') {
            // compute function here
        }
        else if(menuoption == 'r') {
            nrOfMeasurements = 0; // reset the count
        }
        else if(menuoption == 'q') {
            printf("Exiting Measurement tool 2.0\n");
            return 0; 
        }
    }
}
