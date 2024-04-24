#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct companyInfo
{
    double sharePrice;
    char companyName[100];
};

int main()
{
    struct companyInfo data; // Allocate memory for the struct
    struct companyInfo *pdata = &data; // Point to the allocated memory

    strcpy(pdata->companyName, "sdfsd");

    // Printing the copied value to verify
    printf("Company Name: %s\n", pdata->companyName);

    return 0;
}
