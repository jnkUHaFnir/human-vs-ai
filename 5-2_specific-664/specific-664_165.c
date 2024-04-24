float** tworzenie(int m, int n)
{
    float **tab1;

    tab1 = (float**)malloc(m * sizeof(float*));
    for (int i = 0; i < m; i++) // Should be m, not n
    {
        tab1[i] = (float*)malloc(n * sizeof(float));
    }

    // Initialization loop is fine
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tab1[i][j] = 0;
        }
    }
    return tab1;
}
