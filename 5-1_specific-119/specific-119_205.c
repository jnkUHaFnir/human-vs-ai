int _tmain(int argc, _TCHAR* argv[])
{
    int m, n, num;
    float **tab1 = NULL;
    for (;;)
    {
        // Your existing code ...

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

            tab1 = tworzenie(m, n); // Update tab1 with the return value of tworzenie
        }

        // Your existing code ...

    }

    return 0;
}
