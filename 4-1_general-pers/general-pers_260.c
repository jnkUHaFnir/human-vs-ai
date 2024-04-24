#include <stdio.h>
#include <string.h>

struct futbaler
{
    char ime[15];
    char prezime[20];
    char pozicija[15];
    char godiste[4];
};

void upis(struct futbaler* pok, int n)
{
    int i;
    char temp[100]; // Temporary buffer for input

    for(i = 0; i < n; i++)
    {
        printf("Ime igraca #%d: ", i+1);
        fgets(temp, sizeof(temp), stdin);
        sscanf(temp, "%14[^\n]", (pok + i)->ime);

        printf("Prezime igraca #%d: ", i+1);
        fgets(temp, sizeof(temp), stdin);
        sscanf(temp, "%19[^\n]", (pok + i)->prezime);

        printf("Pozicija igraca #%d: ", i+1);
        fgets(temp, sizeof(temp), stdin);
        sscanf(temp, "%14[^\n]", (pok + i)->pozicija);

        printf("Godiste igraca #%d: ", i+1);
        fgets(temp, sizeof(temp), stdin);
        sscanf(temp, "%3[^\n]", (pok + i)->godiste);
    }
}

void ispis(struct futbaler* pok, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("\nIme igraca #%d je: %s\n", i+1, (pok + i)->ime);
        printf("Prezime igraca #%d je: %s\n", i+1, (pok + i)->prezime);
        printf("Pozicija igraca #%d je: %s\n", i+1, (pok + i)->pozicija);
        printf("Godiste igraca #%d je: %s\n", i+1, (pok + i)->godiste);
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

    return 0;
}
