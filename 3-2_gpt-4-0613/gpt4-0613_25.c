typedef struct companyInfo
{
    double sharePrice;
    char companyName[100];
} CompanyInfo;

int main()
{
    CompanyInfo * pdata = malloc(sizeof(CompanyInfo)); // allocate memory
    if(pdata == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    strcpy(pdata->companyName, "sdfsd");
    free(pdata); // when you don't need the data anymore

    return 0;
}
