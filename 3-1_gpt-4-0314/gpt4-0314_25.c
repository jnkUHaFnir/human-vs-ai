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
    struct companyInfo * pdata = (struct companyInfo *) malloc(sizeof(struct companyInfo));
    if (pdata == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    strcpy(pdata->companyName, "sdfsd");
    
    printf("Company Name: %s\n", pdata->companyName);

    free(pdata);
    exit(0);
}
