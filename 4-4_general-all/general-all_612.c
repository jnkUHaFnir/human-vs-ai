#include <stdio.h>

int main() {
    double age, avgprice; // age = 1st column, avgprice = 2nd column
    FILE *corolla; // pointer for the file

    corolla = fopen("corolla.txt", "r");
    if (corolla == NULL) { // check if the file exists
        printf("File does not exist!\n");
        return 1; // return error
    }
    else {
        printf("Age \t\t Average Price\n");
        while (fscanf(corolla, "%lf %lf", &age, &avgprice) == 2) { // read two doubles at a time
            printf("%.1f \t\t $%.2f\n", age, avgprice);
        }
    }
    fclose(corolla);
    return 0;
}
