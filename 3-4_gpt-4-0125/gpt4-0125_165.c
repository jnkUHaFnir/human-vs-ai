if (num == 1)
{
    // Input gathering logic remains the same...
    tab1 = tworzenie(m, n); // Update tab1 with the new matrix.
}
float** tworzenie(int m, int n)
{
    float **tab1;
    tab1 = (float**)malloc(m * sizeof(float*));
    for (int i = 0; i < m; i++)  // FIX: Loop should iterate over `m` (rows)
    {
        tab1[i] = (float*)malloc(n * sizeof(float));
    }

    // Initialization loop remains the same...

    return tab1;
}
