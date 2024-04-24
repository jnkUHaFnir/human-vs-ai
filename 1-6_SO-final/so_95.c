    char *deleteLastChar(char* s)
    {
        int rozmiar,i;
        char *tab1;
        rozmiar = strlen(s);
        if(rozmiar == 0)
            return NULL;
        tab1 = malloc(rozmiar);
        for (i = 0 ; i < (rozmiar - 1) ; i++)
        {
            tab1[i] = s[i];
        }
        tab1[rozmiar - 1] = '\0';
        free(s);
        return tab1;
    }
    int main()
    {
        char tab1[ROZ], *tab2;
        int l, i, p, a;
        printf("podaj napis\n");
        fgets(tab1, 100, stdin);
        l    = strlen(tab1);
        tab2 = malloc(1 + l);
        if (tab2 == NULL)
            printf("blad");
        strcpy(tab2, tab1);
        for(i = 0 ; i < l ; i++)
        {
            tab2 = deleteLastChar(tab2);
            if (tab2 != NULL)
            {
                p = strlen(tab2);
                for (a = 0 ; a < p ; a++)
                {
                    printf("%c", tab2[a]);
                }
                printf("\n");
            }
        }
        free(tab2);
        
        return 0;
    }