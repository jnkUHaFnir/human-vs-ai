#include <stdio.h>

int main() {

    double age, avgprice; // age = 1st column, avgprice = 2nd column
    FILE *corolla; // ptr for file

    corolla = fopen("C:/Users/Nate/Downloads/DataFiles/corolla.txt", "r");
    if (corolla == NULL) { // makes sure the file exists
        printf("File does not exist!\n");
        return 0; // prevents crashing
    } else {
        printf("Age \t\t Average Price\n"); // header for data when printed

        // Read one number at a time and alternate between age and avgprice
        while (fscanf(corolla, "%lf", &age) == 1) {
            if (fscanf(corolla, "%lf", &avgprice) == 1) {
                printf("%.1f \t\t $%.2f\n", age, avgprice); // prints data from file
            } else {
                printf("Incomplete data entry for age %.1f\n", age);
                break; // exit the loop if data is incomplete
            }
        }
    }
    fclose(corolla); // closes file
    return 0;
}
