#include <stdio.h>
#include <string.h>

struct futbaler
{
    char ime[15];
    char prezime[20];
    char pozicija[15];
    char godiste[5]; // Increased buffer size to accommodate 4 characters and terminating null character
};

void upis(struct futbaler* pok, int n)
{
    int i;
    char temp[100]; // Temp variable to read input

    for(i = 0; i < n; i++)
    {
        printf("Ime igraca #%d: ", i+1);
        fgets(temp, 100, stdin);
        strncpy((pok+i)->ime, temp, 15); // Copy up to 15 characters
        (pok+i)->ime[15] = '\0'; // Null-terminate the string

        printf("Prezime igraca #%d: ", i+1);
        fgets(temp, 100, stdin);
        strncpy((pok+i)->prezime, temp, 20); // Copy up to 20 characters
        (pok+i)->prezime[20] = '\0'; // Null-terminate the string

        printf("Pozicija igraca #%d: ", i+1);
        fgets(temp, 100, stdin);
        strncpy((pok+i)->pozicija, temp, 15); // Copy up to 15 characters
        (pok+i)->pozicija[15] = '\0'; // Null-terminate the string

        printf("Godiste igraca #%d: ", i+1);
        fgets(temp, 100, stdin);
        strncpy((pok+i)->godiste, temp, 5); // Copy up to 4 characters (plus null terminator)
        (pok+i)->godiste[4] = '\0'; // Null-terminate the string
    }
}

void ispis(struct futbaler* pok, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("\nIme igraca #%d je: %s\n", i+1, (pok+i)->ime);
        printf("Prezime igraca #%d je: %s\n", i+1, (pok+i)->prezime);
        printf("Pozicija igraca #%d je: %s\n", i+1, (pok+i)->pozicija);
        printf("Godiste igraca #%d je: %s\n", i+1, (pok+i)->godiste);
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

    printf("%s", igraci[0].godiste);

    return 0;
}
