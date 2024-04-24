#include <stdio.h>
#include <stdlib.h>

struct futbaler
{
    char ime[15];
    char prezime[20];
    char pozicija[15];
    char* godiste; // dynamically allocated
};

void upis(struct futbaler* pok, int n)
{
    int i;
    char temp[4]; // temporary buffer for reading godiste

    for(i = 0; i < n; i++)
    {
        printf("Ime igraca #%d: ", i + 1);
        scanf("%s", (pok + i)->ime);
        printf("Prezime igraca #%d: ", i + 1);
        scanf("%s", (pok + i)->prezime);
        printf("Pozicija igraca #%d: ", i + 1);
        scanf("%s", (pok + i)->pozicija);
        
        // Read godiste as string and dynamically allocate memory
        printf("Godiste igraca #%d: ", i + 1);
        scanf("%s", temp);
        (pok + i)->godiste = strdup(temp);
    }
}

void ispis(struct futbaler* pok, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("\nIme igraca #%d je: %s\n", i + 1, (*(pok + i)).ime);
        printf("\nPrezime igraca #%d je: %s\n", i + 1, (*(pok + i)).prezime);
        printf("\nPozicija igraca #%d je: %s\n", i + 1, (*(pok + i)).pozicija);
        printf("\nGodiste igraca #%d je: %s\n", i + 1, (*(pok + i)).godiste);
    }
}

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

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(igraci[i].godiste);
    }

    return 0;
}
