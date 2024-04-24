#include <stdio.h>
#include <stdlib.h>

typedef struct sask {
    char vard[256];
    char pav[256];
    int num;
    double suma;
    char val[5];
} sask;

void read_file(int *sk, sask **mas) {
    FILE *data = fopen("data.txt", "r");

    if (data != NULL) {
        fscanf(data, "%d", sk);
        printf("%d\n", *sk);

        *mas = realloc(*mas, *sk * sizeof(sask));

        for (int i = 0; i < *sk; i++) {
            fscanf(data, "%s %s %d %lf %s", (*mas)[i].vard, (*mas)[i].pav, &(*mas)[i].num, &(*mas)[i].suma, (*mas)[i].val);
        }
    }
    fclose(data);
}

int main() {
    int sk;
    sask *mas = malloc(1 * sizeof(sask));
    read_file(&sk, &mas);

    // Print the read data for verification
    for (int i = 0; i < sk; i++) {
        printf("%s %s %d %.2f %s\n", mas[i].vard, mas[i].pav, mas[i].num, mas[i].suma, mas[i].val);
    }

    free(mas); // Don't forget to free the allocated memory

    return 0;
}
