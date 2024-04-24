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
    FILE *f;
    f = fopen("archive.txt", "r");

    if (f == NULL) {
        return 0;
    }

    while (fscanf(f, "%ms %ms %ms %ms", &Archive[i].id, &Archive[i].name, &Archive[i].surname, &Archive[i].telephone) == 4) {
        i++;
    }

    *ne = i;
    fclose(f);
    return 1;
}
