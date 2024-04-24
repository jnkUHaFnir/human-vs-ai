#include <stdio.h>

int main() {

    double age, avgprice; // age = 1st column, avgprice = 2nd column
    FILE* corolla; // pointer for file

    corolla = fopen("C:/Users/Nate/Downloads/DataFiles/corolla.txt", "r");
    if (corolla == NULL) { // makes sure the file exists
        printf("File does not exist!\n");
        return 1; // prevents crashing
    }
    else {
        printf("Average Price \t Age\n"); // header for data when printed
        /* prints values until we're at the end of the file */
        while (fscanf(corolla, "%lf %lf", &avgprice, &age) == 2) { // modified to read avgprice first, then age
            printf("$%.2f \t\t %.1f\n", avgprice, age); // prints data from file
        }
    }
    fclose(corolla); // closes file
    return 0;
}
