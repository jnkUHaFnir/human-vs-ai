#include <stdio.h>
#include <stdlib.h>

float** tworzenie(int m, int n)
{
    float **tab1 = (float**)malloc(m * sizeof(float*));
    if (tab1 == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }

    for (int i = 0; i < m; i++)
    {
        tab1[i] = (float*)malloc(n * sizeof(float));
        if (tab1[i] == NULL) {
            printf("Memory allocation failed");
            exit(1);
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
        // Your menu logic here

        if (num == 1)
        {
            // Get m and n values
            tab1 = tworzenie(m, n); // Assign the return value from tworzenie to tab1
        }
        if (num == 2)
        {
            if (tab1 == NULL)
            {
                printf("\n Brak budynku! Stworz nowy.\n");
            }
            else {
                wyswietlanie(tab1, m, n);
            }
        }
        // Other menu options and logic here

        // Free the allocated memory before the program ends
        for (int i = 0; i < m; i++) {
            free(tab1[i]);
        }
        free(tab1);
    }

    return 0;
}
