#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct companyInfo
{
    double sharePrice;
    char companyName[100];
}; 

int main()
{
    struct companyInfo * pdata = malloc(sizeof(struct companyInfo)); // Allocate memory for the struct

    if (pdata == NULL) {
        printf("Failed to allocate memory\n");
        exit(1);
    }

    strcpy(pdata->companyName, "sdfsd"); // Copy value into struct

    // Use pdata here

    free(pdata); // Free memory when done

    return 0;
}
