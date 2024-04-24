#include <stdio.h>

struct futbaler
{
    char ime[15];
    char prezime[20];
    char pozicija[15];
    int godiste; // Changed to int for storing the year as an integer
};

void upis(struct futbaler* pok, int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        printf("Ime igraca #%d: ", i+1);
        scanf("%s", (pok+i)->ime);
        printf("Prezime igraca #%d: ", i+1);
        scanf("%s", (pok+i)->prezime);
        printf("Pozicija igraca #%d: ", i+1);
        scanf("%s", (pok+i)->pozicija);
        printf("Godiste igraca #%d: ", i+1);
        scanf("%d", &(pok+i)->godiste); // Changed to %d for reading integer
    }
}

void ispis(struct futbaler* pok, int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        printf("\nIme igraca #%d je: %s\n", i+1, (*(pok+i)).ime);
        printf("\nPrezime igraca #%d je: %s\n", i+1, (*(pok+i)).prezime);
        printf("\nPozicija igraca #%d je: %s\n", i+1, (*(pok+i)).pozicija);
        printf("\nGodiste igraca #%d je: %d\n", i+1, (*(pok+i)).godiste); // Changed to %d for integer
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

    return 0;
}
