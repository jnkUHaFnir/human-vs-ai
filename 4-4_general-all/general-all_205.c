#include <stdio.h>
#include <stdlib.h>

float** tworzenie(int m, int n)
{
    float **tab1 = (float**)malloc(m * sizeof(float*));
    if (tab1 == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1); // Exit if memory allocation fails
    }

    for (int i = 0; i < m; i++)
    {
        tab1[i] = (float*)malloc(n * sizeof(float));
        if (tab1[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(1); // Exit if memory allocation fails
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tab1[i][j] = 0;
            printf("%10.2f", tab1[i][j]); // You can print here as well
        }
        printf("\n");
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
        printf("1. Nowy budynek\n");
        printf("2. Wyswietl moc pobierana w pomieszczeniach\n");
        printf("3. Wlacz swiatlo\n");
        printf("4. Wylacz swiatlo\n");
        printf("0. Exit\n");
        scanf("%d", &num);

        if (num == 1)
        {
            do{
                printf("Podaj liczbe kondygnacji: ");
                scanf("%d", &m);
            } while (m < 0);
            do{
                printf("Podaj liczbe pomieszczen: ");
                scanf("%d", &n);
            } while (n < 0);

            tab1 = tworzenie(m, n);
        }

        if (num == 2)
        {
            if (tab1 == NULL)
            {
                printf("\nBrak budynku! Stworz nowy.\n");
            }
            else
            {
                wyswietlanie(tab1, m, n);
            }
        }

        // Add the handling of other options here

        if (num == 0)
        {
            for (int i = 0; i < m; i++)
            {
                free(tab1[i]);
            }
            free(tab1);
            break; // Exit the loop
        }
    }

    return 0;
}
