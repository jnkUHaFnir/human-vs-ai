for (int i = 0; i < m; i++)
{
    tab1[i] = (float*)malloc(n * sizeof(float));
}
tab1 = tworzenie(m, n);
for (int i = 0; i < m; i++)
{
    free(tab1[i]);
}
free(tab1);
