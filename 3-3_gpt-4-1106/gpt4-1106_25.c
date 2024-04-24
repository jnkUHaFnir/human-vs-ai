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
    if (pdata == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    strcpy(pdata->companyName, "sdfsd");

    // Ensure you free the allocated memory when you're done with it
    free(pdata);

    exit(EXIT_SUCCESS);
}
strncpy(pdata->companyName, "sdfsd", sizeof(pdata->companyName) - 1);
pdata->companyName[sizeof(pdata->companyName) - 1] = '\0'; // Ensure null-termination
