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

    // Assign the returned 2D array from tworzenie back to tab1
    tab1 = tworzenie(m, n);
}
