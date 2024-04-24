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
    struct companyInfo *pdata = (struct companyInfo*)malloc(sizeof(struct companyInfo)); // Allocate memory for pdata
    if (pdata == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    strcpy(pdata->companyName, "sdfsd");
    
    // Use the data stored in the struct or free the allocated memory later
    
    free(pdata); // Don't forget to free the memory when done using it
    exit(0);
}
