#include <stdio.h>

struct futbaler {
    char ime[15];
    char prezime[20];
    char pozicija[15];
    char godiste[5]; // Increased size to accommodate 4 characters + null terminator
};

void upis(struct futbaler* pok, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("Ime igraca #%d: ", i + 1);
        scanf("%14s", (pok + i)->ime); // Limit input to 14 characters to prevent buffer overflow
        printf("Prezime igraca #%d: ", i + 1);
        scanf("%19s", (pok + i)->prezime); // Limit input to 19 characters to prevent buffer overflow
        printf("Pozicija igraca #%d: ", i + 1);
        scanf("%14s", (pok + i)->pozicija); // Limit input to 14 characters to prevent buffer overflow
        printf("Godiste igraca #%d: ", i + 1);
        scanf("%4s", (pok + i)->godiste); // Limit input to 4 characters to prevent buffer overflow
    }
}

void ispis(struct futbaler* pok, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("\nIme igraca #%d je: %s\n", i + 1, (*(pok + i)).ime);
        printf("Prezime igraca #%d je: %s\n", i + 1, (*(pok + i)).prezime);
        printf("Pozicija igraca #%d je: %s\n", i + 1, (*(pok + i)).pozicija);
        printf("Godiste igraca #%d je: %s\n", i + 1, (*(pok + i)).godiste);
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
