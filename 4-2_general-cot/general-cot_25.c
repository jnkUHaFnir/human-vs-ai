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
    struct companyInfo * pdata = (struct companyInfo *)malloc(sizeof(struct companyInfo));
    
    if(pdata == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    strcpy(pdata->companyName, "sdfsd");

    // Do something with pdata

    free(pdata); // Don't forget to free the allocated memory

    return 0;
}
