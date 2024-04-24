tab1 = tworzenie(m, n);
int _tmain(int argc, _TCHAR* argv[])
{
    int m, n, num;
    float **tab1 = NULL;
    for (;;)
    {

        printf("\n1. Nowy budynek");
        printf("\n2. Wyswietl moc pobierana w pomieszczeniach");
        printf("\n3. Wlacz swiatlo");
        printf("\n4. Wylacz swiatlo");
        printf("\n0. Exit\n");
        scanf_s("%d", &num);

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
            tab1 = tworzenie(m, n); // Assign the returned value to tab1
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%10.2f", tab1[i][j]);
            }
            printf("\n");
        }
        if (num == 2)
        {
            if (tab1 == NULL)
            {
                printf("\n Brak budynku! Stworz nowy.\n");
            }
            else
                wyswietlanie(tab1, m, n); <- it crashes here.
        }
        if (num == 3)
        {
            if (tab1 == NULL)
            {
                printf("\n Brak budynku! Stworz nowy.\n");
            }
            else
                wlaczanie(tab1, m, n);
        }
        if (num == 4)
        {
            if (tab1 == NULL)
            {
                printf("\n Brak budynku! Stwórz nowy.");
            }
            //else
            //wylaczanie(tab1,m, n);
        }
        if (num == 0)
        {
            //      exit(tab1,m, n);
        }
    }


    return 0;

}
