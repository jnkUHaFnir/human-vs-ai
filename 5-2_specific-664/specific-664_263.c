#include <stdio.h>

struct futbaler
{
    char ime[15];
    char prezime[20];
    char pozicija[15];
    char godiste[5]; // Increase the size to accommodate 4 characters and null terminator
};

void upis(struct futbaler* pok, int n)
{
    int i;

    for(i=0; i<n;i++)
    {
        printf("Ime igraca #%d: ",i+1);
        scanf("%14s",(pok+i)->ime); // Limit the input to 14 characters to avoid buffer overflow
        printf("Prezime igraca #%d: ",i+1);
        scanf("%19s",(pok+i)->prezime); // Limit the input to 19 characters to avoid buffer overflow
        printf("Pozicija igraca #%d: ",i+1);
        scanf("%14s",(pok+i)->pozicija); // Limit the input to 14 characters to avoid buffer overflow
        printf("Godiste igraca #%d: ",i+1);
        scanf("%4s",(pok+i)->godiste); // Limit the input to 4 characters to avoid buffer overflow
    }
}

void ispis(struct futbaler* pok, int n)
{
    int i;

    for(i=0; i<n;i++)
    {
        printf("\nIme igraca #%d je: %s\n",i+1,(*(pok+i)).ime);
        printf("\nPrezime igraca #%d je: %s\n",i+1,(*(pok+i)).prezime);
        printf("\nPozicija igraca #%d je: %s\n",i+1,(*(pok+i)).pozicija);
        printf("\nGodiste igraca #%d je: %s\n",i+1,(*(pok+i)).godiste);
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
