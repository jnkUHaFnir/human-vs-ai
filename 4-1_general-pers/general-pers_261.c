#include <stdio.h>
#include <string.h>

struct futbaler {
    char ime[15];
    char prezime[20];
    char pozicija[15];
    char godiste[5]; // Increased size to accommodate the null terminator
};

void upis(struct futbaler* pok, int n) {
    int i;
    char buffer[100]; // Temporary buffer to handle input

    for (i = 0; i < n; i++) {
        printf("Ime igraca #%d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
        strncpy((pok + i)->ime, buffer, sizeof((pok + i)->ime));

        printf("Prezime igraca #%d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        strncpy((pok + i)->prezime, buffer, sizeof((pok + i)->prezime));

        printf("Pozicija igraca #%d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        strncpy((pok + i)->pozicija, buffer, sizeof((pok + i)->pozicija));

        printf("Godiste igraca #%d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        strncpy((pok + i)->godiste, buffer, sizeof((pok + i)->godiste));
    }
}

void ispis(struct futbaler* pok, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nIme igraca #%d je: %s\n", i + 1, (pok + i)->ime);
        printf("\nPrezime igraca #%d je: %s\n", i + 1, (pok + i)->prezime);
        printf("\nPozicija igraca #%d je: %s\n", i + 1, (pok + i)->pozicija);
        printf("\nGodiste igraca #%d je: %s\n", i + 1, (pok + i)->godiste);
    }
}

int main() {
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
