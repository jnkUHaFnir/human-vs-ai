#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct companyInfo {
    double sharePrice;
    char companyName[100];
};

int main() {
    struct companyInfo *pdata = malloc(sizeof(struct companyInfo)); // Dynamically allocate memory

    if (pdata == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    strcpy(pdata->companyName, "sdfsd");

    // Print the copied value to verify
    printf("Company Name: %s\n", pdata->companyName);

    free(pdata); // Free the allocated memory

    return 0;
}
