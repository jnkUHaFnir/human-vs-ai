#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *deleteLastChar(char *s)
{
    int i, len = strlen(s);

    char *tab1 = (char *)malloc((len) * sizeof(char));
    if (tab1 == NULL)
    {
        printf("Error in memory allocation\n");
        exit(1);
    }

    for (i = 0; i < (len - 1); i++)
    {
        tab1[i] = s[i];
    }
    tab1[len - 1] = '\0';
    return tab1;
}

int main()
{
    char tab1[100], *tab2;
    int l, i, p, a;

    printf("Enter a string:\n");
    fgets(tab1, 100, stdin);

    l = strlen(tab1);
    if (tab1[l - 1] == '\n')
    {
        tab1[l - 1] = '\0';
        l--;
    }

    tab2 = strdup(tab1);

    for (i = 0; i < l; i++)
    {
        printf("%s\n", tab2);
        char *newTab2 = deleteLastChar(tab2);
        free(tab2);
        tab2 = newTab2;
    }

    free(tab2);

    return 0;
}
