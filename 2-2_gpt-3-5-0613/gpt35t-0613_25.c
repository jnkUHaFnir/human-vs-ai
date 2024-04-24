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
    struct companyInfo *pdata = malloc(sizeof(struct companyInfo));
    strcpy(pdata->companyName, "sdfsd");

    // Access the data in the struct
    printf("Company Name: %s\n", pdata->companyName);

    // Free the allocated memory
    free(pdata);

    return 0;
}
