#include <stdio.h>

struct futbaler
{
    char ime[16];      // increased by 1 for null terminator
    char prezime[21];  // increased by 1 for null terminator
    char pozicija[16]; // increased by 1 for null terminator
    char godiste[5];   // increased by 1 for null terminator
};

void upis(struct futbaler* pok, int n)
{
    int i;

    for(i=0; i<n;i++)
    {
        printf("Ime igraca #%d: ",i+1);
        scanf("%15s", (pok+i)->ime);
        printf("Prezime igraca #%d: ",i+1);
        scanf("%20s", (pok+i)->prezime);
        printf("Pozicija igraca #%d: ",i+1);
        scanf("%15s", (pok+i)->pozicija);
        printf("Godiste igraca #%d: ",i+1);
        scanf("%4s", (pok+i)->godiste);
    }
}

void ispis(struct futbaler* pok, int n)
{
    int i;

    for(i=0; i<n;i++)
    {
        printf("\nIme igraca #%d je: %s\n",i+1, (*(pok+i)).ime);
        printf("\nPrezime igraca #%d je: %s\n",i+1, (*(pok+i)).prezime);
        printf("\nPozicija igraca #%d je: %s\n",i+1, (*(pok+i)).pozicija);
        printf("\nGodiste igraca #%d je: %s\n",i+1, (*(pok+i)).godiste);
    }
}

int main()
{
    int n;
    printf("Koliko bi igraca uneli? ");
    scanf("%d",&n);
    struct futbaler* pok;
    struct futbaler igraci[n];
    pok = igraci;
    upis(pok,n);
    ispis(pok,n);

    printf("%s",igraci[0].godiste);

    return 0;
}
