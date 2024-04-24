#include <stdio.h>
#include <stdlib.h>

float** tworzenie(int m, int n)
{
    float **tab1 = (float**)malloc(m * sizeof(float*));
    if (tab1 == NULL) {
        printf("Memory allocation failed for tab1\n");
        return NULL;
    }

    for (int i = 0; i < m; i++)
    {
        tab1[i] = (float*)malloc(n * sizeof(float));
        if (tab1[i] == NULL) {
            printf("Memory allocation failed for tab1[%d]\n", i);
            for (int j = 0; j < i; j++) {
                free(tab1[j]);
            }
            free(tab1);
            return NULL;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tab1[i][j] = 0;
        }
    }
    return tab1;
}

void wyswietlanie(float **tab1, int m, int n)
{
    if (tab1 == NULL) {
        printf("\nBrak budynku! Stworz nowy.\n");
        return;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%10.2f", tab1[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m, n, num;
    float **tab1 = NULL;

    for (;;)
    {
        printf("\n1. Nowy budynek");
        printf("\n2. Wyswietl moc pobierana w pomieszczeniach");
        printf("\n0. Exit\n");
        scanf("%d", &num);

        if (num == 1)
        {
            do {
                printf("Podaj liczbe kondygnacji: ");
                scanf("%d", &m);
            } while (m < 0);
            do {
                printf("Podaj liczbe pomieszczen: ");
                scanf("%d", &n);
            } while (n < 0);
            tab1 = tworzenie(m, n);
        }

        if (num == 2)
        {
            wyswietlanie(tab1, m, n);
        }

        if (num == 0)
        {
            // Free allocated memory before exiting
            for (int i = 0; i < m; i++) {
                free(tab1[i]);
            }
            free(tab1);
            return 0;
        }
    }

    return 0;
}
