#include <stdio.h>

struct futbaler
{
    char ime[15];
    char prezime[20];
    char pozicija[15];
    char godiste[5];  // Increased size to accommodate 4 characters + null terminator
};

void upis(struct futbaler* pok, int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        printf("Ime igraca #%d: ", i+1);
        scanf("%14s", (pok+i)->ime);  // Specifying max input size as 14
        printf("Prezime igraca #%d: ", i+1);
        scanf("%19s", (pok+i)->prezime); // Specifying max input size as 19
        printf("Pozicija igraca #%d: ", i+1);
        scanf("%14s", (pok+i)->pozicija); // Specifying max input size as 14
        printf("Godiste igraca #%d: ", i+1);
        scanf("%4s", (pok+i)->godiste); // Specifying max input size as 4
    }
}

void ispis(struct futbaler* pok, int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        printf("\nIme igraca #%d je: %s\n", i+1, (*(pok+i)).ime);
        printf("Prezime igraca #%d je: %s\n", i+1, (*(pok+i)).prezime);
        printf("Pozicija igraca #%d je: %s\n", i+1, (*(pok+i)).pozicija);
        printf("Godiste igraca #%d je: %s\n", i+1, (*(pok+i)).godiste);
    }
}

int main()
{
    int n;
    printf("Koliko bi igraca uneli? ");
    scanf("%d", &n);
    struct futbaler igraci[n];
    struct futbaler* pok = igraci;
    upis(pok, n);
    ispis(pok, n);

    printf("%s", igraci[0].godiste);

    return 0;
}
