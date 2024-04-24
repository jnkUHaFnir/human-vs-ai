struct futbaler
{
    char ime[15];
    char prezime[20];
    char pozicija[15];
    char godiste[5];
};
int main()
{
    int n;
    printf("Koliko bi igraca uneli? ");
    scanf("%d", &n);

    struct futbaler* pok;
    struct futbaler igraci[n];
    pok = igraci;

    upis(pok, n);
    ispis(pok, n);

    printf("%s", igraci[0].godiste);

    return 0;
}
