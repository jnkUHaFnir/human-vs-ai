#include <stdio.h>

struct futbaler {
    char ime[15];
    char prezime[20];
    char pozicija[15];
    int godiste;
};

void upis(struct futbaler* pok, int n) {
    int i;

    for(i = 0; i < n; i++) {
        printf("Ime igraca #%d: ", i + 1);
        scanf("%s", (pok + i)->ime);
        printf("Prezime igraca #%d: ", i + 1);
        scanf("%s", (pok + i)->prezime);
        printf("Pozicija igraca #%d: ", i + 1);
        scanf("%s", (pok + i)->pozicija);
        printf("Godiste igraca #%d: ", i + 1);
        scanf("%d", &(pok + i)->godiste);
    }
}

void ispis(struct futbaler* pok, int n) {
    int i;

    for(i = 0; i < n; i++) {
        printf("\nIme igraca #%d je: %s\n", i + 1, (pok + i)->ime);
        printf("Prezime igraca #%d je: %s\n", i + 1, (pok + i)->prezime);
        printf("Pozicija igraca #%d je: %s\n", i + 1, (pok + i)->pozicija);
        printf("Godiste igraca #%d je: %d\n", i + 1, (pok + i)->godiste);
    }
}

int main() {
    int n;
    printf("Koliko bi igraca uneli? ");
    scanf("%d", &n);
    
    struct futbaler igraci[n];
    upis(igraci, n);
    ispis(igraci, n);

    return 0;
}
