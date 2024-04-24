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
    struct companyInfo * pdata;
    pdata = (struct companyInfo *)malloc(sizeof(struct companyInfo)); // Allocate memory

    if (pdata == NULL) { // Check for successful allocation
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    strcpy(pdata->companyName, "sdfsd"); // Now you can safely copy

    // Don't forget to free the allocated memory once you're done using it
    free(pdata);

    return 0;
}
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
    struct companyInfo data; // Declare a variable
    struct companyInfo * pdata = &data; // Get its address

    strcpy(pdata->companyName, "sdfsd"); // Now you can safely copy

    // Since it's not dynamically allocated, no need to free

    return 0;
}
