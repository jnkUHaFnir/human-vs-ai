#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[10];
    double b = 0, a;
    int n, i;
    
    printf("limit of n input: ");
    fgets(input, sizeof(input), stdin);
    n = atoi(input);

    for (i = 1; i <= n; i++) {
        char numInput[20];
        printf("Enter a number: ");
        fgets(numInput, sizeof(numInput), stdin);
        a = atof(numInput);
        
        if (a > b) {
            b = a;
        }
    }

    printf("%.2lf", b);

    return 0;
}
