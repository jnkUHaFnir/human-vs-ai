#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _SPerson {
    char *name;
    char *surname;
    char *id;
    char *telephone;
} SPerson;

int Load(SPerson Archive[], unsigned int *ne);

int main(void) {
    unsigned int ne;
    SPerson Archive[1000];
    Load(Archive, &ne);
    return 0;
}

int Load(SPerson Archive[], unsigned int *ne) {
    int i = 0;
    char s[4][20];
    FILE *f;
    f = fopen("archive.txt", "r");
    if (f == NULL) return 0;

    while (fscanf(f, "%19s %19s %19s %19s", s[0], s[1], s[2], s[3]) == 4) {
        Archive[i].id = strdup(s[0]);
        Archive[i].name = strdup(s[1]);
        Archive[i].surname = strdup(s[2]);
        Archive[i].telephone = strdup(s[3]);
        i++;
    }

    *ne = i;
    fclose(f);
    return 1;
}
