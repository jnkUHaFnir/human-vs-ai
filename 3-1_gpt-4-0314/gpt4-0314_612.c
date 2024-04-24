#include "stdafx.h"
#include <stdio.h>

int main() {

    double age, avgprice; //age = 1st column, avgprice = 2nd column
    FILE *corolla; //ptr for file

    corolla = fopen("C:/Users/Nate/Downloads/DataFiles/corolla.txt", "r");
    if (corolla == NULL) { //makes sure the file exists
        printf("File does not exist!\n");
        return 0; //prevents crashing
    }
    else {
        printf("Age \t\t Average Price\n"); //header for data when printed
        /*prints values until we're at the end of the file*/
        while (fscanf(corolla, "%lf %lf", &age, &avgprice) != EOF) {
            printf("%.1f \t\t $%.2f\n", age, avgprice); //prints data from file
        }
    }
    fclose(corolla); //closes file
    return 0;
}
