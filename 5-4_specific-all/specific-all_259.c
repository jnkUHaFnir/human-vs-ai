#include <stdio.h>
#include <string.h>

struct futbaler {
    char ime[15];
    char prezime[20];
    char pozicija[15];
    char godiste[5]; // Increase size to 5 to accommodate 4 characters and '\0'
};

void upis(struct futbaler* pok, int n) {
    int i;
    char temp[256]; // Temporary buffer for input

    for(i = 0; i < n; i++) {
        printf("Ime igraca #%d: ", i + 1);
        fgets((pok + i)->ime, sizeof((pok + i)->ime), stdin);

        printf("Prezime igraca #%d: ", i + 1);
        fgets((pok + i)->prezime, sizeof((pok + i)->prezime), stdin);

        printf("Pozicija igraca #%d: ", i + 1);
        fgets((pok + i)->pozicija, sizeof((pok + i)->pozicija), stdin);

        printf("Godiste igraca #%d: ", i + 1);
        fgets(temp, sizeof(temp), stdin); // Read into temporary buffer
        temp[strcspn(temp, "\n")] = 0; // Remove newline character if present
        strncpy((pok + i)->godiste, temp, sizeof((pok + i)->godiste)); // Copy to godiste
    }
}

void ispis(struct futbaler* pok, int n) {
    int i;

    for(i = 0; i < n; i++) {
        printf("\nIme igraca #%d je: %s\n", i + 1, (pok + i)->ime);
        printf("Prezime igraca #%d je: %s\n", i + 1, (pok + i)->prezime);
        printf("Pozicija igraca #%d je: %s\n", i + 1, (pok + i)->pozicija);
        printf("Godiste igraca #%d je: %s\n", i + 1, (pok + i)->godiste);
    }
}

int main() {
    int n;
    printf("Koliko bi igraca uneli? ");
    scanf("%d", &n);
    struct futbaler igraci[n];
    upis(igraci, n);
    ispis(igraci, n);

    printf("%s", igraci[0].godiste);

    return 0;
}
