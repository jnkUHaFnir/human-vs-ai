    int main(void)
    {
        char fInName[50];
        char fOutName[50];
        printf("pleas type input file, and output file please type legibly\n ");
    
        scanf("%s %s", fInName, fOutName);
        FILE *fin = fopen(fInName, "r");
        FILE *fout = fopen(fOutName, "r");
    
        if (fin == NULL)
        {
            printf("Error: Cannot open input file %s.", fInName);
        }
        else
        {
            printf("file found");
        }
    }