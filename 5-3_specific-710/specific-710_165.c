float** tworzenie(int m, int n)
{
    float **tab1;

    tab1 = (float**)malloc(m * sizeof(float*)); // Allocate m pointers for rows

    for (int i = 0; i < m; i++)
    {
        tab1[i] = (float*)malloc(n * sizeof(float)); // Allocate n floats for each row
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
    for (int i = 0; i < m; i++) // Start from 0 instead of m-1
    {
        for (int j = 0; j < n; j++)
        {
            printf("%10.2f", tab1[i][j]);
        }
        printf("\n");
    }
}
