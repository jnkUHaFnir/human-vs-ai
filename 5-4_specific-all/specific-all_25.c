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
    struct companyInfo * pdata = malloc(sizeof(struct companyInfo));
    
    if (pdata != NULL) {
        strcpy(pdata->companyName, "sdfsd");

        // Print the copied value
        printf("Company Name: %s\n", pdata->companyName);
        
        free(pdata); // Free the allocated memory when done
    } else {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    return 0;
}
