if (num == 1)
{
    do{
        printf("Podaj liczbe kondygnacji: ");
        scanf_s("%d", &m);
    } while (m < 0);
    do{
        printf("Podaj liczbe pomieszczen: ");
        scanf_s("%d", &n);
    } while (n < 0);
    tab1 = tworzenie(m, n); // Save pointer to allocated memory.
}
float** tworzenie(int m, int n)
{
    float **tab1;

    tab1 = (float**)malloc(m * sizeof(float*)); // Allocating rows 
    for (int i = 0; i < m; i++) // Iterate m times, not n.
    {
        tab1[i] = (float*)malloc(n * sizeof(float)); // Allocating columns for each row.
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
