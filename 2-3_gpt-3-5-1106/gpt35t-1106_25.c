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
    struct companyInfo * pdata = malloc(sizeof(struct companyInfo)); // Allocate memory for the pdata pointer

    if (pdata == NULL) // Check if memory allocation was successful
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    strcpy(pdata->companyName, "sdfsd");

    free(pdata); // Free the allocated memory before exiting the program
    exit(0);
}
