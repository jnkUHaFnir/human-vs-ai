#include <stdio.h>
#include <stdlib.h>

typedef struct sask {
    char vard[256];
    char pav[256];
    int num;
    double suma;
    char val[5];
} sask;

void read_file(int *sk, sask **mas){
    FILE *data = fopen("data.txt", "r");

    if (data != NULL){
        fscanf(data, "%d", sk);
        printf("%d\n", *sk);

        *mas = (sask *)realloc(*mas, *sk * sizeof(sask));

        if (*mas == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            fclose(data);
            return;
        }

        for(int i = 0; i < *sk; i++){
            fscanf(data, "%s%s%d%lf%s", (*mas)[i].vard, (*mas)[i].pav, &(*mas)[i].num, &(*mas)[i].suma, (*mas)[i].val);
        }
    }
    fclose(data);
}

int main() {
    int sk;
    sask *mas = NULL;
    
    read_file(&sk, &mas);

    if (mas != NULL) {
        // Print the data read from the file for verification
        for (int i = 0; i < sk; i++) {
            printf("%s %s %d %lf %s\n", mas[i].vard, mas[i].pav, mas[i].num, mas[i].suma, mas[i].val);
        }
        
        // Free the dynamically allocated memory
        free(mas);
    }

    return 0;
}
