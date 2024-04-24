#include <stdio.h>
#include <stdlib.h>

// Declare the function prototypes
float** tworzenie(int m, int n);
void wyswietlanie(float **tab1, int m, int n);

int main(int argc, char* argv[])
{
    int m, n, num;
    float **tab1 = NULL;

    for (;;)
    {
        // Your menu code here...

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
            // Make sure to update tab1 with the return value from tworzenie
            if (tab1 != NULL) {
                // Free previous building before creating a new one
                for (int i = 0; i < m; i++) {
                    free(tab1[i]);
                }
                free(tab1);
            }
            tab1 = tworzenie(m, n);
        }
        if (num == 2)
        {
            // Checking and printing inside the loop corrected
            if (tab1 == NULL)
            {
                printf("\n Brak budynku! Stworz nowy.\n");
            }
            else
                wyswietlanie(tab1, m, n);
        }
        // Handle other options...
        if (num == 0)
        {
            // Free memory before exiting
            if (tab1 != NULL) {
                for(int i = 0; i < m; i++) {
                    free(tab1[i]);
                }
                free(tab1);
            }
            break; // Exit the loop
        }
    }

    return 0;
}

float** tworzenie(int m, int n)
{
    float **tab1;

    tab1 = (float**)malloc(m * sizeof(float*));
    for (int i = 0; i < m; i++) // Fixed loop condition
    {
        tab1[i] = (float*)malloc(n * sizeof(float));
        for (int j = 0; j < n; j++) // Initialize values right after allocation
        {
            tab1[i][j] = 0;
        }
    }

    return tab1;
}

void wyswietlanie(float **tab1, int m, int n)
{
    // Your wyswietlanie function here (unchanged)
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%10.2f", tab1[i][j]);
        }
        printf("\n");
    }
}
