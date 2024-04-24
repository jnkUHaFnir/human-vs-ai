#include <stdio.h>

int main() {
    double age, avgprice;
    FILE *corolla;
    
    corolla = fopen("C:/Users/Nate/Downloads/DataFiles/corolla.txt", "r");
    if (corolla == NULL) {
        printf("File does not exist!\n");
        return 1; // return a non-zero value to indicate an error
    }
    
    printf("Age \t\t Average Price\n");
    
    while (fscanf(corolla, "%lf %lf", &age, &avgprice) == 2) {
        printf("%.1f \t\t $%.2f\n", age, avgprice);
    }
    
    fclose(corolla);
    return 0;
}
