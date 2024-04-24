#include <stdio.h>
#include <stdlib.h>

float** tworzenie(int m, int n)
{
    float **tab1;

    tab1 = (float**)malloc(m * sizeof(float*));
    for (int i = 0; i < m; i++) // <--- correction here: outer loop should be up to m, not n
    {
        tab1[i] = (float*)malloc(n * sizeof(float));
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
    for (int i = m - 1; i >= 0; i--)
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
        printf("\n3. Wlacz swiatlo");
        printf("\n4. Wylacz swiatlo");
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
            tab1 = tworzenie(m, n); // <--- assign the returned pointer to tab1
        }

        if (num == 2)
        {
            if (tab1 == NULL)
            {
                printf("\n Brak budynku! Stworz nowy.\n");
            }
            else
                wyswietlanie(tab1, m, n);
        }

        // Add handling for other menu options here

        if (num == 0)
        {
            // Free memory for tab1 before exiting
            for (int i = 0; i < m; i++)
            {
                free(tab1[i]);
            }
            free(tab1);
            break;
        }
    }

    return 0;
}
