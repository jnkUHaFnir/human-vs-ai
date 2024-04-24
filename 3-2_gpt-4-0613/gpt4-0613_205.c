...
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
    tab1 = tworzenie(m, n); // capture returned 2D array
}
...
...
    tab1 = (float**)malloc(m * sizeof(float*));
    for (int i = 0; i < m; i++) // changed n to m
    {
        tab1[i] = (float*)malloc(n * sizeof(float));
    }
...
