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
            tab1 = tworzenie(m, n);  // Update the tab1 pointer
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%10.2f", tab1[i][j]);
            }
            printf("\n");
        }
        ...
    }
    return 0;
}
