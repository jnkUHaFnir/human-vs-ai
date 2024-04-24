...
for (int i = 0; i < m; i++) // << Change 'n' to 'm' here
{
    tab1[i] = (float*)malloc(n * sizeof(float));
}
...
...
if (num == 1)
{
    ...
    tab1 = tworzenie(m, n);
}
...
// Function 'tworzenie' after correction
float** tworzenie(int m, int n)
{
    float **tab1;

    tab1 = (float**)malloc(m * sizeof(float*));
    for (int i = 0; i < m; i++) // Corrected loop bound
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

// Part of '_tmain' after correction
...
if (num == 1)
{
    ...
    tab1 = tworzenie(m, n); // Assigning the returned pointer
}
...
if (num == 2)
{
    if (tab1 == NULL)
    {
        printf("\n Brak budynku! Stworz nowy.\n");
    }
    else
    {
        wyswietlanie(tab1, m, n); // It should no longer crash.
    }
}
...
if (num == 0)
{
    for (int i = 0; i < m; i++)
    {
        free(tab1[i]);
    }
    free(tab1);
    break;
}
