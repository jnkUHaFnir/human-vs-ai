#include <stdio.h>

int main() {
    double age, avgprice;
    FILE *corolla;
    
    corolla = fopen("C:/Users/Nate/Downloads/DataFiles/corolla.txt", "r");
    if (corolla == NULL) {
        printf("File does not exist!\n");
        return 0;
    }
    else {
        printf("Age \t\t Average Price\n");
        while (fscanf(corolla, "%lf %lf", &age, &avgprice) == 2) { // Read both columns at once
            printf("%.1f \t\t $%.2f\n", age, avgprice);
        }
    }
    fclose(corolla);
    return 0;
}
