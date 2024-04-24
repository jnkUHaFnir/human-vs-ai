int _tmain(int argc, _TCHAR* argv[])
{
    int m, n, num;
    float **tab1 = NULL;
    for (;;)
    {
        /* Your menu code */

        if (num == 1)
        {
            do {
                printf("Podaj liczbe kondygnacji: ");
                scanf_s("%d", &m);
            } while (m < 0);
            do {
                printf("Podaj liczbe pomieszczen: ");
                scanf_s("%d", &n);
            } while (n < 0);
            tab1 = tworzenie(m, n); // Assign the returned array to tab1
        }
        
        if (num == 2)
        {
            if (tab1 == NULL)
            {
                printf("\n Brak budynku! Stworz nowy.\n");
            }
            else
                wyswietlanie(tab1, m, n);
        }
        /* Your remaining menu code */
    }

    return 0;
}

float** tworzenie(int m, int n)
{
    float **tab1;

    tab1 = (float**)malloc(m * sizeof(float*));
    for (int i = 0; i < m; i++)
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
