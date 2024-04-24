#include <stdio.h>

int main() {
    double age, avgprice; 
    FILE *corolla; 
    char eof;

    corolla = fopen("corolla.txt", "r");
    if (corolla == NULL) { 
        printf("File does not exist!\n");
        return 0; 
    }
    else {
        printf("Age \t\t Average Price\n"); 
        while (fscanf(corolla, "%c", &eof) != EOF) {
            fscanf(corolla, "%lf %lf", &avgprice, &age); // Updated format specifier
            printf("%.1f \t\t $%.2f\n", age, avgprice); 
        }
    }
    fclose(corolla); 
    return 0;
}
