#include <stdio.h>
#include <string.h>

struct futbaler
{
    char ime[15];
    char prezime[20];
    char pozicija[15];
    char godiste[5]; // Increased the size to 5 to accommodate 4 characters and the null terminator
};

void upis(struct futbaler* pok, int n)
{
    int i;
    char buffer[256]; // Adjust the buffer size as needed

    for(i = 0; i < n; i++)
    {
        printf("Ime igraca #%d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove '\n' from the end
        strncpy((pok + i)->ime, buffer, sizeof((pok + i)->ime));

        printf("Prezime igraca #%d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy((pok + i)->prezime, buffer, sizeof((pok + i)->prezime));

        printf("Pozicija igraca #%d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy((pok + i)->pozicija, buffer, sizeof((pok + i)->pozicija));

        printf("Godiste igraca #%d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy((pok + i)->godiste, buffer, sizeof((pok + i)->godiste));
    }
}

void ispis(struct futbaler* pok, int n)
{
    int i;

    for(i = 0; i < n; i++)
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

    printf("%s\n", igraci[0].godiste);

    return 0;
}
