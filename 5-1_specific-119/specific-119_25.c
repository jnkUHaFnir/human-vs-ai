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
    struct companyInfo *pdata = (struct companyInfo*)malloc(sizeof(struct companyInfo));
    
    if(pdata == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    strcpy(pdata->companyName, "sdfsd");

    // Do some processing with pdata here

    free(pdata); // Don't forget to free the allocated memory

    return 0;
}
