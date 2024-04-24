#include <stdio.h>

struct futbaler
{
    char ime[15];
    char prezime[20];
    char pozicija[15];
    char godiste[5]; // Increased size to 5 to accommodate 4 characters for year and 1 for null terminator
};

void upis(struct futbaler* pok, int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        printf("Ime igraca #%d: ", i + 1);
        scanf("%14s", (pok + i)->ime); // Limit input to 14 characters
        printf("Prezime igraca #%d: ", i + 1);
        scanf("%19s", (pok + i)->prezime); // Limit input to 19 characters
        printf("Pozicija igraca #%d: ", i + 1);
        scanf("%14s", (pok + i)->pozicija); // Limit input to 14 characters
        printf("Godiste igraca #%d: ", i + 1);
        scanf("%4s", (pok + i)->godiste); // Limit input to 4 characters
    }
}

void ispis(struct futbaler* pok, int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        printf("\nIme igraca #%d je: %s\n", i + 1, (pok + i)->ime);
        printf("\nPrezime igraca #%d je: %s\n", i + 1, (pok + i)->prezime);
        printf("\nPozicija igraca #%d je: %s\n", i + 1, (pok + i)->pozicija);
        printf("\nGodiste igraca #%d je: %s\n", i + 1, (pok + i)->godiste);
    }
}

int main()
{
    int n;
    printf("Koliko bi igraca uneli? ");
    scanf("%d", &n);
    struct futbaler igraci[n];
    upis(igraci, n);
    ispis(igraci, n);

    printf("%s", igraci[0].godiste);
    
    return 0;
}
