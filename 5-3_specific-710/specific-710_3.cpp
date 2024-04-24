#include <stdio.h>
#include <stdlib.h>

float** tworzenie(int m, int n)
{
    float** tab1;

    tab1 = (float**)malloc(m * sizeof(float*));
    for (int i = 0; i < m; i++) // <-- Changed the loop condition to 'm'
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

void wyswietlanie(float** tab1, int m, int n)
{
    for (int i = 0; i < m; i++) // <-- Fixed the loop to display from top to bottom
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
    float** tab1 = NULL;

    // Your menu and input code here
    
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

    // Your menu selections here

    return 0;
}
