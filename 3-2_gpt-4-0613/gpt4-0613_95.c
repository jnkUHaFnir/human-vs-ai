#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *deleteLastChar(char* s)
{
    int rozmiar, i;
    char *tab1;

    rozmiar = strlen(s);
    tab1 = (char*) malloc(rozmiar * sizeof(char));
    if (tab1 == NULL)
        return NULL;
        
    for(i=0; i < rozmiar-1; i++)
    {
        tab1[i] = s[i];
    }
    
    tab1[i] = '\0';
    free(s);
       
    return tab1;
}

int main()
{
    char tab1[100], *tab2;
    int l,i;
    
    printf("podaj napis\n");
    fgets(tab1, 100, stdin);
    
    l = strlen(tab1);     
    tab2 = malloc(l * sizeof(char));
    if(tab2==NULL)
    {
        printf("blad");
        return -1;
    }
    
    strncpy(tab2, tab1, l);
    tab2[l-1] = '\0';
    
    for(i = 0; i < l-1; i++)
    {
        tab2 = deleteLastChar(tab2);
        if (tab2 == NULL)
        {
            printf("blad");
            return -1;
        }
        printf("%s\n", tab2);
    }
    
    free(tab2);
    return 0;
}
